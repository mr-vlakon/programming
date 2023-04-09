class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [] (vector<int> &lhs, vector<int> &rhs) {
            return lhs[1] < rhs[1];
        });
        vector<int> dp(pairs.size(), 1);
        int tmp = 0;
        for (int i = 1; i != pairs.size(); ++i) {
            tmp = 0;
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) {
                    tmp = max(tmp, dp[j]);
                }
            }
            dp[i] = tmp + 1;
        }
        return *max_element(dp.cbegin(), dp.cend());
    }
};

int main() {
  
  
  
  return 0;  
}
