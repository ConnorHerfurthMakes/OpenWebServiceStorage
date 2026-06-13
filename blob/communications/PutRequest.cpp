#include "PutRequest.h"

PutRequest::PutRequest()
{
	
}

PutRequest::PutRequest(ObjectKey key)
{
	key_ = key;
}

PutRequest::PutRequest(ObjectKey key, std::span<const char> bytes)
{
	key_ = key;
	bytes_ = bytes;
}

ObjectKey PutRequest::GetKey()
{
	return key_;
}

std::span<const char> PutRequest::GetBytes()
{
	return bytes_;
}