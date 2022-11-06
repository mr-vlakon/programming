class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        auto sum = accumulate(nums.cbegin(), nums.cbegin() + k, 0LL);
        unordered_set<int> st(nums.cbegin(), nums.cbegin() + k);
        vector<long long> answer;
        if (st.size() == k) {
            answer.push_back(sum);
        }
        
        for (int i = 1; i <= nums.size() - k; ++i) {
            sum -= nums[i - 1];
            sum += nums[i + k - 1];
            st.erase(nums[i - 1]);
            st.insert(nums[i + k - 1]);
            if (st.size() < k) {
                st.insert(nums[i]);
            }
            if (st.size() == k) {
                answer.push_back(sum);
            }
            
        }
        if (answer.size() != 0)
            return *max_element(answer.cbegin(), answer.cend());
        else
            return 0;
    }
};

int main() {
  
  
  return 0;  
}
