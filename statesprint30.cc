#include <vector>
#include <fstream>

using namespace std;

void squarenum(int N, int count, vector<int> square, int layer) {
    if(layer == N) count++;
}

int main() {
    ifstream in ("statesprint30.in");
    ofstream out ("statesprint30.out");

    int N, count = 0;
    vector<int> square;
    for(int i = 0; i < N; i++) {
        square.push_back(0);
    }
    squarenum(N, count, square, 1);

    out << count << endl;
}
