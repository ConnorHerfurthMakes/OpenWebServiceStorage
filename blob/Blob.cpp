#include "Blob.h"

Blob::Blob()
{

}

PutResponse Blob::Put(PutRequest request)
{
	// Since this blob stores no data, it just fails
	return PutResponse(false);
}

GetResponse Blob::Get(GetRequest request)
{
	// Since this blob stores no data, it just fails
	return GetResponse(false);
}

DeleteResponse Blob::Delete(DeleteRequest request)
{
	// Since we store no data, it's not possible to delete it
	return DeleteResponse(false);
}

ListResponse Blob::List(ListRequest request)
{
	// Unlike the others this one actually returns something
	// Kind of, anyway.
	return ListResponse();
}


bool Blob::Connect()
{
	return false;
}

bool Blob::IsConnected()
{
	return false;
}

void Blob::Disconnect()
{

}