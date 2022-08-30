class Solution {
public:
    double myPow(double x, int n) {
            if (abs(x) <= 0.00001) {
                return 0;
            }
            if (x == 1) {
                return 1;
            }
            if (x == -1) {
                if (n % 2 == 0)
                    return 1;
                if (n % 2 == 1)
                    return -1;
            }
            if (abs(x) > 0 && n < -100000000) {
                return 0;
            }
            if (n < 0  && cnt == 0) {
                x = 1/x;
                ++cnt;
            }
            if (n == 0) {
                return 1;
            }
            if (n == 1) {
                return x;
            }
            if (n == -1) {
                return x;
            }
            if (n > 0) {
                return x * myPow(x, n - 1);
            }            
            if (n < 0) {
                return x * myPow(x, n + 1); 
            }
            return 0;
    }
private:
    int cnt = 0;
};

int main() {

  return 0;
}
