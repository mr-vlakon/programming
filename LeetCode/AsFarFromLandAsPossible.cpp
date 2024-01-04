class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MIN + 10));
        queue<pair<int, int>> q;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 1)
                    q.push({i*grid[0].size() + j, 0});
            }
        }
        int answer = 0;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int y = top.first % grid[0].size();
            int x = (top.first - y) / grid[0].size();
            answer = max(answer, top.second);
            if ((x - 1) >= 0 && dp[x - 1][y] < (top.second + 1) && grid[x - 1][y] == 0) {
                if (dp[x - 1][y] < (top.second - 1)) {
                    dp[x - 1][y] = top.second + 1;
                    q.push({(x - 1)*grid[0].size() + y, top.second + 1});
                }
            }   
            if ((y - 1) >= 0 && dp[x][y - 1] < (top.second + 1) && grid[x][y - 1] == 0) {
                if (dp[x][y - 1] < (top.second - 1)) {
                    dp[x][y - 1] = top.second + 1;
                    q.push({(x)*grid[0].size() + y - 1, top.second + 1});
                }
            }
            if ((x + 1) < grid[0].size() && dp[x + 1][y] < (top.second + 1) && grid[x + 1][y] == 0) {
                if (dp[x + 1][y] < (top.second - 1)) {
                    dp[x + 1][y] = top.second + 1;
                    q.push({(x + 1)*grid[0].size() + y, top.second + 1});
                }
            }   
            if ((y + 1) < grid.size() && dp[x][y + 1] < (top.second + 1) && grid[x][y + 1] == 0) {
                if (dp[x][y + 1] < (top.second - 1)) {
                    dp[x][y + 1] = top.second + 1;
                    q.push({(x)*grid[0].size() + y + 1, top.second + 1});
                }
            }
        }
        return (answer == 0) ? -1 : answer;
    }
};

int main()
{



  return 0;
}
