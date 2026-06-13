#pragma once

#include <filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "Blob.h"

// The simple blob is the simplest implementation of a blob.
// It's designed mainly around being lightweight.
// It works by being given a directory, and then simply reading
// or writing files from that directory.
class SimpleBlob : Blob
{
public:
	// Constructor
	SimpleBlob(std::filesystem::path root_path);

	// Put Methods
	PutResponse Put(PutRequest request) override;

	// Get Methods
	GetResponse Get(GetRequest request) override;

	// Delete Methods
	DeleteResponse Delete(DeleteRequest request) override;

	// List Methods
	ListResponse List(ListRequest request) override;

	// Connection Methods
	bool Connect() override;
	bool IsConnected() override;
	void Disconnect() override;

private:
	// Splits a key into its components
	std::vector<std::string> Split(ObjectKey key, char delimiter);
	// Returns the path to the object for a given key (if it exists)
	std::filesystem::path GetObjectPath(ObjectKey key);

	// TODO: Make writing thread safe.  For now it's single threaded
	// so it's fine.
	std::filesystem::path blob_root_path_;
};