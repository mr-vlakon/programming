class Solution {
public:
    int sumBase(int n, int k) {
        int result = 0;
        while(n) {
            int tmp = n % k;
            result += tmp;
            n /= k;
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}
