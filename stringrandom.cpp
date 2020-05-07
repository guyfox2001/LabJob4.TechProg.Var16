#include "stringrandom.h"

Str_Array* RandArr;
bool init_flag; 

void init_arr(Str_Array* init) {
	if (init_flag == true) return;
	init = new Str_Array[BASE_WORDS];
	ifstream input;
	input.open("pldf-win.txt", ios::binary);
	for (int i = 0; i < BASE_WORDS; ++i) {
		input >> init[i].OurStr;
	}
	init_flag = true;
}

void rand_string(string Randomize) {
	init_arr(RandArr);
	Randomize = RandArr[rand() % BASE_WORDS].OurStr;
}
string rand_string() {
	init_arr(RandArr);
	return RandArr[rand() % BASE_WORDS].OurStr;
}