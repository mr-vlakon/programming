class Solution {
public:
    int countEven(int num) {
        int cnt = 0;
        int i = 2;
        while (i <= num) {
            int x = i;
            int sum = 0;
            while (x) {
                int tmp = x % 10;
                sum += tmp;
                x /= 10;
            }
            if (sum % 2 == 0)
                ++cnt;
            ++i;
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
