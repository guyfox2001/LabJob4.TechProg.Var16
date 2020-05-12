#include "stringrandom.h"

Str_Array RandArr[BASE_WORDS];
bool init_flag; 

void init_arr(Str_Array* init) {
	if (init_flag == true) return;
	ifstream input;
	ofstream output;
	bool complete_flag5 = false;
	bool complete_flag10 = false;
	bool complete_flag25 = false;
	bool complete_flag50 = false;
	bool complete_flag75 = false;
	bool complete_flag100 = false;
	input.open("words_base.txt", ios::in);
	if (input.is_open()) { cout << "Open file words_base.txt \n"; cout << "Start initialize the dictionary \n"; }
	else cerr << "not found\n";
	for (int i = 0; i < BASE_WORDS; ++i) {
		input >> init[i].OurStr;
		if (i / (BASE_WORDS / 100) == 5 && complete_flag5 == false) {
			cout << "5% complete\n"; complete_flag5 = true;
		}
		if (i / (BASE_WORDS / 100) == 10 && complete_flag10 == false) { cout << "10% complete\n"; complete_flag10 = true; }
		if (i / (BASE_WORDS / 100) == 25 && complete_flag25 == false) {cout << "25% complete\n"; complete_flag25 = true;}
		if (i / (BASE_WORDS / 100) == 50 && complete_flag50 == false) { cout << "50% complete\n"; complete_flag50 = true; }
		if (i / (BASE_WORDS / 100) == 75 && complete_flag75 == false) { cout << "75% complete\n"; complete_flag75 = true; }
		if (i / (BASE_WORDS / 100) == 100 && complete_flag100 == false) { cout << "100% complete\n"; complete_flag100 = true; }
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