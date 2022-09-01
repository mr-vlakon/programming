class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        if (arr.size() == 1) return arr;
        size_t n = (arr.size() - 1) / 2;
        auto m = arr[n];
        sort(arr.begin(), arr.end(), [](const int &lhs, const int &rhs) {
            return lhs > rhs;
        });
        stable_sort(arr.begin(), arr.end(),[=](const int &lhs, const int &rhs) {
           return (abs(lhs - m) > abs(rhs - m)); 
        });
        vector<int> v(arr.begin(), arr.begin() + k);
        return v;
    }
};

int main() {
  
  return 0;  
}
