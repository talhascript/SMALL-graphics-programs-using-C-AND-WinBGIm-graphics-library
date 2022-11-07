//? Exercise 3: C++ Strings
//? file: custom_string.cpp

//!----------------------------------------------------------------------------------------
//! This is the only file that you will need to modify in this exercise.
//! Also, you will submit only this file.
//! In this file will implement the class 'CustomString'.
//!----------------------------------------------------------------------------------------

// Programming Technique II
// Semester 1, 2021/2022

// Date: __ December 2021
// Section: _________
// Member 1's Name: _____________    Location: ____________ (i.e. where are you currently located)
// Member 2's Name: _____________    Location: ____________

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

#include <iostream>
#include <string>
using namespace std;

#include "custom_string.hpp"

//?----------------------------------------------------------------------------------------
//? The following methods are fully given: a constructor, getData() and setData()
//?----------------------------------------------------------------------------------------

CustomString::CustomString(const string &_data) : data(_data) {}
string CustomString::getData() const { return data; }
void CustomString::setData(const string &_data) { data = _data; }

//! Task 1: Complete the implementation of the following mutator methods:
//!        (a) pushFront()
//!        (b) pushBack()
//!        (c) pop()
//!        (d) popFront()
//!        (e) popBack()

void CustomString::pushFront(const string &s)
{
    data = data.insert(0,s);
}

void CustomString::pushBack(const string &s)
{
    
    data = data.insert(data.length(),s);
}

string CustomString::pop(int index, int count)
{
    string data1;
    data1 = data.substr(index,count);
    data.erase(index,count);
    return data1;
}

string CustomString::popFront(int count)
{   
    string data1;
    data1 = data.substr(0,count);
    data.erase(0,count);
    return data1;
}

string CustomString::popBack(int count)
{   
    string data1;
    data1 = data.substr(data.length()-count,count);
    data.erase(data.length()-count,count);
    return data1;
}

//! Task 2: Complete the implementation of the following overloaded operators:
//!        (a) operator !
//!        (b) operator *

CustomString CustomString::operator!() const
{   
    string rev = "";
    for(int i=data.length()-1; i>=0; i--){
        
        rev = rev + data[i];  
    }
    return CustomString(rev);
}

CustomString CustomString::operator*(int count) const
{   
    string repeat="";

    for(int i=0; i<count; i++){
        repeat = repeat + data;
    }

    return CustomString(repeat);
}

//! Task 3: Complete the implementation of the following conversion methods:
//!        (a) toDouble()
//!        (b) toUpper()

double CustomString::toDouble() const
{   
    double num;
    num = stod(data);
    return num;
}

CustomString CustomString::toUpper() const
{   string data1 = data;

    for(int i =0; i<data.length(); i++){
        data1[i] = toupper(data[i]);
    }
    
    
   
    return CustomString(string(data1));
}