#include "SimpleBlob.h"

SimpleBlob::SimpleBlob(std::filesystem::path root_path)
{
	blob_root_path_ = root_path;
}

PutResponse SimpleBlob::Put(PutRequest request)
{
	if (!IsConnected())
		return PutResponse(false);

	std::filesystem::path object_path = GetObjectPath(request.GetKey());

	// TODO: Make it create directories recursively.
	std::ofstream object_out_stream(object_path);

	if (!object_out_stream.is_open())
	{
		return PutResponse(false);
	}

	if (!object_out_stream.write(
		request.GetBytes().data(), request.GetBytes().size()))
	{
		return PutResponse(false);
	}

	object_out_stream.close();

	return PutResponse(true);
}

GetResponse SimpleBlob::Get(GetRequest request)
{
	if (!IsConnected())
	{
		return GetResponse(false);
	}

	std::filesystem::path object_path = GetObjectPath(request.GetKey());

	std::ifstream object_in_stream(object_path);

	if (!object_in_stream.is_open())
	{
		return GetResponse(false);
	}

	std::streamsize size = object_in_stream.tellg();
	object_in_stream.seekg(0, std::ios::beg);

	// Initialize a false response and initialize the buffer
	GetResponse output = GetResponse(false, size);

	if (!object_in_stream.read(output.GetBufferData(), size))
	{
		return GetResponse(false);
	}

	return output;
}

DeleteResponse SimpleBlob::Delete(DeleteRequest request)
{
	if (!IsConnected())
	{
		return DeleteResponse(false);
	}

	std::filesystem::path object_path = GetObjectPath(request.GetKey());

	return DeleteResponse(std::filesystem::remove(object_path));
}

ListResponse SimpleBlob::List(ListRequest request)
{
	ListResponse output(true);

	for(const std::filesystem::path& entry : 
		std::filesystem::recursive_directory_iterator(blob_root_path_))
	{
		output.AddKey(ObjectKey(entry.string()));
	}

	return output;
}

bool SimpleBlob::Connect()
{
	return IsConnected(); // Since this connects if we have access to
						  // the directory, Connect and IsConnected are
						  // functionally the same.
}

bool SimpleBlob::IsConnected()
{
	return List(ListRequest()).GetSuccessful();
}

void SimpleBlob::Disconnect()
{
	// Does nothing, you can't really disconnect from a directory.
}

std::vector<std::string> SimpleBlob::Split(ObjectKey key, char delimiter)
{
	// Shamelessly stolen from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	std::vector<std::string> result;
	std::stringstream ss(key.GetKey());
	std::string item;

	while (getline(ss, item, delimiter)) {
		result.push_back(item);
	}

	return result;
}

std::filesystem::path SimpleBlob::GetObjectPath(ObjectKey key)
{
	std::filesystem::path output = blob_root_path_;
	for (const std::string& component : Split(key.GetKey(), '/'))
	{
		output /= component;
	}

	return output;
}