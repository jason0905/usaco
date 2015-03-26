#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void squarenum(int & N, int & count, vector<int> & square, int layer) {
    if(layer == N * N) {
        count++;
        return;
    }
    if(square[0] != N) {
        square[0]++;
        squarenum(N, count, square, layer + 1);
        square[0]--;
    }
    for(int i = 1; i < N; i++) {
        if(square[i] < square[i - 1]) {
            square[i]++;
            squarenum(N, count, square, layer + 1);
            square[i]--;
        }
    }
}

int main() {
    ifstream in ("statesprint30.in");
    ofstream out ("statesprint30.out");

    int N, count = 0;
    vector<int> square;
    in >> N;
    for(int i = 0; i < N; i++)
        square.push_back(0);

    squarenum(N, count, square, 1);

    out << count << endl;
}
