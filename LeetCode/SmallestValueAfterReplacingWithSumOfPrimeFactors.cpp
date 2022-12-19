class Solution {
public:
    int smallestValue(int n) {
        int prev = n;
        while (n >= 2) {
            int tmp = 2;
            int x = n;
            int sum = 0;
            int cnt = 0;
            while (x > 1) {
                if (x % tmp == 0) {
                    x = x / tmp;
                    sum += tmp;
                    ++cnt;
                } else {
                    ++tmp;
                }
            }
            if (cnt > 1) {
                n = sum;
            } else {
                n = sum;
                break;
            }
            if (prev == n)
                break;
           prev = n;
        }
        return n;
    }
};

int main() {
  
  
  
  
  return 0;  
}
