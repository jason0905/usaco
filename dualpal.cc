/*
ID: jason091
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string changeBase(int n, int b) {
    string x;

    for(int i = 0; n > 0; i++) {
        x += "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n % b];
        n /= b;
    }

    return x;
}

bool hasTen(int x) {
    string y;
    for(int i = 2, j = 0; i < 11; i++) {
        y = changeBase(x, i);
        for(int k = 0, l = y.size() - 1; ; k++, l--) {
            if(y[k] != y[l]) break;
            else if(k + 1 >= l) {
                j++;
                break;
            }
        }
        if(j == 2) return true;
    }
    return false;
}

int main() {
    ifstream in ("dualpal.in");
    ofstream out ("dualpal.out");

    int N, S, x = 0;

    in >> N >> S;

    for(int i = S + 1; x < N; i++) {
        if(hasTen(i)) {
            x++;
            out << i << endl;
        }
    }
}
