class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long sum = accumulate(nums.cbegin(), nums.cend(), 0LL);
        int tmp = 0;
        vector<int> answer;
        for (const auto &e: nums) {
            if (tmp > sum) {
                return answer;
            }
            answer.push_back(e);
            tmp += e;
            sum -= e;
        }
        
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
