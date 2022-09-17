#include "utils.h"

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
    utility::char_t* ret = new utility::char_t[text.length()];
    for(i = 0; i<text.length(); i++)
    {
        ret[i] = (utility::char_t)(text[i]);
    }
    return ret;
}

std::string sendGetRequest(std::string address)
{
    string ret = "";
    http_client client(stringToCharT(address));
    client.request(methods::GET).then([=](http_response response)
                                      {
                                          if (response.status_code() == status_codes::OK)
                                          {
                                              auto body = response.extract_string().get();
                                              ret = (body);
                                          }
                                      });
    return ret;
}