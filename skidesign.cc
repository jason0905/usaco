/*
ID: jason091
LANG: C++
TASK: skidesign
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in ("skidesign.in");
    ofstream out ("skidesign.out");

    int N, cost;
    vector<int> hills;

    in >> N;
    for(int i = 0; i < N; i++) {
        in >> cost;
        hills.push_back(cost);
    }

    cost = 10000000;

    for(int i = 0; i < 84; i++) {
        int temp_cost = 0;

        for(int j = 0; j < N; j++) {
            if(hills[j] < i) temp_cost += ((i - hills[j]) * (i - hills[j]));
            else if(hills[j] > i + 17) temp_cost += ((hills[j] - i - 17) * (hills[j] - i - 17));
        }

        if(temp_cost < cost) cost = temp_cost;
    }

    out << cost << endl;
}
