class Solution {
public:
    int getSum(int a, int b) {
        int k = 0;
        int answer = 0;
        int perenos = 0;
        int first = 0;
        int second = 0;
        long long x = 1;
        while (x <= 2147483648) {
            first = (a & x);
            second = (b & x);
            if (first != 0 && second != 0) {
                if (perenos == 1) {
                    answer |= x;
                }
                perenos = 1;
            } else if ((first != 0 || second != 0) && perenos == 0) {
                answer |= x;
            } else if ((first == 0 && second == 0)) {
                if (perenos == 1) {
                    answer |= x;
                    perenos = 0;
                }
            }
            x <<= 1;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
