class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, size_t> ums;
        unordered_map<char, size_t> umt;
        for (const auto &e: s) {
            ++ums[e];
        }
        
        for (const auto &e: t) {
            ++umt[e];
        }
        
        int ans = 0;
        int ansX = 0;
        for (const auto &e: umt) {
            if (e.second < ums[e.first]) {
                ans += ums[e.first] - e.second;
            }
            if (e.second > ums[e.first]) {
                ansX += e.second - ums[e.first];
            }

        }        
        return ansX > ans ? ansX : ans;
    }
};

int main() {

  
  
  return 0;  
}
