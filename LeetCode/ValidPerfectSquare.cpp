class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        long long i = 0;
        long long res = 0;
        while (i <= (num / 2) && res < num) {
            res = i * i;
            if (res == num) {
                return true;
            }
            ++i;
        }
        return false;
    }
};

int main() {
  
  
  
  return 0;  
}
