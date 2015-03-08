/*
ID: jason091
LANG: C++
TASK: barn1
*/

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool moreThan (int i, int j) { return (i > j); }

int main() {
    ifstream in ("barn1.in");
    ofstream out ("barn1.out");

    int boardNum, stallNum, cowNum, covered, temp;
    vector<int> cows, empty;

    in >> boardNum >> stallNum >> cowNum;

    for(int i = 0; i < cowNum; i++) {
        in >> temp;
        cows.push_back(temp);
    }

    sort(cows.begin(), cows.end());

    covered = cows[cowNum - 1] - cows[0] + 1;

    for(int i = 0; i < cowNum - 1; i++)
        empty.push_back(cows[i + 1] - cows[i]);

    for(int i = 0; i < boardNum - 1; i++) {
        sort(empty.begin(), empty.end(), moreThan);
        if(empty[0] > 0) covered -= (empty[0] - 1);
        empty[0] = 0;
    }

    out << covered << endl;
}
