/*
ID: jason091
LANG: C++
TASK: milk3
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

void Camounts(pair<int, int> buckets, set<pair<int, int> > & cases, vector<int> & Cs, int & C, int & B, int & A) {
    int a, b, c;

    if(cases.find(buckets) != cases.end())
        return;

    cases.insert(buckets);

    if(buckets.first + buckets.second == C)
        Cs.push_back(buckets.second);

    c = buckets.second;
    b = buckets.first;
    a = C - c - b;

    if(A - a >= b)
        Camounts(make_pair(0, c), cases, Cs, C, B, A);
    else
        Camounts(make_pair(a + b - A, c), cases, Cs, C, B, A);

    if(B - b >= a)
        Camounts(make_pair(a + b, c), cases, Cs, C, B, A);
    else
        Camounts(make_pair(B, c), cases, Cs, C, B, A);

    if(A - a >= c)
        Camounts(make_pair(b, 0), cases, Cs, C, B, A);
    else
        Camounts(make_pair(b, a + c - A), cases, Cs, C, B, A);

    if(C - c >= a)
        Camounts(make_pair(b, a + c), cases, Cs, C, B, A);
    else
        Camounts(make_pair(b, C), cases, Cs, C, B, A);

    if(B - b >= c)
        Camounts(make_pair(b + c, 0), cases, Cs, C, B, A);
    else
        Camounts(make_pair(B, b + c - B), cases, Cs, C, B, A);

    if(C - c >= b)
        Camounts(make_pair(0, b + c), cases, Cs, C, B, A);
    else
        Camounts(make_pair(b + c - C, C), cases, Cs, C, B, A);
}

int main() {
    ifstream in ("milk3.in");
    ofstream out ("milk3.out");

    set<pair<int, int> > cases;
    vector<int> Cs;
    pair<int, int> buckets;
    int a, b, c;

    in >> a >> b >> c;
    
    buckets.first = 0;
    buckets.second = c;

    Camounts(buckets, cases, Cs, c, b, a);

    sort(Cs.begin(), Cs.end());

    for(int i = 0; i < Cs.size() - 1; i++)
        out << Cs[i] << " ";

    out << Cs[Cs.size() - 1] << endl;
}
