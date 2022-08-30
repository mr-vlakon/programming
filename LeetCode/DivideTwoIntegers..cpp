class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        return (divisor == 0) ? 0 : (dividend / divisor);
    }
};

int main() {
  return 0; 
}
