class Solution {
public:
    long long appealSum(string s) {
        unordered_map<char, size_t> um;
        vector<long long> dp(s.size(), 0);
        um[s[0]] = 1;
        dp[0] = 1;
        long long count = 1;
        for (int i = 1; i != dp.size(); ++i) {
            count -= um[s[i]];
            um[s[i]] = i + 1;
            count += um[s[i]];
            dp[i] += dp[i - 1] + count;
        }
        return dp[dp.size() - 1];        
    }
};

int main() {
  
  
  
  return 0;  
}
