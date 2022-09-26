#include "BFSRequest.h"
#include <string>
#include <cpprest/http_msg.h>

using namespace std;
using namespace utility;
using namespace utility::conversions;

BFSRequest::BFSRequest(Graph* graph, int source, int destination)
{
	this->graph = graph->clone();
	this->source = source;
	this->destination = destination;
}

BFSRequest::BFSRequest(string_t text)
{
	string_t graphName = U("graph: ");
	string_t sourceName = U("source: ");
	string_t destinationName = U("destination: ");
	size_t pos = 0;
	size_t nextStopPos = 0;
	pos = text.find(graphName, pos);
	nextStopPos = text.find(sourceName, pos);
	this->graph = new Graph(text.substr(pos + graphName.length(), nextStopPos - (pos + graphName.length())));
	pos = text.find(sourceName, pos);
	nextStopPos = text.find(U(","), pos);
	this->source = stoi(text.substr(pos + sourceName.length(), nextStopPos - (pos + sourceName.length())));
	pos = text.find(destinationName, pos);
	nextStopPos = text.find(U("}"), pos);
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

string_t BFSRequest::toString()
{
	string_t ret = U("");
	ret += U("{");
	ret += U("graph: ");
	ret += this->graph->toString();
	ret += U(",");
	ret += U("source: ");
	ret += to_string_t(to_string(this->source));
	ret += U(",");
	ret += U("destination: ");
	ret += to_string_t(to_string(this->destination));
	ret += U("}");
	return ret;
}