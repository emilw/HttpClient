#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../URL.h"

TEST_CASE( "Create regular URL", "URLTests" ) {
    
    URL* urlObject;

    SECTION( "regulr http" ) {
        SECTION(" with full URL"){
            urlObject = new URL("http://testing.com");
        }
        SECTION(" with short form"){
            urlObject = new URL("testing.com");
        }
        REQUIRE_FALSE(urlObject->IsSSL());
        CHECK(urlObject->GetPortNumber() == "80");
        CHECK(urlObject->GetProtocoll() == "http");
    }
    SECTION( "with https" ) {
        SECTION(" with full URL"){
            urlObject = new URL("https://testing.com");
        }
        REQUIRE(urlObject->IsSSL());
        CHECK(urlObject->GetPortNumber() == "443");
        CHECK(urlObject->GetProtocoll() == "https");
    }

    SECTION( "with specified port" ) {
        
        urlObject = new URL("https://testing.com:8080");
        REQUIRE(urlObject->IsSSL());
        CHECK(urlObject->GetPortNumber() == "8080");
    }

    SECTION( "with sub folders(long port) " ) {
        
        urlObject = new URL("https://testing.com:8080/testfolder");
        REQUIRE(urlObject->IsSSL());
        CHECK(urlObject->GetPortNumber() == "8080");
        CHECK(urlObject->GetRelativePath() == "/testfolder");
    }

    SECTION( "with sub folders(short port) " ) {
        
        urlObject = new URL("https://testing.com:88/testfolder");
        REQUIRE(urlObject->IsSSL());
        CHECK(urlObject->GetPortNumber() == "88");
    }

    SECTION( "with query string parameters " ) {
        
        urlObject = new URL("https://testing.com:88/testfolder?testPar1=2344&testPar3=3345");
        REQUIRE(urlObject->IsSSL());
        CHECK(urlObject->GetPortNumber() == "88");
        CHECK(urlObject->GetQueryString() == "?testPar1=2344&testPar3=3345");
    }
    
    CHECK(urlObject->GetHostName() == "testing.com");
}