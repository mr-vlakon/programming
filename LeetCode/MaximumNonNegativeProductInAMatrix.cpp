class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        vector<vector<pair<long long, long long>>> dp(grid.size());
        int n = grid.size();
        for (auto &e: dp) {
            e.resize(grid[0].size(), {1, 1});
        }
        dp[0][0].first = grid[0][0];
        dp[0][0].second = grid[0][0];
        for (decltype(grid[0].size()) i = 1; i != grid[0].size(); ++i) {
            dp[0][i].first = grid[0][i] * dp[0][i - 1].first;
            dp[0][i].second = grid[0][i] * dp[0][i - 1].second;
        }
        for (int j = 1; j < n; ++j) {
            dp[j][0].first = grid[j][0] * dp[j - 1][0].first;
            dp[j][0].second = grid[j][0] * dp[j - 1][0].second;
            long long q = -1000000;
            long long l = 10000000;
            for (int i = 1; i < grid[0].size(); ++i) {
                l = min<long long>(grid[j][i] * dp[j][i - 1].first, grid[j][i] * dp[j - 1][i].first);
                l = min<long long>(l, grid[j][i] * dp[j - 1][i].first);
                l = min<long long>(l, grid[j][i] * dp[j - 1][i].second);
                l = min<long long>(l, grid[j][i] * dp[j][i - 1].first);
                l = min<long long>(l, grid[j][i] * dp[j][i - 1].second);
                dp[j][i].first = l;
                
                q = max<long long>(grid[j][i] * dp[j][i - 1].second, grid[j][i] * dp[j - 1][i].second);
                q = max<long long>(q, grid[j][i] * dp[j - 1][i].first);
                q = max<long long>(q, grid[j][i] * dp[j - 1][i].second);
                q = max<long long>(q, grid[j][i] * dp[j][i - 1].first);
                q = max<long long>(q, grid[j][i] * dp[j][i - 1].second);
                dp[j][i].second = q;
            }
        }
        return dp[n - 1][grid[0].size() - 1].second < 0 ? -1 : dp[n - 1][grid[0].size() - 1].second % 
            1000000007;
    }
};

int main() {
  
  
  
  return 0;  
}
