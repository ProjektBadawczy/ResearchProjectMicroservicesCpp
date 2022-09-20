#pragma once
#include<string>

class BFSResult
{
public:
	BFSResult(int* parents, bool success, int parentsSize);
	BFSResult(std::string text);
	~BFSResult();
	int* getParents();
	bool getSuccess();
	int getParentsSize();
	std::string toString();
private:
	int* parents;
	bool success;
	int parentsSize;
};