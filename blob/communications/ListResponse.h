#pragma once

#include <vector>
#include "../types/ObjectKey.h"

// The class responsible for returning a list returned from a blob
class ListResponse
{
public:
	// Constructors
	ListResponse();
	ListResponse(bool successful);
	ListResponse(std::vector<ObjectKey> keys);
	
	// Setter (ish) Methods
	void AddKey(ObjectKey key);
	void SetSuccessful(bool successful);

	// Getters
	bool GetSuccessful();
	std::vector<ObjectKey>* GetKeys();

protected:
	bool successful_;
	// TODO: Profile performance of returning the response with the
	// vector vs. passing in response reference and adding to the ref.
	std::vector<ObjectKey> keys_;
};