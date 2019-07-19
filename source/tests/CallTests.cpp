// Copyright 2019 Emil W

#include "source/HttpClient.h"
#include "catch.hpp"
#include <string>

TEST_CASE("Cal tests", "GET") {
    HttpClient* httpClient;
    string statusCode;

    SECTION("GET") {
        SECTION(" With full URL") {
            httpClient = new HttpClient();
            statusCode = httpClient->RunRequest("http://httpbin.org/get", "GET")
                                        .GetHttpStatusCode();
        }
        SECTION(" with short form") {
            httpClient = new HttpClient();
            statusCode = httpClient->RunRequest("httpbin.org/get", "GET")
                                        .GetHttpStatusCode();
        }
        SECTION(" without trailing /") {
            httpClient = new HttpClient();
            statusCode = httpClient->RunRequest("www.example.com", "GET")
                                        .GetHttpStatusCode();
        }
        CHECK(statusCode == "200");
    }
}
