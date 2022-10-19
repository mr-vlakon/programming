class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> answer;
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.cend() || *it != target) return answer;
        size_t index = it - nums.cbegin();
        while (it != nums.cend()) {
            if (*it == target) {
                answer.push_back(index);
                ++index;
            } else {
                break;
            }
            ++it;
        }
        return answer;
        
    }
};

int main() {
  
  
  return 0;  
}
