class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int x = target;
        int cnt = 0;
        while(x != 1) {
            if (maxDoubles == 0) {
                return cnt + x - 1;
            }
            if (x % 2 == 0 && maxDoubles) {
                x /= 2;
                --maxDoubles;
            } else
                x -= 1;
            ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  return 0; 
}
