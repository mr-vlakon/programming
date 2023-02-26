class Solution {
public:
    bool isPalindrome(const string &str) {
        for (int i = 0; i < str.size() / 2; ++i) {
            if (str[i] != str[str.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void generate(const string &s, int i, vector<string> &v, string &str, int cnt = 0) {
        if (i == s.size()) {
            if (cnt == s.size()) {
                result.push_back(v);
            }
            return;
        }
        if (i > s.size()) {
            return;
        }
        if (str.size() == 0) {
            str.push_back(s[i]);
            v.push_back(str);
            string empty;
            generate(s, i + 1, v, empty, cnt + str.size());
            v.pop_back();
            generate(s, i + 1, v, str, cnt);           
        } else {
            if(str[0] == s[i]) {
                str.push_back(s[i]);
                if (isPalindrome(str)) {
                    v.push_back(str);
                    string empty;
                    generate(s, i + 1, v, empty, cnt + str.size());  
                    v.pop_back();
                    generate(s, i + 1, v, str, cnt);
                } else {
                    generate(s, i + 1, v, str, cnt);
                }     
            } else {
                str.push_back(s[i]);
                generate(s, i + 1, v, str, cnt);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> empty;
        string str;
        generate(s, 0, empty, str, 0);
        return result;
    }
private:
    vector<vector<string>> result;
};

int main() {
  
  
  
  return 0;  
}
