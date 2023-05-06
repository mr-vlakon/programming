class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        priority_queue<vector<int>, deque<vector<int>>, greater<vector<int>>> pq;
        queue<vector<int>> q;
        q.push({start[0], start[1], 0});
        vector<int> tmp;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        visited[start[0]][start[1]] = true;
        if (grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1]) {
            pq.push({0, grid[start[0]][start[1]], (start[0]), start[1]});
        }
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            visited[tmp[0]][tmp[1]] = true;  
            if ((tmp[0] + 1) < grid.size() && !visited[tmp[0] + 1][tmp[1]] && grid[tmp[0] + 1][tmp[1]]) {
                if (grid[tmp[0] + 1][tmp[1]] >= pricing[0] && grid[tmp[0] + 1][tmp[1]] <= pricing[1]) {
                    pq.push({tmp[2] + 1, grid[tmp[0] + 1][tmp[1]], (tmp[0] + 1), tmp[1]});
                }
                q.push({tmp[0] + 1, tmp[1], tmp[2] + 1});
                visited[tmp[0] + 1][tmp[1]] = true;
            }
            if ((tmp[0] - 1) >= 0 && !visited[tmp[0] - 1][tmp[1]] && grid[tmp[0] - 1][tmp[1]]) {
                if (grid[tmp[0] - 1][tmp[1]] >= pricing[0] && grid[tmp[0] - 1][tmp[1]] <= pricing[1]) {
                    pq.push({tmp[2] + 1, grid[tmp[0] - 1][tmp[1]], (tmp[0] - 1), tmp[1]});
                }
                q.push({tmp[0] - 1, tmp[1], tmp[2] + 1});
                visited[tmp[0] - 1][tmp[1]] = true;
            }
            if ((tmp[1] + 1) < grid[0].size() && !visited[tmp[0]][tmp[1] + 1] && grid[tmp[0]][tmp[1] + 1]) {
                if (grid[tmp[0]][tmp[1] + 1] >= pricing[0] && grid[tmp[0]][tmp[1] + 1] <= pricing[1]) {
                    pq.push({tmp[2] + 1, grid[tmp[0]][tmp[1] + 1], (tmp[0]), tmp[1] + 1});
                }
                q.push({tmp[0], tmp[1] + 1, tmp[2] + 1});
                visited[tmp[0]][tmp[1] + 1] = true;
            }
            if ((tmp[1] - 1) >= 0 && !visited[tmp[0]][tmp[1] - 1] && grid[tmp[0]][tmp[1] - 1]) {
                if (grid[tmp[0]][tmp[1] - 1] >= pricing[0] && grid[tmp[0]][tmp[1] - 1] <= pricing[1]) {
                    pq.push({tmp[2] + 1, grid[tmp[0]][tmp[1] - 1], (tmp[0]), tmp[1] - 1});
                }
                q.push({tmp[0], tmp[1] - 1, tmp[2] + 1});
                visited[tmp[0]][tmp[1] - 1] = true;
            }

        }
        vector<vector<int>> answer;
        int i = 0;
        vector<int> topP;
        while (i < k && !pq.empty()) {
            topP = pq.top();
            answer.push_back({topP[2], topP[3]});
            pq.pop();
            ++i;
        }
        return answer;
   }
};

int main() {
  
  
  
  return 0;  
}
