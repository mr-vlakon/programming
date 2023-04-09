class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<pair<int, int>>> L(s1.size() + 1, vector<pair<int, int>>(s2.size() + 1, {0, 0}));
        for (int i = 1; i != L.size(); ++i) {
            for (int j = 1; j != L[0].size(); ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    L[i][j].first = 1 + L[i - 1][j - 1].first;
                    L[i][j].second = s1[i - 1] + L[i - 1][j - 1].second;
                } else {
                    L[i][j].first = max(L[i - 1][j].first, L[i][j - 1].first);
                    L[i][j].second = max(L[i - 1][j].second, L[i][j - 1].second);
                }
            }
        }
        int first = 0;
        int second = 0;
        for (const auto &e: s1) {
            first += e;
        }
        for (const auto &e: s2) {
            second += e;
        }
        return first - 2*L[L.size() - 1][L[0].size() - 1].second + second;
    }
};

int main() {
  
  
  
  
  return 0;  
}
