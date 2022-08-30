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
void SelectionSort(vector<T> &vec)
{
        for(size_t i = 0; i != vec.size() - 1; ++i)
        {
                size_t min = i;
                for (size_t j = i + 1; j != vec.size(); ++j) {
                        if (vec[j] < vec[min])
                                min = j;
                }
                swap(vec[min], vec[i]);
        }


}

int main() {

        vector<int> v = {11,2,-1,0,3,2,15,-23,-25,-30};
        PrintVector(v);
        SelectionSort(v);
        PrintVector(v);


        return 0;
}
