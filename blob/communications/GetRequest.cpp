#include "GetRequest.h"

GetRequest::GetRequest()
{
	
}

GetRequest::GetRequest(ObjectKey key)
{
	key_ = key;
}

ObjectKey GetRequest::GetKey()
{
	return key_;
}