//
//  mystring.cpp
//  Lab5
//
//  Created by Matthew Kiyama on 10/23/18.
//  Copyright © 2018 SCU. All rights reserved.
//

#include <stdio.h>
#include "mystring.h"
#include <cstring>

namespace coen79_lab5{
    // CONSTRUCTOR, COPY CONSTRUCTOR, and DESTRUCTOR
    
    string::string(const char str[ ]){
        current_length = strlen(str);
        allocated = current_length+1;
        characters = new char[allocated];
        strncpy(characters, str, sizeof(*str));
    };
    
    string::string(char c){ // NEW FUNCTION 1
        current_length = 1;
        allocated = current_length+1;
        characters = new char[allocated];
        characters[0] = c;
        characters[1] = '\0';
    }
    
    string::string(const string& source){
        current_length = source.length();
        allocated = current_length+1;
        characters = new char[allocated];

        for(int i = 0; i < sizeof(source); i++){
            characters[i] = source[i];
        }
    }
    
    string::~string( ){
        delete []characters;
    }
    
    // MODIFICATION MEMBER FUNCTIONS
    void string::operator +=(const string& addend){
        
        current_length += sizeof(addend);
        allocated = current_length+1;
        for(int i = 0; i<sizeof(addend); i++){
            characters[current_length+i] = addend[i];
        }
    }
    
    void string::operator +=(const char addend[ ]){
        current_length += sizeof(*addend);
        allocated = current_length+1;
        strncat(characters, addend, sizeof(*addend));
    }
    
    void string::operator +=(char addend){
        current_length++;
        allocated++;
        characters[current_length+1] = addend;
    }
    
    void string::reserve(size_t n){
        if(allocated == n){
            return;
        }
        if(n < allocated){
            n = allocated;
        }
        *new characters = new [n];
        copy(characters, characters+allocated, n);
    }
    
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

