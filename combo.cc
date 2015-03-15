/*
ID: jason091
LANG: C++
TASK: combo
*/

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream in ("combo.in");
    ofstream out ("combo.out");

    int N, farmer[3], master[3];
    vector< vector<int> > combos;
    vector<int> combo;

    in >> N;

    for(int i = 0; i < 3; i++) {
        in >> farmer[i];
        combo.push_back(i);
    }

    for(int i = 0; i < 3; i++)
        in >> master[i];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if((((i - farmer[0] < 3) && (farmer[0] - i < 3)) || 
                        ((i - farmer[0] > N - 3) || (i - farmer[0] < 3 - N))) &&
                        (((j - farmer[1] < 3) && (farmer[1] - j < 3)) ||
                        ((j - farmer[1] > N - 3) || (j - farmer[1] < 3 - N))) &&
                        (((k - farmer[2] < 3) && (farmer[2] - k < 3)) ||
                        ((k - farmer[2] > N - 3) || (k - farmer[2] < 3 - N)))) {
                    combo[0] = i;
                    combo[1] = j;
                    combo[2] = k;
                    combos.push_back(combo);
                }
                else if((((i - master[0] < 3) && (master[0] - i < 3)) || 
                        ((i - master[0] > N - 3) || (i - master[0] < 3 - N))) &&
                        (((j - master[1] < 3) && (master[1] - j < 3)) ||
                        ((j - master[1] > N - 3) || (j - master[1] < 3 - N))) &&
                        (((k - master[2] < 3) && (master[2] - k < 3)) ||
                        ((k - master[2] > N - 3) || (k - master[2] < 3 - N)))) {
                    combo[0] = i;
                    combo[1] = j;
                    combo[2] = k;
                    combos.push_back(combo);
                }
            }
        }
    }

    out << combos.size() << endl;
}
