#include "stringrandom.h"

Str_Array RandArr[BASE_WORDS];
bool init_flag; 

void init_arr(Str_Array* init) {
	if (init_flag == true) return;
	ifstream input;
	ofstream output;
	input.open("words_base.txt", ios::in);
	if (input.is_open()) { cout << "Open file\n"; }
	else cerr << "not found\n";
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