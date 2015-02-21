/*
ID: jason091
LANG: C++
TASK: friday
 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main() {

	ifstream fin ("friday.in");
	ofstream fout ("friday.out");

	int N, day, days[7], a;

	fin >> N;

	day = 0;

	for(int i = 0; i < 7; i++) days[i] = 0;

    days[day]++;

	for(int i = 0; i < N; i++) {
		for(a = 1; a < 13; a++) {
			if(a == 4 || a == 6 || a == 9 || a == 11) day += 2;
			else if(a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12) day += 3;
			else if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 100)) day++;
            if(a != 12 || (i + 1) != N) {
                day %= 7;
                days[day]++;
            }
        }
	}

	for(int i = 0; i < 7; i++) {
        fout << days[i];
        if(i != 6) fout << " ";
    }

	fout << endl;
}
