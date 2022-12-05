class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> um;
        for (int i = 0; i != order.size(); ++i) {
            um[order[i]] = i;
        }
        for (int j = 0; j != words.size() - 1; ++j) {
            for (int i = 0; i != min(words[j].size(), words[j + 1].size()); ++i) {
                if (um[words[j][i]] < um[words[j + 1][i]]) {
                    if (j == words.size() - 2)
                        return true;
                    break;
                } else if (um[words[j][i]] > um[words[j + 1][i]]) {
                    return false;
                }
            }
            if (words[j].size() > words[j + 1].size()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}
