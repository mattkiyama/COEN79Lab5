//
//  mystring.cpp
//  Lab5
//
//  Created by Matthew Kiyama on 10/23/18.
//  Copyright © 2018 SCU. All rights reserved.
//

#include <stdio.h>
#include "mystring.h"

namespace coen79_lab5{
    // CONSTRUCTOR, COPY CONSTRUCTOR, and DESTRUCTOR
    string(const char str[ ] = "");
    string(char c);                     // NEW FUNCTION 1
    string(const string& source);
    ~string( );
    
    // MODIFICATION MEMBER FUNCTIONS
    void operator +=(const string& addend);
    void operator +=(const char addend[ ]);
    void operator +=(char addend);
    void reserve(size_t n);
    string& operator =(const string& source);
    void insert(const string& source, unsigned int position);
    void dlt(unsigned int position, unsigned int num);
    void replace(char c, unsigned int position);
    void replace(const string& source, unsigned int position);
    
    // CONSTANT MEMBER FUNCTIONS
    size_t length( ) const { return current_length; }
    char operator [ ](size_t position) const;
    int search(char c) const;
    int search(const string& substring) const;
    unsigned int count(char c) const;

}

