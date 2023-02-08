class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int tmp = 1;
        for (int i = 1; i != s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++tmp;
            } else {
                if (tmp >= 3) {
                    result.push_back({i - tmp, i - 1});
                }
                tmp = 1;
            }
        }
        if (tmp >= 3) {
            result.push_back({static_cast<int>(s.size()) -  tmp, static_cast<int>(s.size()) - 1});
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
