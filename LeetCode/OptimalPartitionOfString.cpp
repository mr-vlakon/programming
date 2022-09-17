class Solution {
public:
    bool uniqueCharacters(const string &str) {
        int checker = 0;
        for (int i = 0; i < str.length(); i++) {
            int bitAtIndex = str[i] - 'a';
            if ((checker & (1 << bitAtIndex)) > 0) {
                return false;
            }
            checker = checker | (1 << bitAtIndex);
        }
        return true;
    }
    int partitionString(string s) {
        string tmp;
        int cnt = 0;
        for (decltype(s.size()) i = 0; i != s.size(); ++i) {
            tmp += s[i];
            if (!uniqueCharacters(tmp)) {
                ++cnt;
                tmp = s[i];
            }
        }
        if (uniqueCharacters(tmp))
            ++cnt;
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}
