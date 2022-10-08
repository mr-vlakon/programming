class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0;
        int sum = accumulate(arr.cbegin(), arr.cbegin() + k, 0);
        if ( (sum / k) >= threshold) ++cnt;
        for (decltype(arr.size()) i = 1; i <= arr.size() - k; ++i) {
            sum -= arr[i - 1];
            sum += arr[i + k - 1];
            if ( (sum / k) >= threshold) ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}
