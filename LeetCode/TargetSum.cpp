class Solution {
public:
    int generate(const vector<int> &num, int i, int tar) {
        if (i == num.size() && tar == 0) {
            return 1;
        }  
        if (i >= num.size()) {
            return 0;
        }
        it = memo[i].find(tar);
        if (it != memo[i].cend()) {
            return memo[i][tar];
        }
        memo[i][tar] += generate(num, i + 1, tar - num[i]) + generate(num, i + 1, tar + num[i]);
        return memo[i][tar];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        target_ = target;
        memo.resize(nums.size());
        return generate(nums, 0, target);
    }
private:
    vector<unordered_map<int, int>> memo;
    unordered_map<int, int>::iterator it;
    int target_ = 0;
};
/*
class Solution {
public:
    void generate(const vector<int> &num, int i, int tar) {
        if (i == num.size()) {
            if (tar == target_) {
                ++cnt;
            }
            return;
        }
        tar += num[i];
        generate(num, i + 1, tar);
        tar -= num[i];
        tar -= num[i];
        generate(num, i + 1, tar);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        target_ = target;
        int tmp = 0;
        generate(nums, 0, tmp);
        return cnt;
    }
private:
    int target_ = 0;
    int cnt = 0;
};
*/
int main() {
  
  
  
  return 0;  
}
