#include "PutRequest.h"

PutRequest::PutRequest()
{
	
}

PutRequest::PutRequest(ObjectKey key)
{
	key_ = key;
}

ObjectKey PutRequest::GetKey()
{
	return key_;
}