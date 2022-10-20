class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> res;
        for (const auto &e: grid) {
            copy(e.cbegin(), e.cend(), back_inserter(res));
        }

        if (k > res.size()) {
            k = k % res.size();
        }
        rotate(res.rbegin(), res.rbegin() + k, res.rend());
        
        vector<vector<int>> answer(grid.size(), vector<int>(grid[0].size(), 0));
        int cnt = 0;
        int i = 0;
        int p = 0;
        while (i != res.size()) {
            if (i % grid[0].size() == 0 && i != 0) {
                ++cnt;
            }
            answer[cnt][i % grid[0].size()] = res[i];
            ++i;
        }

        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
