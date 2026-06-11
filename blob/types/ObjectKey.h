#pragma once

#include <stdexcept>
#include <string>

// Represents the key in a key value pair for a blob object.
// Can also be used to verify whether a given key is valid.
// Currently only supports string keys, since blobs generally
// represent file object stores.
class ObjectKey
{
public:
	// Constructor
	ObjectKey();
	ObjectKey(std::string key);
	
	// Getters
	std::string GetKey();

	// Validation
	virtual bool IsValid(std::string key);
protected:
	std::string key_;
};