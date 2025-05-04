#pragma once
#include <vector>
#include <string>
using namespace std;

void readFullMatrix(const string& filename, vector<vector<int> >& matrix, int& rows, int& cols);
void readFullMatrixManual(vector<vector<int> >& matrix, int& rows, int& cols);
void readSparseManual(vector<vector<int> >& matrix, int& rows, int& cols);
void printMatrix(const vector<vector<int> >& matrix);
void convertToSparse(const vector<vector<int> >& matrix, vector<int>& vval, vector<int>& vpos, vector<int>& vptr);
void subtractFromDiagonalSparse(vector<int>& vval, vector<int>& vpos, vector<int>& vptr, int rows, int cols, int number);
void readMatrixFromFile(const string& filename, vector<vector<int> >& matrix, int& rows, int& cols);
void generateRandomMatrix(vector<vector<int> >& matrix, int rows, int cols);
void readSparseManualDirect(vector<int>& vval, vector<int>& vpos, vector<int>& vptr, int& rows, int& cols);
void printSparseMatrix(const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptr, int rows, int cols);
void sparseToFullMatrix(const vector<int>& vval, const vector<int>& vpos, const vector<int>& vptr, int rows, int cols, vector<vector<int> >& matrix);
void printVector(const string& label, const vector<int>& v); // ← Додати ось це
