class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt = 0;
        while(s.find("01") != string::npos) {
            for(decltype(s.size()) i = 0; i < s.size() - 1;) {
                    if(s[i] == '0' && s[i + 1] == '1') {
                        s[i] = '1';
                        s[i + 1] = '0';
                        i += 2;
                    } else
                        ++i;
            }
            ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  return 0;  
}
