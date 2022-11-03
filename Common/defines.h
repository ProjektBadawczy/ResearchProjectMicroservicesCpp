#pragma once
#include <string>
#define GRAPH_SERVICE_URL U("http://graphservice:8090/api/")
#define BFS_SERVICE_URL U("http://bfsservice:8091/api/")
#define EDMONDSKARP_SERVICE_URL U("http://edmondskarpservice:8092/api/")
#define PUSHRELABEL_SERVICE_URL U("http://pushrelabelservice:8093/api/")
//#define GRAPH_SERVICE_URL U("http://localhost:8090/api/")
//#define BFS_SERVICE_URL U("http://localhost:8091/api/")
//#define EDMONDSKARP_SERVICE_URL U("http://localhost:8092/api/")
//#define PUSHRELABEL_SERVICE_URL U("http://localhost:8093/api/")

#ifndef linux
#define ADDRESS "127.0.0.1"
#else
#define ADDRESS getenv("INSIDE_DOCKER") ? "0.0.0.0" : "127.0.0.1"
#endif