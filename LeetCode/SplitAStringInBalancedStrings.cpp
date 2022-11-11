class Solution {
public:
    int balancedStringSplit(string s) {
        int answer = 0;
        int cntL = 0;
        int cntR = 0;
        for (const auto &e: s) {
            (e == 'L') ? ++cntL : ++cntR;
            if (cntL == cntR) {
                cntL = 0;
                cntR = 0;
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
