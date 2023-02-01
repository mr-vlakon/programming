class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> us;
        int j = 0;
        while (j != n) {
            us.insert(j);
            ++j;
        }
        for (const auto &e: edges) {
            us.erase(e[1]);
        }
        return {us.cbegin(), us.cend()};
    }
};

int main() {
  
  
  return 0;  
}
