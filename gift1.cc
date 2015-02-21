/*
ID: jason901
LANG: C++
TASK: gift1
 */

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");

    int a, k, numberOfPeople, money;

    vector<string>                  peopleNames;
    map<string, pair<int, int> >    money_map;
    string name, giver_name, recvr_name;

    fin >> numberOfPeople;

    for(int i = 0; i<numberOfPeople; i++) {
        fin >> name;
        peopleNames.push_back(name);
        money_map.insert(make_pair(name, make_pair(0, 0)));
    }

    for(int i=0; i<numberOfPeople; i++) {
        fin >> giver_name;
        fin >> money >> a;
        money_map[giver_name].first = money;
        for (int j = 0; j<a; j++) {
            fin >> recvr_name;
            money_map[recvr_name].second += (int(money_map[giver_name].first/a));
        }
        if(a != 0)
            money_map[giver_name].second -= (a * int(money_map[giver_name].first/a));
    }

    for(int i = 0; i<numberOfPeople; i++) {
        fout << peopleNames[i];
        fout << " ";
        fout << money_map[peopleNames[i]].second << endl;
    }
}
