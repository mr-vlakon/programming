class Solution {
public:
    void placeQueens(vector<int> &v, int r, const int & n) {
        if (r == n) {
            vector<string> tmp(v.size(), string(n, '.'));
            int i = 0;
            for (const auto &e: v) {
                tmp[i][e] = 'Q';
                ++i;
            }
            answer.push_back(tmp);
            return;
        } else {
            for (int j = 0; j != n; ++j) {
                bool legal = true;
                for (int i = 0; i != r; ++i) {
                    if (v[i] == j || v[i] == (j + r - i) || v[i] == (j - r + i)) {
                        legal = false;
                    }
                }
                if (legal) {
                    v[r] = j;
                    placeQueens(v, r + 1, n);
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> v(n, 0);
        int r = 0;
        placeQueens(v, r, n);
        return answer;
    }
private:
    vector<vector<string>> answer;
};

int main() {
  
  
  return 0;  
}
