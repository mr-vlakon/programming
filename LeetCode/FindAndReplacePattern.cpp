class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, int> um;
        for (const auto &e: pattern) {
            ++um[e];
        }
        vector<string> answer;
        for (const auto &e: words) {
            unordered_map<char, char> tmp;
            unordered_map<char, char> revTmp;
            bool status = true;
            for (int i = 0; i != e.size(); ++i) {
                auto it = tmp.find(e[i]);
                auto iter = revTmp.find(pattern[i]);
                if (it == tmp.cend()) {
                    tmp[e[i]] = pattern[i];
                } else {
                    if (it->second != pattern[i]) {
                        status = false;
                        break;
                    }
                }
                if (iter == revTmp.cend()) {
                    revTmp[pattern[i]] = e[i];
                } else if (iter != revTmp.cend()) {
                    if (iter->second != e[i]) {
                        status = false;
                        break;
                    }
                }
            }
            if (status) {
                answer.push_back(e);
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  
  
  return 0;  
}
