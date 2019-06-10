//
// Created by zygsi on 5/18/19.
//


#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../headers/functions.cpp"
#include "../headers/Human.h"
#include "../headers/main.h"
#include "../headers/studs.h"
#include "../headers/student.h"



    TEST_CASE( "Students are tested", "[student]" ) {
        Student test = Student("Vardas", "Pavarde");
        REQUIRE(  test.getLastName() == "Pavarde" );

        test.setExam(10);
        test.setMark(10);
        REQUIRE( test.calculateScore() == 10 );
    REQUIRE(  test.getLastName() == "Pavarda" );
    }

