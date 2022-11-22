class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<string> v(strs[0].size());
        for(int i = 0; i != strs.size(); ++i) {
            for (int j = 0; j != strs[i].size(); ++j) {
                v[j].push_back(strs[i][j]);
            }
        }
        
        int cnt = 0;
        for (const auto &e: v) {
            if (!is_sorted(e.begin(), e.end()))
                ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
