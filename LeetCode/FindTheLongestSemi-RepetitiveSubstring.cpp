class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int answer = 0;
        char prev = 'x';
        int tmp = 0;
        int t = 0;
        char pr;
        for (int i = 0; i != s.size(); ++i) {
            t = 0;
            pr = 'x';
            if (prev == s[i]) {
                ++tmp;
            } 
            prev = s[i];
            for (int j = 0; j <= i; ++j) {
                if (pr == s[j]) {
                    ++t;
                } 
                pr = s[j];
                if ((tmp - t) <= 1) {
                    answer = max(answer, i - j + 1);
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
