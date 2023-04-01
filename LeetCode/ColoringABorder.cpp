class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        q.push({row, col});
        pair<int, int> top;
        int color_ = grid[row][col];
        while (!q.empty()) {
            top = q.front();
            q.pop();
            visited[top.first][top.second] = true;
            if ((top.first - 1) >= 0 && !visited[top.first - 1][top.second] && 
            grid[top.first - 1][top.second] == color_) {
                visited[top.first - 1][top.second] = true;
                q.push({top.first - 1, top.second});
            }
            if (((top.first + 1) < grid.size()) && !visited[top.first + 1][top.second] && 
            grid[top.first + 1][top.second] == color_) {
                visited[top.first + 1][top.second] = true;
                q.push({top.first + 1, top.second});
            }
            if ((top.second - 1) >= 0 && !visited[top.first][top.second - 1] && 
            grid[top.first][top.second - 1] == color_) {
                visited[top.first][top.second - 1] = true;
                q.push({top.first, top.second - 1});
            }
            if ((top.second + 1) < grid[0].size() && !visited[top.first][top.second + 1] && 
            grid[top.first][top.second + 1] == color_) {
                visited[top.first][top.second + 1] = true;
                q.push({top.first, top.second + 1});
            }
        }
        for (int j = 0; j != grid[0].size(); ++j) {
            if (visited[0][j] == 1) {
                grid[0][j] = color;
            }
        }
        for (int j = 0; j != grid[0].size(); ++j) {
            if (visited[visited.size() - 1][j] == 1) {
                grid[visited.size() - 1][j] = color;
            }
        }
        for (int i = 0; i != grid.size(); ++i) {
            if (visited[i][0] == 1) {
                grid[i][0] = color;
            }
        }
        for (int i = 0; i != grid.size(); ++i) {
            if (visited[i][visited[0].size() - 1] == 1) {
                grid[i][visited[0].size() - 1] = color;
            }
        }

        for (int i = 1; i != grid.size() - 1; ++i) {
            for (int j = 1; j != grid[0].size() - 1; ++j) {
                if (visited[i][j] && (!visited[i - 1][j] || !visited[i + 1][j] || !visited[i][j - 1] || !visited[i][j + 1])) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }
};

int main() {
  
  
  
  
  
  return 0;  
}
