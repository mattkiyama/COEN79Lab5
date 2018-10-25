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
    
    string& string::operator =(const string& source){
        
    }
    void string::insert(const string& source, unsigned int position){
        assert(position <=current_length);
        
        current_length += source.length();
        allocated = current_length+1;
        
        for(int i = 0; i<source.length(); i++){
            characters[current_length+1] = source[i];
        }
        
    }
    
    void string::dlt(unsigned int position, unsigned int num){
        assert(position+num <= current_length);
        
        current_length -= num;
        allocated = current_length+1;
        
        for(int i = position; i < num; i++){
            characters[i] = characters[i+1];
        }
    }
    
    void string::replace(char c, unsigned int position){
        assert(position < current_length);
        
        characters[current_length] = c;
    }
    void string::replace(const string& source, unsigned int position){
        assert(position+source.length() < current_length);
        
        current_length += source.length();
        allocated = current_length+1;
        
        for(int j = 0; j < source.length(); j++){
            for(int i = position; i < current_length; i++){
                characters[i] = source[j];
            }
        }
    }
    
    // CONSTANT MEMBER FUNCTIONS
    size_t string::length( ) const {
        return current_length;
    }
    
    char string::operator [ ](size_t position) const{
        assert(position < current_length);
        return characters[position];
    }
    
    int string::search(char c) const{
        for(int i = 0; i<current_length; i++){
            if(characters[i] == c){
                return i;
            }
        }
        return -1;
    }
    
    int string::search(const string& substring) const{
        std::string characters1 = characters;
        
        size_t found = characters1.find(substring);
        
        
    }
    
    unsigned int string::count(char c) const{
        
    }

}

