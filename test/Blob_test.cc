#include <gtest/gtest.h>

#include "../blob/Blob.h"
#include "../blob/communications/PutRequest.h"
#include "../blob/communications/GetRequest.h"
#include "../blob/communications/DeleteRequest.h"
#include "../blob/communications/ListRequest.h"
#include "../blob/communications/PutResponse.h"
#include "../blob/communications/GetResponse.h"
#include "../blob/communications/DeleteResponse.h"
#include "../blob/communications/ListResponse.h"
#include "../blob/types/ObjectKey.h"

TEST(BlobTest, BlobPut)
{
	Blob blob = Blob();

	PutResponse response = blob.Put(PutRequest(ObjectKey("TestKey")));
	EXPECT_FALSE(response.GetSuccessful());
}

TEST(BlobTest, BlobGet)
{
	Blob blob = Blob();

	GetResponse response = blob.Get(GetRequest(ObjectKey("TestKey")));
	EXPECT_FALSE(response.GetSuccessful());
}

TEST(BlobTest, BlobDelete)
{
	Blob blob = Blob();

	DeleteResponse response = blob.Delete(DeleteRequest(ObjectKey("TestKey")));
	EXPECT_FALSE(response.GetSuccessful());
}

TEST(BlobTest, BlobList)
{
	Blob blob = Blob();

	ListResponse response = blob.List(ListRequest());
	EXPECT_EQ((int)response.GetKeys()->size(), 0);
}