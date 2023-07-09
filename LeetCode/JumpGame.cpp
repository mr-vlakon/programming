class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int i = 0; i != nums.size() - 1; ++i) {
            if (i <= reachable)
                reachable = max(reachable, nums[i] + i);
            else
                return false;
        }
        return reachable >= (nums.size() - 1);
    }
};

int main() {



  return 0;
}
