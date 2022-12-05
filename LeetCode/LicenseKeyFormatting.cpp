class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string answer;
        int cnt = 0;
        int q = 0;
        int number = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] != '-') {
                ++number;
            }
        }
        reverse(s.begin(), s.end());
        auto pos = s.find_first_not_of('-');
        if (pos == string::npos) return "";
        s.erase(s.cbegin(), s.cbegin() + pos);
        reverse(s.begin(), s.end());
        int x = number % k;
        if (x == 0) {
            x = k;
        }
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] != '-') {
                ++cnt;
                answer.push_back(toupper(s[i]));
            }                 
            if (q == 0 && cnt == x) {
                if (i != s.size() - 1) {
                    answer.push_back('-');
                }
                cnt = 0;
                q = 1;
            }
            if (cnt == k && q != 0) {
                if (i != s.size() - 1) {
                    answer.push_back('-');
                }
                cnt = 0;
            }
        }
        return answer;
    }
};

int main() {
  
  

  return 0;
}
