class Solution {
public:
    void generate(const string &s, int i, string &str, int len, int x, string &curr) {
        if (i == s.size() && x == 3) {
            result.push_back(str);
            return;
        }
        if (i > s.size()) {
            return;
        }
        curr.push_back(s[i]);
        str.push_back(s[i]);
        if (len < 3) {
            if ((stoi(curr) <= 255 && curr.size() >= 1 && curr[0] != '0') || (curr.size() == 1 &&
            curr[0] == '0')) {
                if ((i + 1) <= s.size() && (len + 1) <= 3)
                    generate(s, i + 1, str, len + 1, x, curr);
            }
        }
        str.pop_back();
        if (str.size() != 0) {
            str.push_back('.');
            str.push_back(s[i]);
            if (x < 4) {
                curr.resize(0);
                curr.push_back(s[i]);
                if ((x + 1) <= 3 && (i + 1) <= s.size())
                    generate(s, i + 1, str, 1, x + 1, curr);
            }
            str.pop_back();
            str.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string initial;
        string current;
        generate(s, 0, initial, 0, 0, current);
        return result;
    }
private:
    vector<string> result;
};

int main() {
  
  
  
  return 0;  
}
