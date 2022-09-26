#include "utils.h"
using namespace web;
using namespace web::http;
using namespace web::http::client;

std::string charTToString(const utility::char_t* text)
{
    std::string ret = "";
    int i = 0;
    while(text[i] != '\0')
    {
        ret.push_back(text[i]);
        i++;
    }
    return ret;
}

utility::char_t* stringToCharT(const std::string text)
{
    utility::char_t* ret = new utility::char_t[text.length()+1];
    for(int i = 0; i<text.length(); i++)
    {
        ret[i] = (utility::char_t)(text[i]);
    }
    return ret;
}

utility::string_t sendGetRequest(utility::string_t address)
{
    http_client client(address.c_str());
    return client.request(methods::GET).then([=](http_response response)
        {
            if (response.status_code() == status_codes::OK)
            {
                auto body = response.extract_string().get();
                return body;
            }
        }).get();
}

utility::string_t sendPostRequest(utility::string_t address, json::value body)
{
    http_client client(address);
    return client.request(methods::POST, L"", body).then([=](http_response response)
        {
            if (response.status_code() == status_codes::OK)
            {
                auto body = response.extract_string().get();
                return body;
            }
        }).get();
}

std::string stringTToString(const utility::string_t text)
{
    std::string ret = "";
    for (int i = 0; i < text.length(); i++)
    {
        ret += text[i];
    }
    return ret;
}