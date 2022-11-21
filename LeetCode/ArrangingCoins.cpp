class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int answer = 0;
        while (n > 0) {
            if (i <= n)
                ++answer;
            n -= i;
            ++i;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
