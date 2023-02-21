class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int answer = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        bool status = false;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!visited[i][j] && grid[i][j] == 0) {
                    q.push({i, j});
                    status = false;
                    while (!q.empty()) {
                        auto top = q.front();
                        q.pop();
                        visited[top.first][top.second] = true;
                        if (top.first == (grid.size() - 1) || top.first == 0) {
                            status = true;
                        }
                        if (top.second == (grid[0].size() - 1) || top.second == 0) {
                            status = true;
                        }            
                        if ((top.first + 1) < grid.size() 
                        && grid[top.first + 1][top.second] == 0 && !visited[top.first + 1][top.second])                      {
                            q.push({top.first + 1, top.second});
                        }
                        if ((top.first - 1) >= 0 
                        && grid[top.first - 1][top.second] == 0 && !visited[top.first - 1][top.second])                      {
                            q.push({top.first - 1, top.second});
                        }
                        if ((top.second + 1) < grid[0].size() 
                        && grid[top.first][top.second + 1] == 0 && !visited[top.first][top.second + 1])                      {
                            q.push({top.first, top.second + 1});
                        }
                        if ((top.second - 1) >= 0 
                        && grid[top.first][top.second - 1] == 0 && !visited[top.first][top.second - 1])                      {
                            q.push({top.first, top.second - 1});
                        }
                    }
                    if (!status) {
                        ++answer;
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
