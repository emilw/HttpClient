#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../URL.h"

TEST_CASE( "Create regular URL", "URLTests" ) {
    
    URL* urlObject;

    SECTION( "with http" ) {
        urlObject = new URL("http://testing.com");
        REQUIRE_FALSE(urlObject->IsSSL());
        CHECK(urlObject->GetPortNumber() == "80");
        CHECK(urlObject->GetProtocoll() == "http");
    }
    SECTION( "with https" ) {
        urlObject = new URL("https://testing.com");
        REQUIRE(urlObject->IsSSL());
        CHECK(urlObject->GetPortNumber() == "443");
        CHECK(urlObject->GetProtocoll() == "https");
    }
    
    CHECK(urlObject->GetHostName() == "testing.com");
}