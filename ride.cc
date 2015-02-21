/*
ID: jason091
LANG: C++
TASK: ride
 */
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int get_code(char *a) {
    int c = 1;
    int i=0;
    for(i=0; a[i]!='\0' && a[i]!='\n'; a++) c = (c * (a[i]-'A'+1)) % 47;
    return c;
}

int main() {
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");
    char a[7], b[7];
    int c=1, d=1;

    fin >> a >> b;

    c = get_code(a);
    d = get_code(b);

    if(c==d) {
        fout << "GO" << endl;
        exit (0);
    }
    fout << "STAY" << endl;
    exit (0);
}
