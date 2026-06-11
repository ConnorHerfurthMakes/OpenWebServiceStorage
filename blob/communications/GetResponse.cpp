#include "GetResponse.h"

GetResponse::GetResponse()
{
	successful_ = false;
}

GetResponse::GetResponse(bool successful)
{
	successful_ = successful;
}

bool GetResponse::GetSuccessful()
{
	return successful_;
}