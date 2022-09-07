class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto min = min_element(nums.cbegin(), nums.cend());
        auto max = max_element(nums.cbegin(), nums.cend());
        if (min > max) {
            swap(min, max);
        }
        
        size_t first_scenario = 0;
        size_t second_scenario = 0;
        size_t third_scenario = 0;
                                
        first_scenario = max - nums.cbegin() + 1;
        second_scenario = nums.cend() - min;
        third_scenario = (nums.cend() - max) + (min - nums.cbegin() + 1);
        
        auto min_ = std::min(first_scenario, second_scenario);
        min_ = std::min(min_, third_scenario);
        return min_;
    }
};

int main() {
  
  
  return 0;  
}
