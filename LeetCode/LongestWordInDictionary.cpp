class Solution {
public:
    void construct(string &s, const string &str) {
        s.pop_back();
        if (s.size() == 0) return;
        if (us.find(s) == us.cend()) {
            status = false;
            return;
        }
        construct(s, str);
    }
    string longestWord(vector<string>& words) {
        for (const auto &e: words) {
            us.insert(e);
        }
        string tmp;
        vector<string> answer;
        for (const auto &e: words) {
            status = true;
            tmp = e;
            construct(tmp, e);
            if (status) {
                if (e.size() >= ans.size()) {
                    if (e.size() == ans.size()) {
                        if (ans > e) {
                            ans = e;
                        }
                    } else {
                        ans = e;
                    }
                }
            }
        }
        return ans;
  }
private:
    string ans;
    bool status = false;
    unordered_set<string> us;
};

int main() {
  
  
  
  return 0;  
}
