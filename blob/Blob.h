#pragma once

#include <vector>
#include "communications/PutRequest.h"
#include "communications/PutResponse.h"
#include "communications/GetRequest.h"
#include "communications/GetResponse.h"
#include "communications/DeleteRequest.h";
#include "communications/DeleteResponse.h"
#include "communications/ListRequest.h"
#include "communications/ListResponse.h"

// A Blob represents a collection of objects and the access patterns that
// enable it to store objects.
class Blob
{
public:
	// Constructor
	Blob();

	// Put Methods
	virtual PutResponse Put(PutRequest request);

	// Get Methods
	virtual GetResponse Get(GetRequest request);

	// Delete Methods
	virtual DeleteResponse Delete(DeleteRequest request);

	// List Methods
	virtual ListResponse List(ListRequest request);

	// Connection Methods
	// Although not all blobs have a literal connection,
	// this also serves as a way of verifying if they're ready
	// Returns true if connection succeeded
	virtual bool Connect();
	// Returns whether the blob is connected (i.e. able to read
	// and write)
	virtual bool IsConnected();
	// Disconnects the blob.
	virtual void Disconnect();
};