class Solution {
public:
    void recursive(string &s, const vector<string> &wordDict, string &str) {
        if (s.size() == 0) {
            c = str.back();
            str.pop_back();
            answer.push_back(str);
            str.push_back(c);
            return;
        }
        auto it = memo.find(s);
        if (it != memo.cend()) {
            return;
        }
        for (const auto &e: wordDict) {
            if (e.size() <= s.size()) {
                if (string(s.cbegin(), s.cbegin() + e.size()) == e) {
                    string newS = string(s.cbegin() + e.size(), s.cend());
                    memo[str];      
                    str += e + " ";               
                    recursive(newS, wordDict, str);
                    str.erase(str.cend() - e.size() - 1, str.cend());
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string empty;
        string str;
        recursive(s, wordDict, str);
        return answer;
    }
private:
    char c;
    vector<string> answer;
    unordered_map<string, bool> memo;
};

int main() {
  
  
  
  
  return 0;  
}
