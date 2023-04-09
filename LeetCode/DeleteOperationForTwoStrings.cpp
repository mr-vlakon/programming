class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> L(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i != L.size(); ++i) {
            for (int j = 1; j != L[0].size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    L[i][j] = 1 + L[i - 1][j - 1];
                } else {
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }
            }
        }
        return word1.size() - 2*L[L.size() - 1][L[0].size() - 1] + word2.size();
    }
};

int main() {
  
  
  
  return 0;  
}
