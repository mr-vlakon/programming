class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for (const auto &e: matrix) {
            unordered_set<int> us(e.cbegin(), e.cend());
            if (us.size() != matrix.size())
                return false;
        }
        vector<vector<int>> transponse(matrix.size());
        for (const auto &e: matrix) {
            int i = 0;
            for (const auto &p : e) {
                transponse[i].push_back(p);
                ++i;
            }
        }
        for (const auto &e: transponse) {
            unordered_set<int> us(e.cbegin(), e.cend());
            if (us.size() != transponse.size())
                return false;
        }
        
        
        return true;
    }
};

int main() {
  
  
  return 0;  
}
