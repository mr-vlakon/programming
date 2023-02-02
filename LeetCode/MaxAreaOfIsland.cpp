class Solution {
public:
    struct hashFunction {
        size_t operator()(const pair<int, int> &x) const
        {
            return x.first ^ x.second;
        }
    };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        unordered_set<pair<int, int>, hashFunction> us;
        int answer = 0;
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                queue<pair<int, int>> q;
                if (grid[i][j] == 1) {
                    int cnt = 1;
                    q.push({i, j});
                    us.insert({i, j});
                    while(!q.empty()) {
                        auto top = q.front();
                        q.pop();
                        if (((top.first + 1) < grid.size()) && 
                        grid[top.first + 1][top.second] == 1 
                        && us.find({top.first + 1, top.second}) == us.cend()) {
                            q.push({top.first + 1, top.second});
                            us.insert({top.first + 1, top.second});
                            ++cnt;
                        }
                        
                        if (((top.first - 1) >= 0) &&  
                        (grid[top.first - 1][top.second] == 1) &&
                        (us.find({top.first - 1, top.second}) == us.cend())) {
                            q.push({top.first - 1, top.second});
                            us.insert({top.first - 1, top.second});
                            ++cnt;
                        }
                        
                        if (((top.second + 1) < grid[0].size()) && 
                        (grid[top.first][top.second + 1] == 1) &&
                        us.find({top.first, top.second + 1}) == us.cend()) {
                            q.push({top.first, top.second + 1});
                            us.insert({top.first, top.second + 1});
                            ++cnt;
                        }
                        
                        if (((top.second - 1) >= 0) &&
                        (grid[top.first][top.second - 1] == 1) && 
                        us.find({top.first, top.second - 1}) == us.cend()) {
                            q.push({top.first, top.second - 1});
                            us.insert({top.first, top.second - 1});
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
