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

};

int main(){

    return 0;
}