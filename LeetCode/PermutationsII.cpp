class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        sort(result.begin(), result.end());
        auto p = unique(result.begin(), result.end());
        result.erase(p, result.end());
        return result;    
    }
};

int main() {
  
  return 0;  
}
