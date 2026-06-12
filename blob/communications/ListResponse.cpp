#include "ListResponse.h"

ListResponse::ListResponse()
{
	
}

ListResponse::ListResponse(std::vector<ObjectKey> keys)
{
	keys_ = keys;
}

void ListResponse::AddKey(ObjectKey key)
{
	keys_.push_back(key);
}

std::vector<ObjectKey>* ListResponse::GetKeys()
{
	return &keys_;
}