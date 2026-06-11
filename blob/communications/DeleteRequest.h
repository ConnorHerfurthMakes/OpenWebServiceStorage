#pragma once

#include "../types/ObjectKey.h"

// The class detailing a request to delete an object
// from the blob.
class DeleteRequest
{
public:
	// Constructors
	DeleteRequest();
	DeleteRequest(ObjectKey key);

	// Getters
	ObjectKey GetKey();

protected:
	ObjectKey key_;
};