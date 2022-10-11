class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n) {
            int tmp = n % 10;
            sum += tmp;
            product *= tmp;
            n /= 10;
        }
        return product - sum;
    }
};

int main() {
  
  
  return 0;  
}
