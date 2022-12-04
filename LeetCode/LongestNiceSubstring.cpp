class Solution {
public:
    string longestNiceSubstring(string s) {
        string answer;
        for (int i = 0; i != s.size(); ++i) {
            unordered_map<char, set<char>> um;
            for (int j = i; j != s.size(); ++j) {
                um[tolower(s[j])].insert(s[j]);
                bool status = true;
                for (const auto &e: um) {
                    if (e.second.size() != 2) {
                        status = false;
                        break;
                    }
                }
                if (status) {
                    string ss(s.cbegin() + i, s.cbegin() + j + 1);
                    if (ss.size() > answer.size()) {
                        answer = ss;
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
