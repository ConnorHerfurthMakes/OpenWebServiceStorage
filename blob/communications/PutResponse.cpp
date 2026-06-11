#include "PutResponse.h"

PutResponse::PutResponse()
{
	successful_ = false;
}

PutResponse::PutResponse(bool successful)
{
	successful_ = successful;
}

bool PutResponse::GetSuccessful()
{
	return successful_;
}