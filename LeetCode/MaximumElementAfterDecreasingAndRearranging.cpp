class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (decltype(arr.size()) i = 1; i != arr.size(); ++i) {
            if (arr[i] - arr[i - 1] >= 1)
                arr[i] = arr[i - 1] + 1;
        }
        return arr.back();
    }
};

int main() {
  
  
  return 0;  
}
