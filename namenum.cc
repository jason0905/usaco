/*
ID: jason091
LANG: C++
TASK: namenum
 */

#include <fstream>

using namespace std;

int main() {

    ifstream in ("namenum.in");
    ifstream txt ("dict.txt");
    ofstream out ("namenum.out");

    int nsolutions = 0; 
    string word, num, word2;
    char map[256];

    map['A'] = map['B'] = map['C'] = '2';
    map['D'] = map['E'] = map['F'] = '3';
    map['G'] = map['H'] = map['I'] = '4';
    map['J'] = map['K'] = map['L'] = '5';
    map['M'] = map['N'] = map['O'] = '6';
    map['P'] = map['R'] = map['S'] = '7';
    map['T'] = map['U'] = map['V'] = '8';
    map['W'] = map['X'] = map['Y'] = '9';

    in >> num;
    word2 = num;

    while(txt) {
        txt >> word;
        if(num.size() != word.size()) continue;
        for(int i = 0; i < word.size(); i++) {
            word2[i] = map[word[i]];
        }
        if(num == word2) {
            out << word << endl;
            ++nsolutions;
        }
    }

    if(nsolutions == 0) out << "NONE" << endl;
}
