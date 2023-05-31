class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, long long> left;
        unordered_map<int, long long> right;
        unordered_map<int, long long> cnt;
        for (int i = 0; i != nums.size(); ++i) {
            right[nums[i]] += i;
            ++cnt[nums[i]];
        }
        vector<long long> result(nums.size(), 0);
        unordered_map<int, long long> cntL;
        for (int i = 0; i != nums.size(); ++i) {
            --cnt[nums[i]];
            right[nums[i]] -= i;
            
            result[i] = abs<long long>(left[nums[i]] - cntL[nums[i]]*i) + 
            abs<long long>((cnt[nums[i]])*i - right[nums[i]]);
            left[nums[i]] += i;
            ++cntL[nums[i]];
        }
        return result;
    }
};

int main() {
  
  
  
  
  return 0;  
}
