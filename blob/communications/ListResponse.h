#pragma once

#include <vector>
#include "../types/ObjectKey.h"

// The class responsible for returning a list returned from a blob
class ListResponse
{
public:
	// Constructors
	ListResponse();
	ListResponse(std::vector<ObjectKey> keys);
	
	// Setter (ish) Methods
	void AddKey(ObjectKey key);

	// Getters
	std::vector<ObjectKey>* GetKeys();

protected:
	std::vector<ObjectKey> keys_;
};