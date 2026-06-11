#include "DeleteResponse.h"

DeleteResponse::DeleteResponse()
{
	successful_ = false;
}

DeleteResponse::DeleteResponse(bool successful)
{
	successful_ = successful;
}

bool DeleteResponse::GetSuccessful()
{
	return successful_;
}