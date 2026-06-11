#pragma once

#include "../types/ObjectKey.h"

// The class that handles the information for a get response
// from a blob.
class GetResponse
{
public:
	// Constructors
	GetResponse();
	GetResponse(bool successful);

	// Getters
	bool GetSuccessful();

protected:
	bool successful_;
};