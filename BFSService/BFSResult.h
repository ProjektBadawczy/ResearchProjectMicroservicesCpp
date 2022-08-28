#pragma once
#include<string>

class BFSResult
{
public:
	BFSResult(int* parents, bool success);
	BFSResult(int* parents, bool success, int parentsSize);
	~BFSResult();
	int* getParents();
	bool getSuccess();
	int getParentsSize();
private:
	int* parents;
	bool success;
	int parentsSize;
};