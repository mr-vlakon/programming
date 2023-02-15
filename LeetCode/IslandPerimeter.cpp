class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int answer = 0;
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    answer += 4;
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()) {
                        auto top = q.front();
                        q.pop();
                        count = 0;
                        if (((top.first + 1) < grid.size()) && 
                        grid[top.first + 1][top.second] == 1) {
                            ++count;
                            if (!visited[top.first + 1][top.second]) {
                                q.push({top.first + 1, top.second});
                                visited[top.first + 1][top.second] = true;
                                answer += 4;
                            }
                        }                        
                        if (((top.first - 1) >= 0) &&  
                        (grid[top.first - 1][top.second] == 1)) {
                            ++count;
                            if (!visited[top.first - 1][top.second]) {
                                q.push({top.first - 1, top.second});
                                visited[top.first - 1][top.second] = true;
                                answer += 4;
                            }
                        }
                        if (((top.second + 1) < grid[0].size()) && 
                        (grid[top.first][top.second + 1] == 1)) {
                            ++count;
                            if (!visited[top.first][top.second + 1]) {
                                q.push({top.first, top.second + 1});
                                visited[top.first][top.second + 1] = true;
                                answer += 4;
                            }
                        }
                        if (((top.second - 1) >= 0) &&
                        (grid[top.first][top.second - 1] == 1)) {
                            ++count;
                            if (!visited[top.first][top.second - 1]) {
                                q.push({top.first, top.second - 1});
                                visited[top.first][top.second - 1] = true;
                                answer += 4;
                            }
                        }
                        answer -= count; 
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
