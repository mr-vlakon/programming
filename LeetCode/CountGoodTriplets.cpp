class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        for (decltype(arr.size()) i = 0; i != arr.size() - 2; ++i) {
            for (decltype(arr.size()) j = i + 1; j != arr.size() - 1; ++j) {
                for (decltype(arr.size()) k = j + 1; k != arr.size(); ++k) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
