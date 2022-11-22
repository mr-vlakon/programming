class Solution {
public:
    int maxScore(string s) {
        auto cnt1 = count(s.cbegin(), s.cend(), '1');
        int max = 0;
        int cnt0 = 0;
        for (int i = 0; i != s.size() - 1; ++i) {
            if (s[i] == '0') {
                ++cnt0;
            } else {
                --cnt1;
            }
            if (cnt0 + cnt1 > max)
                max = cnt0 + cnt1;
        }
        return max;
    }
};

int main() {
  
  
  return 0;  
}
