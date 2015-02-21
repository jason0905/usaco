/*
ID: jason091
LANG: C++
TASK: milk2
 */

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");

    int N, milk2 = 0, idle2 = 0, count = 1;
    pair<int, int> times[500], milk[500], idle[499];

    idle[0].first = 1000000;
    idle[0].second = 0;

    fin >> N;

    for(int i = 0; i < N; i++) {
        fin >> times[i].first >> times[i].second;
        milk[i].second = times[i].second;
        milk[i].first = times[i].first;
        if(times[i].first < idle[0].first) idle[0].first = times[i].first;
        if(times[i].second > idle[0].second) idle[0].second = times[i].second;
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

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < count; j++) {
            if(times[i].first > idle[j].first && times[i].second < idle[j].first) {
                idle[j].second = times[i].first;
                idle[j+1].first = times[i].second;
                idle[j+1].second = idle[j].second;
                count++;
            }
            else if(times[i].first == idle[j].first && times[i].second == idle[j].second) {
                for(int k = j; k < count; k++) {
                    if((k + 1) < count) {
                        idle[k].first = idle[k+1].first;
                        idle[k].second = idle[k+1].second;
                    }
                    else {
                        idle[k].first = 0;
                        idle[k].second = 0;
                    }
                }
            }
            else if(times[i].first <= idle[j].second && times[i].first > idle[j].first) idle[j].second = times[i].first;
            else if(times[i].second < idle[j].second && times[i].second >= idle[j].first) idle[j].first = times[i].second;
        }
    }

    for(int i = 0; i < count; i++) {
        if((idle[i].second - idle[i].first) > idle2) idle2 = idle[i].second - idle[i].first;
    }

    fout << milk2 << " " << idle2 << endl;
}
