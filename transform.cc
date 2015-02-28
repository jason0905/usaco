/*
ID: jason091
LANG: C++
TASK: transform
 */

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool equal(vector<string> &a, vector<string> &b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

void print(vector<string> &square) {
    for(int i = 0; i < square.size(); i++) 
        cerr << square[i] << endl;
}

void rotate(vector<string> orig, vector<string> & temp, int toRotate) {
    for(int k = 0; k < toRotate; k++) {
        for(int i = 0; i < orig.size(); i++) {
            for(int j = 0; j < orig.size(); j++)
                temp[i][j] = orig[orig.size() - j - 1][i];
        }
        for(int i = 0; i < orig.size(); i++) {
            for(int j = 0; j < orig.size(); j++) 
                orig[i][j] = temp[i][j];
        }
    }
}

void flip(vector<string> orig, vector<string> & temp) {
    for(int i = 0; i < orig.size(); i++) {
        for(int j = 0; j < orig.size(); j++) 
            temp[i][j] = orig[i][orig.size() - j - 1];
    }
}

int main() {

    int transformation = 0, N;
    vector<string> square;
    vector<string> result;
    vector<string> check, check2;

    ifstream fin ("transform.in");
    ofstream fout ("transform.out");
    fin >> N;

    for(int i = 0; i < N; i++) {
        string s;
        fin >> s;
        square.push_back(s);
        check.push_back(s);
        result.push_back(s);
        check2.push_back(s);
    }

    for(int i = 0; i < N; i++)
        fin >> result[i];

    rotate(square, check, 1);

    if(equal(check, result)) {
        fout << "1" << endl;
        exit(0);
    }

    rotate(square, check, 2);

    if(equal(check, result)) {
        fout << "2" << endl;
        exit(0);
    }

    rotate(square, check, 3);

    if(equal(check, result)) {
        fout << "3" << endl;
        exit(0);
    }

    flip(square, check);

    if(equal(check, result)) {
        fout << "4" << endl;
        exit(0);
    }

    flip(square, check2);
    rotate(check2, check, 1);

    if(equal(check, result)) {
        fout << "5" << endl;
        exit(0);
    }   

    flip(square, check2);
    rotate(check2, check, 2);

    if(equal(check, result)) {
        fout << "5" << endl;
        exit(0);
    }

    flip(square, check2);
    rotate(check2, check, 3);

    if(equal(check, result)) {
        fout << "5" << endl;
        exit(0);
    }

    if(equal(square, result)) {
        fout << "6" << endl;
        exit(0);
    }

    if(transformation == 0)
        fout << "7" << endl;
}
