#include <iostream>
#include <fstream>

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
};

int main(){

    return 0;
}