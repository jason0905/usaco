/*
ID: jason091
LANG: C++
TASK: palsquare
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string reverse(string x) {
    string temp = x;

    for(int i = 0; i < x.size(); i++)
        temp[x.size() - i - 1] = x[i];

    return temp;
}

string changeBase(int n, int b) {
    string x;

    for(int i = 0; n > 0; i++) {
        if((n % b) < 10)
            x += (n % b) + 48;
        else
            x += ((n % b) + 55);

        n /= b;
    }

    return x;
}

int main() {

    ifstream in ("palsquare.in");
    ofstream out ("palsquare.out");

    int b, z;
    string temp;
    vector<string> x;

    in >> b;

    for(int k = 0; k < 300; ++k) {
        z = k * k;
        temp = changeBase((z), b);
        for(int i = 0, j = temp.size() - 1; i <= j; i++, j--) {
            if(temp[i] != temp[j]) break;
            else if((j - i) < 2) {
                x.push_back(reverse(changeBase(k, b)));
                x.push_back(temp);
            }
        }
    }

    for(int i = 0; i < x.size(); i++) {
        out << x[i] << " ";
        i++;
        out << x[i] << endl;
    }
}
