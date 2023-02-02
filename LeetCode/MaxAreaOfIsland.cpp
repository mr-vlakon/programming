class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer = 0;
        vector<vector<int>> index(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 1 && index[i][j] == 0) {
                    queue<pair<int, int>> q;
                    int cnt = 1;
                    q.push({i, j});
                    index[i][j] = 1;
                    while(!q.empty()) {
                        auto top = q.front();
                        q.pop();
                        
                        if ((((top.first + 1) < grid.size())) && 
                        (grid[top.first + 1][top.second] == 1) && (
                            index[top.first + 1][top.second] == 0
                        )) {
                            q.push({top.first + 1, top.second});
                            index[top.first + 1][top.second] = 1;
                            ++cnt; 
                        }
                        
                        if (((top.first - 1) >= 0) &&  
                        (grid[top.first - 1][top.second] == 1) &&
                        (index[top.first - 1][top.second] == 0)) {
                            index[top.first - 1][top.second] = 1;
                            //grid[top.first - 1][top.second] == -1;
                            q.push({top.first - 1, top.second});
                            ++cnt;
                        }
                        
                        if (((top.second + 1) < grid[0].size()) && 
                        (grid[top.first][top.second + 1] == 1) &&
                        (index[top.first][top.second + 1] == 0)) {
                            //grid[top.first][top.second + 1] == -1;
                            index[top.first][top.second + 1] = 1;
                            q.push({top.first, top.second + 1});
                            ++cnt;
                        }
                        
                        if (((top.second - 1) >= 0) &&
                        (grid[top.first][top.second - 1] == 1) && (index[top.first][top.second - 1] == 0)) {
                            index[top.first][top.second - 1] = 1;
                            //grid[top.first][top.second - 1] == -1;
                            q.push({top.first, top.second - 1});
                            ++cnt;
                        }   
                            
                    }
                    answer = max(answer, cnt);
                }
            }
        }
        return answer;     
    }
};

int main() {
  
  
  return 0;  
}
