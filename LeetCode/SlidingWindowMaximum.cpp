class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> answer;
        set<int> s;
        for (int i = 0; i != k; ++i) {
            ++um[nums[i]];
            s.insert(nums[i]);
        }
        answer.push_back(*(--s.cend()));    
        for (int i = 1; i <= nums.size() - k; ++i) {
            if (um[nums[i - 1]] == 1 && (nums[i - 1] != nums[i + k - 1])) {
                auto it = s.find(nums[i - 1]);
                um.erase(nums[i - 1]);
                s.erase(it);
                auto iter = um.find(nums[i + k - 1]);
                if (iter == um.cend()) {
                    s.insert(nums[i + k - 1]);
                    ++um[nums[i + k - 1]];
                } else {
                    ++um[nums[i + k - 1]];
                }
            } else if (um[nums[i - 1]] > 1) {
                --um[nums[i - 1]];
                if (nums[i - 1] == nums[i + k - 1]) {
                    
                } else if (nums[i - 1] != nums[i + k - 1]) {
                    auto it = um.find(nums[i + k - 1]);
                    if (it == um.cend()) {
                        s.insert(nums[i + k - 1]);
                        ++um[nums[i + k - 1]];
                    } else {
                        ++um[nums[i + k - 1]];
                    }
                } 
            }
            answer.push_back(*(--s.cend()));    
        }
        return answer;
    }
private:
    unordered_map<int, int> um;
};

int main() {
  
  
  
  return 0;   
}
