class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        for (const auto &e: items) {
            if (ruleKey == "type" && ruleValue == e[0]) {
                ++cnt;
            } else if (ruleKey == "color" && ruleValue == e[1]) {
                ++cnt;
            } else if (ruleKey == "name" && ruleValue == e[2]) {
                ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
