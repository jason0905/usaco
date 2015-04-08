/*
ID: jason091
LANG: C++
TASK: ariprog
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    ifstream in ("ariprog.in");
    ofstream out ("ariprog.out");
    
    int length, bound, x, y;
    vector<pair<int, int> > progressions;
    vector<int> first, bisquares;

    in >> length >> bound;

    length--;

    for(int i = 0; i <= bound * bound * 2; i++)
        bisquares.push_back(0);

    for(int i = 0; i <= bound; i++) {
        for(int j = 0; j <= bound; j++)
            bisquares[i * i + j * j] = 1;
    }

    for(int i = 0; i <= bound; i++) {
        for(int j = i; j <= bound; j++) {
            x = i * i + j * j;
            if(find(first.begin(), first.end(), x) != first.end())
                continue;
            for(y = 1; y <= (2 * bound * bound - x) / length; y++) {
                for(int k = 1; k <= length; k++) {
                    if(bisquares[x + y * k] == 0)
                        break;
                    if(k == length) {
                        progressions.push_back(make_pair(y, x));
                        first.push_back(x);
                    }
                }
            }
        }
    }

    if(progressions.size() == 0)
        out << "NONE" << endl;

    sort(progressions.begin(), progressions.end());

    for(int i = 0; i < progressions.size(); i++)
        out << progressions[i].second << " " << progressions[i].first << endl;
}
