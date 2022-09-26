#pragma once
#include<string>
#include<cpprest/http_client.h>
#include<cpprest/json.h>

std::string charTToString(const utility::char_t* text);

utility::char_t* stringToCharT(const std::string text);

utility::string_t sendGetRequest(utility::string_t address);

utility::string_t sendPostRequest(utility::string_t address, web::json::value body);

std::string stringTToString(const utility::string_t text);
