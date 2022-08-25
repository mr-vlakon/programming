#include <iostream>
#include <vector>
using namespace std;

template<class T>
void PrintVector(vector<T> vec) {
        cout << "{";
        auto sizeOfVector = vec.size();
        decltype(vec.size()) i = 1;
        for (const auto &v: vec) {
                if (sizeOfVector != i) {
                        cout << v << ", ";
                } else
                        cout << v;
                        ++i;
        }
        cout << "};" << endl;
}

template<class T>
void Merge(vector<T> &A, int p, int q, int r) {
        int n1 = q - p + 1;
        int n2 = r - q;
        vector<int> L(n1 + 1);
        vector<int> R(n2 + 1);
        int i = 0;
        int j = 0;
        for (i = 0; i < n1; ++i) {
                L[i] = A[p + i];
        }
        for (j = 0; j < n2; ++j) {
                R[j] = A[q + j + 1];
        }
        L[n1] = 100000;
        R[n2] = 100000;
        i = 0;
        j = 0;
        for(int k = p; k <= r; ++k) {
                if (L[i] <= R[j]) {
                        A[k] = L[i];
                        ++i;
                } else {
                        A[k] = R[j];
                        ++j;
                }
        }
}

template<class T>
void MergeSort(vector<T>& A, int p, int r) {
        int q = 0;
        if (p < r) {
                q = (p + r) / 2;
                MergeSort(A, p, q);
                MergeSort(A, q + 1, r);
                Merge(A,p, q, r);
        }
}

int main() {
        vector<int> A = {10,3,2,3,1,2,4,5,     2, 4, 5, 7, 1, 2, 3, 6,     1, 0, 2};
        vector<int> v2 = {5 ,3, 41, 52, 26, 38, 57, 9};
        PrintVector(v2);
        MergeSort(v2, 0, v2.size() - 1);
        PrintVector(v2);
        return 0;
}
