class Solution {
public:
    string maskPII(string s) {
        auto pos = s.find('@', 0);
        string ans;
        if (pos != string::npos) {
            ans.push_back(tolower(s[0]));
            ans += "*****";
            bool status = false;
            for (int i = 0; i != s.size(); ++i) {
                if (s[i] == '@') {
                    status = true;
                    ans.push_back(tolower(s[i - 1]));
                    ans.push_back(s[i]);
                } else if (status) {
                    ans.push_back(tolower(s[i]));
                }
            }
        } else {
            string str(4, ' ');
            int counter = 0;
            int pos = str.size() - 1;
            int cnt = 0;
            for (int i = s.size() - 1; i >= 0; --i) {
                    if (isdigit(s[i]) && counter < 4) {
                        str[pos] = s[i];
                        --pos;
                        ++counter;
                        ++cnt;
                    } else if (isdigit(s[i])) {
                        ++cnt;
                    }
            }
            int diff = cnt - 10;
            if (diff == 0) {
                ans = "***-***-" + str;
            } else if (diff == 1) {
                ans = "+*-***-***-" + str;
            } else if (diff == 2) {
                ans = "+**-***-***-" + str;
            } else {
                ans = "+***-***-***-" + str;
            }
        }
        return ans;
    }
};

int main() {
  
  
  
  return 0;  
}
