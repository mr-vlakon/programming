class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        int answer = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if ((grid[i][j] == '1') && (!visited[i][j])) {
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        auto top = q.front();
                        q.pop();
                        if ((top.first + 1) < grid.size() && !visited[top.first + 1][top.second] && grid[top.first + 1][top.second] == '1') {
                            visited[top.first + 1][top.second] = true;
                            q.push({top.first + 1, top.second});
                        }
                        if ((top.second + 1) < grid[0].size() && !visited[top.first][top.second + 1] && grid[top.first][top.second + 1] == '1') {
                            visited[top.first][top.second + 1] = true;
                            q.push({top.first, top.second + 1});
                        }
                        if ((top.first - 1) >= 0 && !visited[top.first - 1][top.second] && grid[top.first - 1][top.second] == '1') {
                            visited[top.first - 1][top.second] = true;
                            q.push({top.first - 1, top.second});
                        }
                        if ((top.second - 1) >= 0 && !visited[top.first][top.second - 1] && grid[top.first][top.second - 1] == '1') {
                            visited[top.first][top.second - 1] = true;
                            q.push({top.first, top.second - 1});
                        }
                    }
                    ++answer;
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
