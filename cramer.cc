#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

double determinant(vector<vector<int> > matrix) {
    int ans = 0;
    if(matrix[0].size() == 2) {
        ans += matrix[0][0] * matrix[1][1];
        ans -= matrix[1][0] * matrix[0][1];
        return ans;
    }

    vector<vector<int> > matrix2;
    int cofactor, count = 0;

    for(int i = 1; i < matrix.size(); i++) {
        vector<int> temp;
        for(int j = 1; j < matrix.size(); j++)
            temp.push_back(j);
        matrix2.push_back(temp);
    }

    for(int i = 0; i < matrix.size(); i++) {
        if(i % 2 == 0)
            cofactor = 1;
        else
            cofactor = -1;
        for(int j = 1; j < matrix.size(); j++) {
            for(int k = 0; k < matrix.size(); k++, count++) {
                if(k == i) {
                    count--;
                    continue;
                }
                matrix2[j - 1][count] = matrix[j][k];
            }
            count = 0;
        }
        ans += (cofactor * matrix[0][i] * determinant(matrix2));
    }

    return ans;
}

int main() {
    ifstream in ("cramer.in");
    ofstream out ("cramer.out");

    vector<vector<int> > matrix;
    vector<vector<int> > matrix2;
    vector<double> solutions, determinants;
    int N;

    in >> N;

    for(int i = 0; i < N; i++) {
        vector<int> temp3;
        vector<int> temp2;
        for(int j = 0; j <= N; j++) {
            int temp;
            in >> temp;
            temp2.push_back(temp);
            if(j != N)
                temp3.push_back(temp);
        }
        matrix.push_back(temp2);
        matrix2.push_back(temp3);
    }

    determinants.push_back(determinant(matrix2));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            matrix2[j][i] = matrix[j][N];
        determinants.push_back(determinant(matrix2));
        if(determinants[0] == 0) {
            out << "Infinite solutions or no solutions, Cramer's rule is unapplicable." << endl;
            return 0;
        }
        for(int j = 0; j < N; j++)
            matrix2[j][i] = matrix[j][i];
        solutions.push_back(determinants[i + 1] / determinants[0]);
    }

    for(int i = 0; i < N; i++)
        out << "Variable " << i + 1 << ": " << solutions[i] << endl;
}
