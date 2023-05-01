class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, deque<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0, 0}});
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), 100000));      
        dist[0][0] = 0;
        visited[0][0] = true;
        int newDist = 0;
        pair<int, pair<int, int>> top;
        while (!pq.empty()) {
            top = pq.top();
            pq.pop();
            visited[top.second.first][top.second.second] = true;
            if (dist[top.second.first][top.second.second] < top.first) continue;
            if ((top.second.first + 1) < grid.size() && !visited[top.second.first + 1][top.second.second]) {
                visited[top.second.first + 1][top.second.second] = true;
                newDist = dist[top.second.first][top.second.second] + grid[top.second.first + 1][top.second.second];
                if (newDist < dist[top.second.first + 1][top.second.second]) {
                    dist[top.second.first + 1][top.second.second] = newDist;
                    pq.push({newDist, {top.second.first + 1, top.second.second}});
                }
            }
            if ((top.second.first - 1) >= 0 && !visited[top.second.first - 1][top.second.second]) {
                visited[top.second.first - 1][top.second.second] = true;
                newDist = dist[top.second.first][top.second.second] + grid[top.second.first - 1][top.second.second];
                if (newDist < dist[top.second.first - 1][top.second.second]) {
                    
                    dist[top.second.first - 1][top.second.second] = newDist;
                    pq.push({newDist, {top.second.first - 1, top.second.second}});
                }
            }
            if ((top.second.second + 1) < grid[0].size() && !visited[top.second.first][top.second.second + 1]) {
                visited[top.second.first][top.second.second + 1] = true; 
                newDist = dist[top.second.first][top.second.second] + grid[top.second.first][top.second.second + 1];
                if (newDist < dist[top.second.first][top.second.second + 1]) {
                    
                    dist[top.second.first][top.second.second + 1] = newDist;
                    pq.push({newDist, {top.second.first, top.second.second + 1}});
                }
            }
            if ((top.second.second - 1) >= 0 && !visited[top.second.first][top.second.second - 1]) {
                visited[top.second.first][top.second.second - 1] = true; 
                newDist = dist[top.second.first][top.second.second] + grid[top.second.first][top.second.second - 1];
                if (newDist < dist[top.second.first][top.second.second - 1]) {
                    dist[top.second.first][top.second.second - 1] = newDist;
                    pq.push({newDist, {top.second.first, top.second.second - 1}});
                }
            }
            if ((top.second.first == (grid.size() - 1)) && (top.second.second == (grid[0].size() - 1))) {
                break;
            }
        }
        return dist[dist.size() - 1][dist[0].size() - 1];
    }
};

int main() {
  
  
  
  
  return 0;  
}
