class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) return false;
        string tmp;
        string str;
        for (int i = 0; i != s.size() - 1; ++i) {
            tmp.push_back(s[i]);
            if ((s.size() % tmp.size()) == 0) {
                str = tmp;
                while (str.size() < s.size()) {
                    str += tmp;
                }
                if (str == s) {
                    return true;
                }
                str.resize(0);
            }
        }
        return false;
    }
};

int main() {
  
  
  return 0;  
}
