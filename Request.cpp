/*
Author: Lina Dbagh
This class makes a GET request to the NHL API in order to pull the necessary data pertaining to the team names and scores.
Date: Jan 31, 2023
*/

#include "Request.h"
using namespace std;


// Request constructor takes in a string object as a parameter, containing the URL to fetch. It initializes this URL by assigning it to the member url variable, m_url.

Request::Request(string url) {
    m_url = url;
}

// Destructor is empty as there is no need to deallocate memory as the class only uses stack-allocated variables 
Request::~Request() {}

/*
Function Name: writeCallBack
Description: writeCallBack is a callback function that is used to handle the HTTP request response with the curl library.
Parameters: buf is a pointer to the buffer containing the data recieved from the HTTP request, size is the size of each element in the buffer represented in bytes, and nmemb is the number of elements in the buffer.
Return: the size of the data processed 
*/
size_t Request::writeCallBack(char *buf, size_t size, size_t nmemb, void *userp) {
    Request* request = static_cast<Request*>(userp); // cast userp pointer to a pointer to the Request object so we can access Request member variables, namely m_response
    request->m_response.append((char*)buf, size*nmemb); // append the data stored in buf to the m_response string
    return size*nmemb; 
}

/*
Function Name: execute
Description: execute is a function that uses the curl library to make an HTTP request to the requested URL.
Parameters: none
Return: true if the request is successful, false if the request fails
*/ 
bool Request::execute() {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, m_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            return false;
        }
        else {
            return true;
        }
    }
    return false;
}

/*
Function name: result
Description: the result function returns the string-representation of the JSON data stored in the member variable m_response
Parameters: none
Return: the pulled JSON data as a string
*/
string Request::result() {
    return m_response;
}
