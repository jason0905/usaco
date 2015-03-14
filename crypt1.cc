/*
ID: jason091
LANG: C++
TASK: crypt1
 */

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

bool allIn(int x, int N, vector<int> digits) {
    for(int i = 0; i < N; i++) {
        if(find(digits.begin(), digits.end(), x % 10) == digits.end())
            return false;
        else
            x /= 10;
    }
    return true;
}

int main() {
    ifstream in ("crypt1.in");
    ofstream out ("crypt1.out");

    int N, x, y, result, ans = 0;
    vector<int> digits;
    
    in >> N;
    for(int i = 0; i < N; i++) {
        in >> x;
        digits.push_back(x);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                x = 100 * digits[i] + 10 * digits[j] + digits[k];
                for(int l = 0; l < N; l++) {
                    if(x * digits[l] >= 1000 || !allIn(x * digits[l], 3, digits)) continue;
                    for(int m = 0; m < N; m++) {
                        y = 10 * digits[l] + digits[m];
                        if(x * digits[m] >= 1000 || !allIn(x * digits[m], 3, digits))
                            continue;
                        if(x * y < 10000 && allIn(x * y, 4, digits))
                            ans++;
                    }
                }
            }
        }
    }
    out << ans << endl;
}
