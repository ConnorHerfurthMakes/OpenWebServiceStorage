#include "DeleteRequest.h"

DeleteRequest::DeleteRequest()
{

}

DeleteRequest::DeleteRequest(ObjectKey key)
{
	key_ = key;
}

ObjectKey DeleteRequest::GetKey()
{
	return key_;
}