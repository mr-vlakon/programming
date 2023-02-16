class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        queue<pair<int, int>> q;
        int rem1 = 0;
        int rem2 = 0;
        bool status1 = false;
        bool status2 = false;
        pair<int, int> top;
        for (int i = 0; i != land.size(); ++i) {
            for (int j = 0; j != land[0].size(); ++j) {        
                if (land[i][j] == 1) {
                    q.push({i, j});
                    rem1 = 0;
                    rem2 = 0;
                    while (!q.empty()) {
                            top = q.front();
                            q.pop();
                            status1 = false;
                            status2 = false;
                            land[top.first][top.second] = -1;
                            if ((top.first + 1) < land.size() && land[top.first + 1][top.second] == 1) {
                                land[top.first + 1][top.second] = -1;
                                q.push({top.first + 1, top.second});
                            } else {
                                status1 = true;
                            }
                            if ((top.second + 1) < land[0].size() && 
                            land[top.first][top.second + 1] == 1) {
                                land[top.first][top.second + 1] = -1;
                                q.push({top.first, top.second + 1});
                            } else {
                                status2 = true;
                            }
                            if (status1 && status2) {
                                rem1 = top.first;
                                rem2 = top.second;
                            }                            
                    }
                    result.push_back({i, j, rem1, rem2});
                }
            }
        }
        
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
