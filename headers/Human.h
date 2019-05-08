//
// Created by zygsi on 5/8/2019.
//
#include "main.h"
#ifndef VUOPP2_HUMAN_H
#define VUOPP2_HUMAN_H

class Human {
private:
    std::string firstName_;
    std::string lastName_;
public:
    inline std::string getName() const { return firstName_; }
    inline std::string getLastName() const { return lastName_; }
    void setName(string text) { firstName_ = text; };
    void setLastname(string text) { lastName_ = text; };

    virtual void getTitle() = 0;

    Human() {};
    Human(string name, string lname): firstName_(std::move(name)), lastName_(std::move(lname)) {};
};

#endif //VUOPP2_HUMAN_H
