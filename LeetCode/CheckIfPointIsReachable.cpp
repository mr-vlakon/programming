class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int gcd_ = gcd(targetX, targetY);
        return ((gcd_ & (gcd_ - 1)) == 0);
    }
};

int main() {
  
  
  return 0;  
}
