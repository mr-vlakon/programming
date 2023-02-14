class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.size() < 3 && grid[0].size() < 3) return 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        bool status = false;
        int answer = 0;
        int cnt = 0;
        for (int i = 1 ; i < grid.size() - 1; ++i) {
            for (int j = 1; j < grid[0].size() - 1; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    cnt = 1;
                    status = false;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto top = q.front();                    
                        q.pop();
                        if (top.first == 0 || top.first == (grid.size() - 1) || top.second == 0 || top.second == (grid[0].size() - 1)) {
                            status = true;
                        }
                        if ((top.first - 1) >= 0) {
                            if (grid[top.first - 1][top.second] == 1 && !visited[top.first - 1][top.second]) {
                                ++cnt;
                                visited[top.first - 1][top.second] = true;
                                q.push({top.first - 1, top.second});
                            }
                        }
                        if (((top.first + 1) < grid.size())) {
                            if (grid[top.first + 1][top.second] == 1 && !visited[top.first + 1][top.second]) {
                                ++cnt;
                                visited[top.first + 1][top.second] = true;
                                q.push({top.first + 1, top.second});
                            }
                        }
                        if ((top.second + 1) < grid[0].size()) {
                            if (grid[top.first][top.second + 1] == 1 && !visited[top.first][top.second + 1]) {
                                ++cnt;
                                visited[top.first][top.second + 1] = true;
                                q.push({top.first, top.second + 1});
                            }
                        }
                        if ((top.second - 1) >= 0) {
                            if (grid[top.first][top.second - 1] == 1 && !visited[top.first][top.second - 1]) {                  
                                ++cnt;
                                visited[top.first][top.second - 1] = true;                         
                                q.push({top.first, top.second - 1});
                            }
                        }
                        visited[top.first][top.second] = true;
                    }
                    if (!status)
                        answer += cnt;
                }
            }
        }          
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
