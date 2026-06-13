#include "GetResponse.h"

GetResponse::GetResponse()
{
	successful_ = false;
}

GetResponse::GetResponse(bool successful)
{
	successful_ = successful;
}

GetResponse::GetResponse(bool successful, size_t buffer_size)
{
	successful_ = successful;
	buffer_ = std::vector<char>(buffer_size);
}

bool GetResponse::GetSuccessful()
{
	return successful_;
}

char* GetResponse::GetBufferData()
{
	return buffer_.data();
}

std::vector<char>* GetResponse::GetBuffer()
{
	return &buffer_;
}

void GetResponse::SetSuccessful(bool successful)
{
	successful_ = successful;
}