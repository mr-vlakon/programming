class Solution {
public:
    long long kadane(const vector<int> &v) {
        long long max_so_far = INT_MIN, max_ending_here = 0;

        for (decltype(v.size()) i = 0; i < v.size(); i++) {
            max_ending_here = max_ending_here + v[i];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                
            }
            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        long long kad = kadane(arr);
        long long sumOfArray = accumulate(arr.cbegin(), arr.cend(), 0LL); 

        long long ans2 = max<long long>(kad, sumOfArray);
        if (k == 1)
            return ans2;
        
        long long prefixMax = 0;
        long long suffixMax = 0;
        long long currPref = 0;
        long long currSuff = 0;
        
        for (int i = 0, j = arr.size() - 1; i < arr.size() && j >= 0; ++i, --j) {
            currPref += arr[i];
            currSuff += arr[j];
            if (currSuff > suffixMax)
                suffixMax = currSuff;
            if (currPref > prefixMax)
                prefixMax = currPref;
        }
 
        long long sumAll = sumOfArray * k;
        long long ans = max<long long>(kad, sumAll);

        ans = max<long long>(ans, suffixMax  + prefixMax + (k - 2)*sumOfArray); 
        ans2 = max<long long>(prefixMax  + suffixMax, ans2);
        ans = max<long long>(ans, ans2);
        return ans < 0 ? 0 : ans % 1000000007;
        
    }
};

int main() {
  
  
  return 0;  
}
