class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        long long sumRight = accumulate(nums.cbegin(), nums.cend(), 0LL);
        long long sumLeft = 0;
        vector<int> answer;
        for (int i = 0; i != nums.size(); ++i) {
            sumRight -= nums[i];
            answer.push_back(abs(sumRight - sumLeft));
            sumLeft += nums[i];
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
