#pragma once

#include "../types/ObjectKey.h"

// The class that holds the data regarding the response to a Put 
// in a blob.
class PutResponse
{
public:
	// Constructors
	PutResponse();
	PutResponse(bool successful);

	// Getters
	bool GetSuccessful();
protected:
	bool successful_;
};