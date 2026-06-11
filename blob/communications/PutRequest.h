#pragma once

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

	// Getters
	ObjectKey GetKey();
protected:
	ObjectKey key_;
};