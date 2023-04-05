class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), 10000000));
        priority_queue<pair<int, pair<int, int>>, deque<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        int newV = 0;
        int tmp = 0;
        pair<int, pair<int, int>> top;
        while (!pq.empty()) {
            top = pq.top();
            pq.pop();
            if (visited[top.second.first][top.second.second] == true) {
                continue;
            }    
            if (top.first > dist[top.second.first][top.second.second]) {
                continue;
            }       
            visited[top.second.first][top.second.second] = true;          
            if ((top.second.first - 1) >= 0 && !visited[top.second.first - 1][top.second.second]
            && top.first < dist[top.second.first - 1][top.second.second]) {
                newV = abs(heights[top.second.first][top.second.second] - heights[top.second.first - 1][top.second.second]);
                if (newV < dist[top.second.first - 1][top.second.second]) {
                    tmp = max(newV, top.first);
                    dist[top.second.first - 1][top.second.second] = tmp;
                    pq.push({tmp, {top.second.first - 1, top.second.second}});
                }
            }
            if ((top.second.first + 1) < heights.size() && !visited[top.second.first + 1][top.second.second] && top.first < dist[top.second.first + 1][top.second.second]) {
                newV = abs(heights[top.second.first][top.second.second] - 
                heights[top.second.first + 1][top.second.second]);
                if (newV < dist[top.second.first + 1][top.second.second]) {
                    tmp = max(newV, top.first);
                    dist[top.second.first + 1][top.second.second] = tmp;
                    pq.push({tmp, {top.second.first + 1, top.second.second}});
                }
            }
            if ((top.second.second - 1) >= 0 && !visited[top.second.first][top.second.second - 1]&& top.first < dist[top.second.first][top.second.second - 1]) {
                newV = abs(heights[top.second.first][top.second.second] - heights[top.second.first][top.second.second - 1]);
                if (newV < dist[top.second.first][top.second.second - 1]) {
                    tmp = max(newV, top.first);
                    dist[top.second.first][top.second.second - 1] = tmp;
                    pq.push({tmp, {top.second.first, top.second.second - 1}});
                }
            }
            if ((top.second.second + 1) < heights[0].size() && !visited[top.second.first][top.second.second + 1] && top.first < dist[top.second.first][top.second.second + 1]) {
                 newV = abs(heights[top.second.first][top.second.second] - heights[top.second.first][top.second.second + 1]);
                if (newV < dist[top.second.first][top.second.second + 1]) {
                    tmp = max(newV, top.first);
                    dist[top.second.first][top.second.second + 1] = tmp;
                    pq.push({tmp,{top.second.first, top.second.second + 1}});
                }
            }
            if (top.second.first == (heights.size() - 1) && top.second.second == (heights[0].size() - 1)) {
                break;
            }
        }
        return dist[dist.size() - 1][dist[0].size() - 1];        
    }
};
int main() {
  
  
  
  
  return 0;  
}
