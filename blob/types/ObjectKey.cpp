#include "ObjectKey.h"

ObjectKey::ObjectKey()
{
	// We set it to some random thing because it needs to be non-empty
	// to be valid.
	key_ = "A";
}

ObjectKey::ObjectKey(std::string key)
{
	if (!IsValid(key))
	{
		throw std::invalid_argument("Key is not valid for object.");
	}

	key_ = key;
}

bool ObjectKey::IsValid(std::string key)
{
	// Since this is a base class, we allow any string
	return !key.empty();
}

std::string ObjectKey::GetKey()
{
	return key_;
}