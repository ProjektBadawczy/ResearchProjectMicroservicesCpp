#pragma once
#include <string>
#define GRAPH_SERVICE_URL U("http://localhost:8090/api/")
#define BFS_SERVICE_URL U("http://localhost:8091/api/")

#ifndef linux
#define ADDRESS "127.0.0.1"
#else
#define ADDRESS getenv("INSIDE_DOCKER") ? "0.0.0.0" : "127.0.0.1"
#endif