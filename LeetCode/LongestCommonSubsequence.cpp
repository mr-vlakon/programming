class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> c(m + 1);
        for (auto &e: c) {
            e.resize(n + 1);
        }
        for (int i = 1; i <= m; ++i) {
            c[i][0] = 0;
        }
        
        for (int j = 0; j <= n; ++j) {
            c[0][j] = 0;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                } else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                } else {
                    c[i][j] = c[i][j - 1];
                }
            }
        }
        int max = 0;
        for (const auto &e: c) {
            for (const auto &p: e) {
                if (p > max)
                    max = p;
            }
        }
        
        return max;
    }
};

int main() {
  
  
  return 0;  
}
