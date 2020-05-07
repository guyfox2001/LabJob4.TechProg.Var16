#pragma once
#define BASE_WORDS 125723
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Str_Array
{
	string OurStr;
};


void init_arr(Str_Array* init);
void rand_string(string Randomize);
string rand_string();