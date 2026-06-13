#include "ListResponse.h"

ListResponse::ListResponse()
{
	successful_ = false;
}

ListResponse::ListResponse(bool successful)
{
	successful_ = successful;
}

ListResponse::ListResponse(std::vector<ObjectKey> keys)
{
	successful_ = true; // If keys were returned, it was successful;
	keys_ = keys;
}

void ListResponse::AddKey(ObjectKey key)
{
	keys_.push_back(key);
}

void ListResponse::SetSuccessful(bool successful)
{
	successful_ = successful;
}

bool ListResponse::GetSuccessful()
{
	return successful_;
}

std::vector<ObjectKey>* ListResponse::GetKeys()
{
	return &keys_;
}