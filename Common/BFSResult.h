#pragma once
#include <string>
#include <cpprest/http_msg.h>
using namespace utility;

class BFSResult
{
public:
	BFSResult(int* parents, bool success, int parentsSize);
	BFSResult(string_t text);
	~BFSResult();
	int* getParents();
	bool getSuccess();
	int getParentsSize();
	string_t toString();
private:
	int* parents;
	bool success;
	int parentsSize;
};