#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void PrintVector(const vector<T> &vec) {
        cout << "{";
        auto sizeOfVector = vec.size();
        decltype(vec.size()) i = 1;
        for (const auto &v: vec) {
                if (sizeOfVector != i) {
                        cout << v << ",";
                } else {
                        cout << v;
                }
                ++i;
        }
        cout << "};" << endl;
}

template<typename T>
void NonDecreasingInsertionSort(vector<T> &A) {
        for (decltype(A.size()) j = 1; j < A.size(); ++j) {
                T key = A[j];
                int i = j - 1;
                while ((i >= 0) && (A[i] > key)) {
                        A[i+1] = A[i];
                        i = i - 1;
                }
                A[i+1] = key;
        }
}

template<class T>
void NonGrowingInsertionSort(vector<T> &A) {
        for (decltype(A.size()) j = 1; j < A.size(); ++j) {
                T key = A[j];
                int i = j - 1;
                while ((i >= 0) && (A[i] < key)) {
                        A[i+1] = A[i];
                        i = i - 1;
                }
                A[i+1] = key;
        }
}



int main() {
        vector<int> v1 = {2,0,17,3,8,6,27,14};
        vector<int> v2 = {2,0,17,3,8,6,27,14};

        PrintVector(v1);
        NonDecreasingInsertionSort(v1);
        PrintVector(v1);

        cout << endl;

        PrintVector(v2);
        NonGrowingInsertionSort(v2);
        PrintVector(v2);

        cout << endl;

        PrintVector(v1);
        NonGrowingInsertionSort(v1);
        PrintVector(v1);

        return 0;
}
