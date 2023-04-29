class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int answer = 0;
        int tmp = 0;
        pair<int, int> top;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] != 0 && visited[i][j] == false) {
                    q.push({i, j});
                    tmp = 0;
                    visited[i][j] = true;
                    while (!q.empty()) {
                        top = q.front();
                        q.pop();
                        tmp += grid[top.first][top.second];
                        if ((top.first + 1) < grid.size() && (grid[top.first + 1][top.second] > 0) && !visited[top.first + 1][top.second]) {
                            q.push({top.first + 1, top.second});
                            visited[top.first + 1][top.second] = true;
                        }
                        if ((top.first - 1) >= 0 && (grid[top.first - 1][top.second] > 0) && !visited[top.first - 1][top.second]) {
                            q.push({top.first - 1, top.second});
                            visited[top.first - 1][top.second] = true;
                        }
                        if ((top.second + 1) < grid[0].size() && (grid[top.first][top.second + 1] > 0) && !visited[top.first][top.second + 1]) {
                            q.push({top.first, top.second + 1});
                            visited[top.first][top.second + 1] = true;
                        }
                        if ((top.second - 1) >= 0 && (grid[top.first][top.second - 1] > 0) && !visited[top.first][top.second - 1]) {
                            q.push({top.first, top.second - 1});
                            visited[top.first][top.second - 1] = true;
                        }
                    }
                    answer = max(answer, tmp);
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
