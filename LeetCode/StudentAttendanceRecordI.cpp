class Solution {
public:
    bool checkRecord(string s) {
        int cntL = 0;
        int cntA = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == 'A') {
                ++cntA;
            }
            if (s[i] == 'L') {
                ++cntL;
            } else {
                if (cntL >= 3) {
                    return false;
                }
                cntL = 0;
            }           
        }
        return (cntA < 2) && (cntL < 3);
    }
};

int main() {
  
  
  return 0;  
}
