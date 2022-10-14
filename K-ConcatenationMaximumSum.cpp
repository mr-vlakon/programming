class Solution {
public:
    long long kadane(const vector<int> &v) {
        long long max_so_far = INT_MIN, max_ending_here = 0;

        for (int i = 0; i < v.size(); i++) {
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
	    
        vector<int> res;
        int i = 0;
        long long kad = kadane(arr);
        long long sumAll = (accumulate(arr.cbegin(), arr.cend(), 0LL) * k);
        long long prefixMax = 0;
        long long suffixMax = 0;
        long long curr = 0;
        for (decltype(arr.size()) i = 0; i < arr.size(); ++i) {
            curr += arr[i];
            if (curr > prefixMax)
                prefixMax = curr;
        }
        curr = 0;
        reverse(arr.begin(), arr.end());
        for (decltype(arr.size()) i = 0; i < arr.size(); ++i) {
            curr += arr[i];
            if (curr > suffixMax)
                suffixMax = curr;
        }
        long long ans = max<long long>(kad, sumAll);
        if (k > 1) {
            ans = max<long long>(ans, 
    suffixMax  + prefixMax + (k - 2)*accumulate(arr.cbegin(), arr.cend(), 0LL));
        } 
       // long long kadd = kadane(arr);
        long long sum = accumulate(arr.cbegin(), arr.cend(), 0LL);
        long long anss = max<long long>(kad, sum);
        if (k == 1)
            return anss;
        anss = max<long long>(prefixMax  + suffixMax, anss);
        ans = max<long long>(ans, anss);
        return ans < 0 ? 0 : ans % 1000000007;
        
        
        
    }
};

int main() {
  
  
  return 0;  
}
