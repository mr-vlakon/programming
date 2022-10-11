class Solution {
public:
    int totalMoney(int n) {
        int start = 0;
        int i = 1;
        int sum = 0;
        int k = 1;
        while (i <= n) {
            sum += k + start;
            if (k % 7 == 0) {
                k = 1;
                ++start;
            } else
                ++k;
            ++i;
        }
        return sum;
    }
};

int main() {
  
  return 0;  
}
