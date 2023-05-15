class Solution {
public:
    int minInsertions(string s) {
        int answer = 0;
        int tmpL = 0;
        int tmpR = 0;
        for (const auto &e: s) {
            if (e == '(') {
                if (tmpR != 0) {
                    answer += 1;
                    tmpR = 0;
                } else {
                    tmpL += 1;
                }
            } else if (e == ')') {
                if (tmpL == 0) {
                    ++answer;
                    tmpL++;
                }
                tmpR += 1;
            }
            if (tmpR == 2) {
                if (tmpL == 0) {
                    ++answer;
                    tmpR = 0;
                } else {
                    tmpR = 0;
                    tmpL--;
                }
            }
        }
        answer += 2*tmpL - tmpR;
        return answer;
    }
};

int main() {
  
  
  
  
  
  
  return 0;  
}
