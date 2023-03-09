class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int s = 31;
        int answer = 0;
        while (s >= 0) {
            if ( ((1 << s) & left) == ((1 << s) & right) ) {
                answer += (1 << s) & left;
            } else {
                break;
            }
            --s;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
