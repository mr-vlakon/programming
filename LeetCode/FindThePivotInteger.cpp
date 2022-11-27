class Solution {
public:
    int pivotInteger(int n) {
        int i = 1;
        while (i <= n) {
            int x = 1;
            int k = i;
            int tmp = 0;
            while (x <= k) {
                tmp += x;
                ++x;
            }
            k = i;
            int tmp2 = 0;
            while (k <= n) {
                tmp2 += k;
                ++k;
            }
            if (tmp == tmp2) {
                return i;
            }
            
            ++i;
            
        }
        return -1;
    }
};

int main() {
  
  
  
  return 0;  
}
