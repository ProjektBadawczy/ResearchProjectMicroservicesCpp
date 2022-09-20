#include "BFSRequest.h"
#include<string>
using namespace std;

BFSRequest::BFSRequest(Graph* graph, int source, int destination)
{
	this->graph = graph->clone();
	this->source = source;
	this->destination = destination;
}

BFSRequest::BFSRequest(string text)
{
	string graphName = "graph: ";
	string sourceName = "source: ";
	string destinationName = "destination: ";
	size_t pos = 0;
	size_t nextStopPos = 0;
	pos = text.find(graphName, pos);
	nextStopPos = text.find(sourceName, pos);
	this->graph = new Graph(text.substr(pos + graphName.length(), nextStopPos - (pos + graphName.length())));
	pos = text.find(sourceName, pos);
	nextStopPos = text.find(",", pos);
	this->source = stoi(text.substr(pos + sourceName.length(), nextStopPos - (pos + sourceName.length())));
	pos = text.find(destinationName, pos);
	nextStopPos = text.find("}", pos);
	this->destination = stoi(text.substr(pos + destinationName.length(), nextStopPos - (pos + sourceName.length())));
}

BFSRequest::~BFSRequest()
{
	delete this->graph;
}

Graph* BFSRequest::getGraph()
{
	return this->graph;
}

int BFSRequest::getSource()
{
	return this->source;
}

int BFSRequest::getDestination()
{
	return this->destination;
}

string BFSRequest::toString()
{
	string ret = "";
	ret += "{";
	ret += "graph: ";
	ret += this->graph->toString();
	ret += ",";
	ret += "source: ";
	ret += to_string(this->source);
	ret += ",";
	ret += "destination: ";
	ret += to_string(this->destination);
	ret += "}";
	return ret;
}