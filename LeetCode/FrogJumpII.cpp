class Solution {
public:
    int maxJump(vector<int>& stones) {
        if (stones.size() == 2) return stones.back() - stones[0];
        int max1 = 0;
        for (int i = 2; i < stones.size(); ++i) {
            int tmp = stones[i] - stones[i - 2];
            if (tmp > max1) {
                max1 = tmp;
            }
        }
        int max2 = 0;
        for (int i = stones.size() - 1; i >= 2; --i) {
            int tmp = stones[i] - stones[i - 2];
            if (tmp > max2) {
                max2 = tmp;
            }
        }
        return min(max1, max2);
    }
};

int main() {
  
  
  return 0;  
}
