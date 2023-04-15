class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> answer{nums[0]*2};
        int maxV = nums[0];
        long long sum = 2*nums[0];
        for (int i = 1; i != nums.size(); ++i) {
            maxV = max(nums[i], maxV);
            sum += maxV + nums[i];
            answer.push_back(sum);
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
