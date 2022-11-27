class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> answer;
        multiset<int> ms;
        for (int i = 0; i != k; ++i) {
            ms.insert(nums[i]);
        }
        answer.push_back(*(--ms.cend()));    
        for (int i = 1; i <= nums.size() - k; ++i) {
            auto it = ms.find(nums[i - 1]);
            ms.erase(it);
            ms.insert(nums[i + k - 1]);
            answer.push_back(*(--ms.cend()));    
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;   
}
