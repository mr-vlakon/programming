class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> v(grid[0].size(), 0);
        for (int i = 0; i != grid[0].size(); ++i) {
            for (int j = 0; j != grid.size(); ++j) {
                v[i] = max(v[i], static_cast<int>((to_string(grid[j][i]).size())));
            }
        }    
        return v;
    }
};

int main() {
  
  
  
  
  return 0;  
}
