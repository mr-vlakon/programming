class Solution {
public:
    int countBinarySubstrings(string s) {
            int answer = 0;
            char prev = s[0];
            int cnt1 = 0;
            int cnt0 = 0;
            prev == '1' ? ++cnt1 : ++cnt0;
            for (int j = 1; j != s.size(); ++j) {
                if (s[j] == '1') {
                    if (prev == '1') {
                        ++cnt1;
                    } else if (prev == '0' && cnt1 != 0) {
                        answer += min(cnt0, cnt1);
                        cnt1 = 1;
                    } else {
                        ++cnt1; 
                    }
                } else {
                    if (prev == '0') {
                        ++cnt0;
                    } else if (prev == '1' && cnt0 != 0) {
                        answer += min(cnt0, cnt1);
                        cnt0 = 1;
                    } else {
                        ++cnt0;
                    }
                }
                prev = s[j];
        }    
        return answer + (cnt1 != 0 ? min(cnt0,cnt1) : 0);
    }
};

int main() {
  
  
  
  return 0;  
}
