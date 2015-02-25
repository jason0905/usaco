/*
ID: jason091
LANG: C++
TASK: milk2
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main() {

    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");

    int N, milk2 = 0, idle2 = 0, count = 0, max, min;
    pair<int, int> times[5000], milk[5000];

    fin >> N;

    min = 1000000;
    max = 0;

    for(int i = 0; i < N; i++) {
        fin >> times[i].first >> times[i].second;
        milk[i].second = times[i].second;
        milk[i].first = times[i].first;
        if(times[i].first < min) min = times[i].first;
        if(times[i].second > max) max = times[i].second;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(milk[j].first <= milk[i].second && milk[j].first >= milk[i].first && milk[i].second <= milk[j].second)
                milk[i].second = milk[j].second;
            if(milk[j].second >= milk[i].first && milk[j].second <= milk[i].second && milk[i].first >= milk[j].first)
                milk[i].first = milk[j].first;
        }
        if((milk[i].second - milk[i].first) > milk2) milk2 = milk[i].second - milk[i].first;
    }

    for(float i = min + 0.5; i <= max; i++) {
        bool cont = true;
        bool add = true;
        for(int j = 0; j < N && (cont == true); j++) {
            if(times[j].first <= i && times[j].second >= i) {
                if(count > idle2) idle2 = count;
                count = 0;
                cont = false;
                add = false;
            }
        }
        if(add == true) count++;
    }

    fout << milk2 << " " << idle2 << endl;
}
