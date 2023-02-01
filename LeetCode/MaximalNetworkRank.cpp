class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> um;
        for (const auto &e: roads) {
            um[e[0]]++;
            um[e[1]]++;
        }
        unordered_map<int, unordered_set<int>> unorm;
        for (const auto &e: roads) {
            unorm[e[0]].insert(e[1]);
            unorm[e[1]].insert(e[0]);
        }
        int max = 0;
        for (int i = 0; i < (n - 1); ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto it = unorm[i].find(j);
                if (it != unorm[i].cend()) {
                    if ((um[i] + um[j] - 1) > max) {
                        max = um[i] + um[j] - 1;
                    }
                } else {
                    if ((um[i] + um[j]) > max) {
                        max = um[i] + um[j];
                    }
                } 
            }
        } 
        return max;
    }
};

int main() {
  
  
  
  return 0;  
}
