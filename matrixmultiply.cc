#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream in ("matrixmultiply.in");
    ofstream out ("matrixmultiply.out");

    int row1, rowcolumn, column2, temp;
    vector<vector<double> > matrix1, matrix2, answer;

    in >> row1 >> rowcolumn >> column2;

    for(int i = 0; i < row1; i++) {
        vector<double> temp2;
        for(int j = 0; j < rowcolumn; j++) {
            in >> temp;
            temp2.push_back(double(temp));
        }
        matrix1.push_back(temp2);
    }

    for(int i = 0; i < rowcolumn; i++) {
        vector<double> temp2;
        for(int j = 0; j < column2; j++) {
            in >> temp;
            temp2.push_back(double(temp));
        }
        matrix2.push_back(temp2);
    }

    for(int i = 0; i < row1; i++) {
        vector<double> temp2;
        for(int j = 0; j < column2; j++)
            temp2.push_back(double(0));
        answer.push_back(temp2);
    }

    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < column2; j++) {
            temp = 0;
            for(int k = 0; k < rowcolumn; k++)
                temp += matrix1[i][k] * matrix2[k][j];
            answer[i][j] = temp;
        }
    }

    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < column2; j++)
            out << answer[i][j] << " ";
        out << endl;
    }
}
