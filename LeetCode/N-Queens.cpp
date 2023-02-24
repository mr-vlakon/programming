class Solution {
public:
    void placeQueens(vector<int> &v, int r) {
        if (r >= n_) {
            vector<string> tmp(v.size(), string(n_, '.'));
            int i = 0;
            for (const auto &e: v) {
                tmp[i][e] = 'Q';
                ++i;
            }
            answer.push_back(tmp);
            return;
        } else {
            for (int j = 0; j < n_; ++j) {
                bool legal = true;
                for (int i = 0; i < r; ++i) {
                    if (v[i] == j || v[i] == (j + r - i) || v[i] == (j - r + i)) {
                        legal = false;
                    }
                }
                if (legal) {
                    v[r] = j;
                    placeQueens(v, r + 1);
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        n_ = n;
        vector<int> v(n_, 0);
        placeQueens(v, 0);
        return answer;
    }
private:
    vector<vector<string>> answer;
    int n_ = 4;
};

int main() {
  
  
  return 0;  
}
