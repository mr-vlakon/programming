class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int cnt = 0;
        while(ans) {
            int tmp = ans % 2;
            if (tmp)
                ++cnt;
            ans /= 2;
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
