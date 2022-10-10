class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        int i = 1;
        while (i <= n) {            
            if (n % i == 0) {
                ++cnt;
            }
            if (cnt > 3)
                return false;

            ++i;
        }
        return cnt == 3;
    }
};

int main() {
  
  
  return 0;  
}
