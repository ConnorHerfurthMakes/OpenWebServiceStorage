#pragma once

#include "../types/ObjectKey.h"

// The class for requesting an object from a blob
class GetRequest
{
public:
	// Constructors
	GetRequest();
	GetRequest(ObjectKey key);

	// Getters
	ObjectKey GetKey();

protected:
	ObjectKey key_;
};