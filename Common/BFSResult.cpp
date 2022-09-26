#include "BFSResult.h"
using namespace std;
using namespace utility::conversions;

BFSResult::BFSResult(int* parents, bool success, int parentsSize)
{
	this->parents = parents;
	this->success = success;
	this->parentsSize = parentsSize;
}
BFSResult::BFSResult(string_t text)
{
	string_t parentsSizeName = U("parentsSize: ");
	string_t parentsName = U("parents: ");
	string_t successName = U("success: ");
	size_t pos = 0;
	size_t nextStopPos = 0;
	pos = text.find(parentsSizeName, pos);
	nextStopPos = text.find(U(","), pos);
	this->parentsSize = stoi(text.substr(pos + parentsSizeName.length(), nextStopPos - (pos + parentsSizeName.length())));
	int* newParents = new int[this->parentsSize];
	pos = text.find(parentsName, pos);
	pos += parentsName.length() + 1;
	for (int i = 0; i < this->parentsSize; i++)
	{
		if (i < this->parentsSize - 1)
		{
			nextStopPos = text.find(U(","), pos);
		}
		else
		{
			nextStopPos = text.find(U("]"), pos);
		}
		newParents[i] = stoi(text.substr(pos, nextStopPos - pos));
		pos = nextStopPos + 1;
	}
	this->parents = newParents;
	pos = text.find(successName, pos);
	nextStopPos = text.find(U("}"), pos);
	this->success = stoi(text.substr(pos + successName.length(), nextStopPos - (pos + successName.length())));
}
BFSResult::~BFSResult()
{
	delete[] parents;
}
int* BFSResult::getParents()
{
	return parents;
}
bool BFSResult::getSuccess()
{
	return success;
}
int BFSResult::getParentsSize()
{
	return parentsSize;
}
string_t BFSResult::toString()
{
	string_t ret = U("");
	ret += U("{");
	ret += U("parentsSize: ");
	ret += to_string_t(to_string(this->parentsSize));
	ret += U(",");
	ret += U("parents: ");
	ret += U("[");
	for (int i = 0; i < this->parentsSize; i++)
	{
		ret += to_string_t(to_string(this->parents[i]));
		if (i < this->parentsSize - 1)
		{
			ret += U(",");
		}
	}
	ret += U("]");
	ret += U(",");
	ret += U("success: ");
	ret += to_string_t(to_string(this->success));
	ret += U("}");
	return ret;
}