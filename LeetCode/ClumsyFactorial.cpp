class Solution {
public:
    int clumsy(int n) {
        int answer = 0;
        int tmp = 0;
        int sign = 1;
        while (n > 0) {
            tmp = 1;
            tmp *= n;
            --n;
            if (n > 0) {
                tmp *= n;
            } else {
                answer += sign*tmp;
                break;
            }
            --n;
            if (n > 0) {
                tmp /= n;
            } else {
                answer += sign*tmp;
                break;
            }
            answer += sign*tmp;
            sign = -1;
            --n;
            answer += n;
            --n;
        }
        return answer;
    }
};

int main() {
  
  
  
  
  
  return 0;  
}
