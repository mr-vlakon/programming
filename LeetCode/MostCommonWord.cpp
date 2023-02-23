class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> us;
        for (const auto &e: banned) {
            us.insert(e);
        }
        string s;
        unordered_map<string, int> um;
        string tmp;
        for (int i = 0; i != paragraph.size(); ++i) { 
            if (!ispunct(paragraph[i]) && paragraph[i] != ' ') {
                tmp.push_back(tolower(paragraph[i]));
            } else {   
                if (tmp.size() != 0 && us.find(tmp) == us.end()) {
                    um[tmp]++;
                }
                tmp.resize(0);
            }
        }
        if (tmp.size() != 0 && us.find(tmp) == us.end()) {
            um[tmp]++;
        }
        int max = 0;
        for (const auto &e: um) {
            if (e.second > max) {
                max = e.second;
            }
        }
        for (const auto &e: um) {
            if (e.second == max) {
                return e.first;
            }
        }
        return "";
    }
};

int main() {
  
  
  return 0;  
}
