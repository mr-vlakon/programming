/*
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
*/
class Solution {
public:
    int recursive(const vector<int> &num, int &target) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (memo[target] != -1) {
            return memo[target];
        }
        memo[target] = 0;
        int remainder = 0;
        for (const auto &e: num) {
            remainder = target - e;
            if (remainder >= 0)
                memo[target] += recursive(num, remainder);
        }
        return memo[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        memo.resize(target + 1, -1);
        return recursive(nums, target);
    }
private:
    vector<int> memo;
};

int main() {
  
  
  return 0;  
}
