class Solution {
public:
    int minimumPartition(string s, int k) {
        long long tmp = 0;
        long long cnt = 1;
        int answer = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i != s.size(); ++i) {
            tmp += (s[i] - '0') * cnt;
            if (tmp > k) {
                ++answer;
                if (cnt == 1) {
                    return -1;
                }
                if (i > 0) {
                    tmp = (s[i] - '0');
                    if (tmp > k) {
                        return -1;
                    }
                } else {
                    return -1;
                }
                cnt = 10;
            } else {
                cnt *= 10;
            }
        }
        if (tmp <= k) {
            ++answer;
        } else {
            return -1;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
