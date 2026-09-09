#include <iostream>
#include <fstream>
#include <cstdlib> // For exit(1)
using namespace std;

class Matrix {
    private:
        int size;
        int** data;

        void allocateMemory(int n) {
            size = n;
            if (size == 0) {
                data = nullptr;
                return;
            }
            // Allocate array of pointers
            data = new int*[size];
            for (int i = 0; i < size; ++i) {
                // Allocate rows
                data[i] = new int[size];
            }
        }

        void freeMemory() {
            if (data != nullptr) {
                for (int i = 0; i < size; ++i) {
                    delete[] data[i];
                }
                delete[] data;
                data = nullptr;
            }
            size = 0;
        }
        
        // Helper function to check if dimensions match
        bool hasSameSize(const Matrix& other) const {
            return this->size == other.size;
        }
    public:
        // 1. Default Constructor
        Matrix() : size(0), data(nullptr) {}

        // 2. Identity Matrix Constructor
        Matrix(int n) {
            allocateMemory(n);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (i == j) data[i][j] = 1;
                    else data[i][j] = 0;
                }
            }
        }

        // 3. Diagonal Matrix Constructor
        Matrix(int n, int* diag_elements) {
            allocateMemory(n);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (i == j) data[i][j] = diag_elements[i];
                    else data[i][j] = 0;
                }
            }
        }

        // 4. Destructor
        ~Matrix() {
            freeMemory();
        }

        // Copy Constructor
        Matrix(const Matrix& other) {
            allocateMemory(other.size);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }

        // Assignment Operator
        Matrix& operator = (const Matrix& other) {
            if (this != &other) { // Prevent self-assignment
                freeMemory();
                allocateMemory(other.size);
                for (int i = 0; i < size; ++i) {
                    for (int j = 0; j < size; ++j) {
                        data[i][j] = other.data[i][j];
                    }
                }
            }
            return *this;
        }

        // ======== OPERATIONS ==============

        // Addition Operator
        Matrix operator + (const Matrix& other) const {
            if (!hasSameSize(other)) {
                cout << "ERROR: Matrix dimensions do not match for addition!\n";
                exit(1);
            }

            Matrix result;
            result.allocateMemory(this->size);

            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    result.data[i][j] = this->data[i][j] + other.data[i][j];
                }
            }
            return result;
        }

        // Subtraction Operator
        Matrix operator - (const Matrix& other) const {
            if (!hasSameSize(other)) {
                cout << "ERROR: Matrix dimensions do not match for subtraction!\n";
                exit(1);
            }

            Matrix result;
            result.allocateMemory(this->size);

            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    result.data[i][j] = this->data[i][j] - other.data[i][j];
                }
            }
            return result;
        }

        // Multiplication Operator
        Matrix operator*(const Matrix& other) const {
            if (!hasSameSize(other)) {
                cout << "ERROR: Matrix dimensions do not match for multiplication!\n";
                exit(1);
            }

            Matrix result;
            result.allocateMemory(this->size);

            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    result.data[i][j] = 0; // Initialize element to mske it zero
                    for (int k = 0; k < size; ++k) {
                        result.data[i][j] += this->data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }

};

int main(){

    return 0;
}