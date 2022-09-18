class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cnt = 1;
        int max = 1;
        string res;
        char prev = s[0];
        res += s[0];
        for (decltype(s.size()) i = 1; i != s.size(); ++i) {
            res += s[i];
            if (s[i] - prev == 1) {
                ++cnt;
            } else {
                if (cnt > max)
                    max = cnt;
                res = s[i];
                cnt = 1;
                if (max == 26)
                    return 26;
            }
            prev = s[i];
        }
        if (cnt > max)
            max = cnt;
        return max;
    }
};

int main() {
  
  
  
  return 0;
}
