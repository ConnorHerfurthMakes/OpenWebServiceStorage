#pragma once

// The class for handling the response from the blob
// after deleting an object
class DeleteResponse
{
public:
	// Constructors
	DeleteResponse();
	DeleteResponse(bool successful);

	// Getters
	bool GetSuccessful();

protected:
	bool successful_;
};