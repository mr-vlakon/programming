class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if ((r * c) != (mat.size() * mat[0].size())) return mat;
        vector<vector<int>> v(r);
        int cnt = 0;
        int row = 0;
        for (auto &e: mat) {
            for (auto &p : e) {
                if (cnt == c) {
                    cnt = 0;
                    ++row;
                }
                v[row].push_back(p);
                ++cnt;
            }
        }
        return v;
    }
};

int main() {
  
  
  return 0;  
}
