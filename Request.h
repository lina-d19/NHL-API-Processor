/*
Author: Lina Dbagh
This file is the header file for the Request class.
Date: Jan 31, 2023
*/

#ifndef ASSIGNMENT1_REQUEST_H
#define ASSIGNMENT1_REQUEST_H

#include <iostream>
#include <string>
#include <curl/curl.h>

class Request {
private:
    std::string m_url;
    std::string m_response;
    static size_t writeCallBack(char* buf, size_t size, size_t nmemb, void* userp);

public:
    Request(std::string url);
    ~Request();
    bool execute();
    std::string result();

};
#endif //ASSIGNMENT1_REQUEST_H
