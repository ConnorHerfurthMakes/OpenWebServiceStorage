#pragma once

#include <span>

#include "../types/ObjectKey.h"

// The class that holds the data for adding an object.
// Since this is a base class, it technically only needs a key,
// as it is valid for an object to exist without any data.
class PutRequest
{
public:
	// Constructors
	PutRequest();
	PutRequest(ObjectKey key);
	PutRequest(ObjectKey key, std::span<const char> bytes);

	// Getters
	ObjectKey GetKey();
	std::span<const char> GetBytes();

protected:
	ObjectKey key_;
	// We use a span so that we don't need to actually handle
	// memory when making a request.
	std::span<const char> bytes_;
};