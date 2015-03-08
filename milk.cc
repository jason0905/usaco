/*
ID: jason091
LANG: C++
TASK: milk
*/

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ifstream in ("milk.in");
    ofstream out ("milk.out");

    int total, farmNum, cost = 0;
    vector<pair<int, int> > milk;

    in >> total >> farmNum;
    for(int i = 0; i < farmNum; i++) {
        pair<int, int> x;
        in >> x.first >> x.second;
        milk.push_back(x);
    }

    sort(milk.begin(), milk.end());

    for(int i = 0; i < farmNum && total > 0; i++) {
        if(milk[i].second <= total) {
            cost += (milk[i].first * milk[i].second);
            total -= milk[i].second;
        }
        else {
            cost += (milk[i].first * total);
            total = 0;
        }
    }

    out << cost << endl;
}
