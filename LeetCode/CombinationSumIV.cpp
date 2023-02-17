class Solution {
public:
    int recursive(int &target, const vector<int> &num) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        auto it = memo.find(target);
        if (it != memo.cend()) {
            return memo[target];
        }
        for (const auto &e: num) {
            int remainder = target - e;
            memo[target] += recursive(remainder, num);
        }
        return memo[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        return recursive(target, nums);
    }
private:
    unordered_map<int, int> memo;
};

int main() {
  
  
  return 0;  
}
