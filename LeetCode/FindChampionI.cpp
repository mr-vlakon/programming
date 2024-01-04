class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        vector<int> v(grid.size());
        for (int i = 0; i != grid.size(); ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    v[i] += 1;
                }
            }
        }
        int maxV = 0;
        int ind = 0;
        for (int i = 0; i != v.size(); ++i) {
            if (v[i] > maxV) {
                maxV = v[i];
                ind = i;
            }
        }
        return ind;
    }
};

int main()
{


  return 0;
}

