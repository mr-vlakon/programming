class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<vector<int>> q;
        int answer = 0;
        vector<int> top;
        for (int i = 0; i != grid.size(); ++i) {
                if (visited[i][0] == false) {
                    q.push({0, i, 0});
                    while (!q.empty()) {
                        top = q.front();
                        q.pop();
                        visited[top[1]][top[2]] = true;
                        answer = max(answer, top[0]);
                        if ((top[2] + 1) < grid[0].size() && grid[top[1]][top[2]] < grid[top[1]][top[2] + 1] && !visited[top[1]][top[2] + 1]) {
                            q.push({top[0] + 1, top[1], top[2] + 1});
                            visited[top[1]][top[2] + 1] = true;
                        }
                        if ((top[2] + 1) < grid[0].size() && (top[1] + 1) < grid.size()  && grid[top[1]][top[2]] < grid[top[1] + 1][top[2] + 1] && !visited[top[1] + 1][top[2] + 1]) {
                            q.push({top[0] + 1, top[1] + 1, top[2] + 1});
                            visited[top[1] + 1][top[2] + 1] = true;
                        }
                        if ((top[2] + 1) < grid[0].size() && (top[1] - 1) >= 0  && !visited[top[1] - 1][top[2] + 1] && grid[top[1]][top[2]] < grid[top[1] - 1][top[2] + 1] ) {
                            q.push({top[0] + 1, top[1] - 1, top[2] + 1});
                            visited[top[1] - 1][top[2] + 1] = true;
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
