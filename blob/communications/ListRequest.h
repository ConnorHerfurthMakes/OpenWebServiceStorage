#pragma once

// The class for handling list requests to a blob
// Since a blob has all the necessary data, the base
// class is empty.  We abstract it anyway, since other
// information can be sent in (at least in theory)
class ListRequest
{
public:
	// Constructor
	ListRequest();
};