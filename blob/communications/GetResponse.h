#pragma once

#include <vector>

#include "../types/ObjectKey.h"

// The class that handles the information for a get response
// from a blob.
class GetResponse
{
public:
	// Constructors
	GetResponse();
	GetResponse(bool successful);
	GetResponse(bool successful, size_t buffer_size);

	// Getters
	bool GetSuccessful();
	char* GetBufferData();
	std::vector<char>* GetBuffer();

	// Setters
	void SetSuccessful(bool successful);

protected:
	bool successful_;
	std::vector<char> buffer_;
};