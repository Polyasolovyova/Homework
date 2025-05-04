#include "function.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void readMatrixFromFile(const string& filename, vector<vector<int> >& matrix, int& rows, int& cols) {
    ifstream fin(filename.c_str());
    if (!fin) {
        cout << "Error opening file.\n";
        return;
    }

    int nnz;
    fin >> rows >> cols;

    if (fin >> nnz) {
        vector<int> vval(nnz), vpos(nnz), vptr(rows + 1);
        for (int i = 0; i < nnz; ++i) fin >> vval[i];
        for (int i = 0; i < nnz; ++i) fin >> vpos[i];
        for (int i = 0; i <= rows; ++i) fin >> vptr[i];

        matrix.assign(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i)
            for (int j = vptr[i]; j < vptr[i + 1]; ++j)
                matrix[i][vpos[j]] = vval[j];
    } else {
        fin.clear();
        fin.seekg(0);
        fin >> rows >> cols;
        matrix.resize(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                fin >> matrix[i][j];
    }
    fin.close();
}

void generateRandomMatrix(vector<vector<int> >& matrix, int rows, int cols) {
    matrix.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = rand() % 21 - 10;
}

void readFullMatrix(const string& filename, vector<vector<int> >& matrix, int& rows, int& cols) {
    ifstream fin(filename.c_str());
    if (!fin) {
        cout << "Error reading file.\n";
        return;
    }
    matrix.clear();
    int value;
    rows = 0;
    while (!fin.eof()) {
        vector<int> row;
        while (true) {
            fin >> value;
            if (fin.fail()) break;
            row.push_back(value);
            if (fin.peek() == '\n' || fin.eof()) break;
        }
        if (!row.empty()) {
            matrix.push_back(row);
            rows++;
        }
    }
    cols = !matrix.empty() ? matrix[0].size() : 0;
    fin.close();
}

void readFullMatrixManual(vector<vector<int> >& matrix, int& rows, int& cols) {
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    matrix.resize(rows, vector<int>(cols));
    cout << "Enter matrix values row by row:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];
}

void readSparseManual(vector<vector<int> >& matrix, int& rows, int& cols) {
    int nnz;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    cout << "Enter number of non-zero elements: ";
    cin >> nnz;

    vector<int> vval(nnz), vpos(nnz), vptr(rows + 1);
    cout << "Enter vval: ";
    for (int i = 0; i < nnz; ++i) cin >> vval[i];
    cout << "Enter vpos: ";
    for (int i = 0; i < nnz; ++i) cin >> vpos[i];
    cout << "Enter vptr: ";
    for (int i = 0; i <= rows; ++i) cin >> vptr[i];

    matrix.assign(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i)
        for (int j = vptr[i]; j < vptr[i + 1]; ++j)
            matrix[i][vpos[j]] = vval[j];
}

void readSparseManualDirect(vector<int>& vval, vector<int>& vpos, vector<int>& vptr, int& rows, int& cols) {
    int nnz;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    cout << "Enter number of non-zero elements: ";
    cin >> nnz;
    vval.resize(nnz);
    vpos.resize(nnz);
    vptr.resize(rows + 1);
    cout << "Enter vval: ";
    for (int i = 0; i < nnz; ++i) cin >> vval[i];
    cout << "Enter vpos: ";
    for (int i = 0; i < nnz; ++i) cin >> vpos[i];
    cout << "Enter vptr: ";
    for (int i = 0; i <= rows; ++i) cin >> vptr[i];
}

void printMatrix(const vector<vector<int> >& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

void printSparseMatrix(const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        int k = vptr[i];
        for (int j = 0; j < cols; ++j) {
            if (k < vptr[i + 1] && vpos[k] == j) {
                cout << vval[k] << " ";
                ++k;
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

void printVector(const string& label, const vector<int>& v) {
    cout << label << ": ";
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n";
}

void sparseToFullMatrix(const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptr, int rows, int cols, vector<vector<int> >& matrix) {
    matrix.assign(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i)
        for (int j = vptr[i]; j < vptr[i + 1]; ++j)
            matrix[i][vpos[j]] = vval[j];
}

void convertToSparse(const vector<vector<int> >& matrix, vector<int>& vval, vector<int>& vpos, vector<int>& vptr) {
    int rows = matrix.size(), cols = matrix[0].size();
    vval.clear();
    vpos.clear();
    vptr.clear();
    vptr.push_back(0);
    for (int i = 0; i < rows; ++i) {
        int count = 0;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                vval.push_back(matrix[i][j]);
                vpos.push_back(j);
                ++count;
            }
        }
        vptr.push_back(vptr.back() + count);
    }
}

void subtractFromDiagonalSparse(vector<int>& vval, vector<int>& vpos, vector<int>& vptr, int rows, int cols, int number) {
    int n = rows < cols ? rows : cols;
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = vptr[i]; j < vptr[i + 1]; ++j) {
            if (vpos[j] == i) {
                vval[j] -= number;
                found = true;
                break;
            }
        }
        if (!found) {
            int insertPos = vptr[i + 1];
            for (int j = vptr[i]; j < vptr[i + 1]; ++j) {
                if (vpos[j] > i) {
                    insertPos = j;
                    break;
                }
            }
            vval.insert(vval.begin() + insertPos, -number);
            vpos.insert(vpos.begin() + insertPos, i);
            for (size_t j = i + 1; j < vptr.size(); ++j)
                vptr[j]++;
        }
    }
}
