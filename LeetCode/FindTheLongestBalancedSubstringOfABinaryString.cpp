class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int cnt0 = 0;
        int cnt1 = 0;
        int answer = 0;
        bool status = false;
        for (int i = 0; i != s.size() - 1; i++) {
            cnt0 = 0;
            cnt1 = 0;
            status = false;
            if (s[i] == '0') {
                cnt0 = 1;
            } else {
                continue;
            }
            for (int j = i + 1; j != s.size(); j++) {
                if (s[j] == '0' && !status) {
                    ++cnt0;
                } else if (s[j] == '1' && !status) {
                    ++cnt1;
                    status = true;
                } else if (s[j] == '1' && status) {
                    ++cnt1;
                } else if (s[j] == '0' && status) {
                    break;
                }
            }
            answer = max(answer, min(cnt0, cnt1)*2);
        }
        return answer;
    }  
};

int main() {
  
  
  
  return 0;  
}
