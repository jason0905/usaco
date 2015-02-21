/*
ID: jason091
LANG: C++
TASK: beads
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream fin ("beads.in");
    ofstream fout ("beads.out");

    int N, splitLeft = 0, splitRight = 0, max = 0, count = 0;
    bool cont = true;
    char currColor;
    string beads;

    fin >> N;
    fin >> beads;

    for(int i = 0; ; i++) {
        if(beads[i] == '\n') beads[i] = '\0';
        if(beads[i] != '\0') continue;
        break;
    }

    for(int i = 0; i < N; i++) {

        currColor = beads[i];

        for(int j = i; cont == true && count < N; j++, count++) {
            j %= N;
            if(currColor == 'w' && beads[j] != 'w') currColor = beads[j];
            if(beads[j] == currColor || beads[j] == 'w') {
                splitRight++;
                continue;
            }
            cont = false;
        }
        
        count = 0;

        cont = true;

        currColor = beads[(i - 1 + N) % N];

        for(int j = i - 1; cont == true && count < N; j--, count++) {
            j = (j + N) % N;
            if(currColor == 'w' && beads[j] != 'w') currColor = beads[j];
            if(beads[j] == currColor || beads[j] == 'w') {
                splitLeft++;
                continue;
            }
            cont = false;
        }

        if(N > (splitLeft + splitRight)) {
            if((splitLeft + splitRight) > max) max = splitLeft + splitRight;
        }
        else
            max = N;

        splitLeft = 0;
        splitRight = 0;
        count = 0;
        cont = true;
    }

    fout << max << endl;
}
