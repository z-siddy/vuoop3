//
// Created by zygsi on 5/18/19.
//


#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>


std::string testAWord(std::string x){
    return x + " is a word!";
}


    TEST_CASE( "Words are tested", "[word]" ) {
        REQUIRE( testAWord("Car") == "Car is a word!" );
        REQUIRE( testAWord("House") == "Horse is a word!" );
    }

