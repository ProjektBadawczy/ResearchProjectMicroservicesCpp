#pragma once
#include<string>
#include<cpprest/http_client.h>

std::string charTToString(const utility::char_t* text);

utility::char_t* stringToCharT(const std::string text);

std::string sendGetRequest(std::string address);