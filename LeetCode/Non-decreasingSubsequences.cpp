class Solution {
public:
    void generate(const vector<int> &nums, int i, vector<int> &v) {
        if (i == nums.size()) {
            if (v.size() >= 2) {
                result.push_back(v);
            }
            return;
        }
        if (i > nums.size()) {
            return;
        }
        int tmp = (v.size() != 0) ? v.back() : -1000000;
        v.push_back(nums[i]);
        if (nums[i] >= tmp) {
            generate(nums, i + 1, v);
        }
        v.pop_back();
        if (tmp != nums[i]) {
            generate(nums, i + 1, v);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> empty;
        generate(nums, 0, empty);
        return result;
    }
private:
    vector<vector<int>> result;
};

int main() {
  
  
  
  return 0;  
}
