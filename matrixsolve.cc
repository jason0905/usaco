#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

bool isZero(vector<double> a, vector<double> b) {
    double x = 0;
    for(int i = 0; i < a.size() - 1; i++) {
        if(b[i] != 0) {
            x = a[i] / b[i];
            break;
        }
    }
    for(int i = 0; i < a.size() - 1; i++) {
        if(b[i] * x == a[i]) continue;
        else
            return false;
    }
    if(a[a.size() - 1] != b[a.size() - 1] * x) return true;
    return false;
}

void divide(vector<double> & a, double b) {
    for(int i = 0; i < a.size(); i++)
        a[i] /= b;
}

void subtract(vector<double> & a, vector<double> & b, double x) {
    for(int i = 0; i < a.size(); i++)
        a[i] = a[i] - (x * b[i]);
}

bool isMultipleOf(vector<double> a, vector<double> b) {
    double x = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b[i] != 0) {
            x = a[i] / b[i];
            break;
        }
    }
    for(int i = 0; i < a.size(); i++) {
        if(b[i] * x == a[i]) continue;
        else
            return false;
    }
    return true;
}

void change(vector<double> & a, vector<double> & b) {
    double x;
    for(int i = 0; i < a.size(); i++) {
        x = a[i];
        a[i] = b[i];
        b[i] = x;
    }
}

int main() {
    ifstream in ("matrixsolve.in");
    ofstream out ("matrixsolve.out");

    int N, count = 0;
    vector<vector<double> > matrix;
    vector<double> solutions;

    // Get the degree
    in >> N;

    //Get the matrix
    for(int i = 0; i < N; i++) {
        int temp;
        vector<double> row;
        for(int j = 0; j <= N; j++) {
            in >> temp;
            row.push_back(double(temp));
        }
        matrix.push_back(row);
        solutions.push_back(0);
    }

    //Check for infinite solutions
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(isMultipleOf(matrix[i], matrix[j])) {
                out << "Infinite solutions" << endl;
                exit(0);
            }
            if(isZero(matrix[i], matrix[j])) {
                out << "No solutions" << endl;
                exit(0);
            }
        }
    }

    //Loop through each row
    for(int i = 0; i < N; count++, i++) {
	if(count == 2 * N) {
	    out << "No solutions" << endl;
	    exit(0);
	}
        //Make sure ith one in ith row isn't zero
        if(matrix[i][i] == 0) {
            if(i < N - 1)
                change(matrix[i], matrix[i + 1]);
            else {
                change(matrix[i], matrix[i - 1]);
                i -= 2;
            }
        }
        //Change corrosponding number to 1
        divide(matrix[i], matrix[i][i]);
        //Loop through rows underneath current row and change corrosponding number to 0
        for(int j = i + 1; j < N; j++)
            subtract(matrix[j], matrix[i], matrix[j][i]);
    }

    //Loop through backwards
    for(int i = N - 1; i > 0; i--) {
        //Subtract everything to zero
        for(int j = i - 1; j >= 0; j--) {
            subtract(matrix[j], matrix[i], matrix[j][i]);
        }
    }

    //Get solutions
    for(int i = 0; i < N; i++)
        solutions[i] = matrix[i][N];

    //Final Matrix
    out << "Matrix in rref" << endl;
    for(int i = 0; i < N; i++) {
	for(int j = 0; j <= N; j++)
	    out << matrix[i][j] << " ";
	out << endl;
    }

    //Output solutions
    out << "Solution:" << endl;
    for(int i = 0; i < N; i++)
        out << "Variable " << i + 1 << ": "<< solutions[i] << endl;
}
