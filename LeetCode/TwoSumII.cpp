class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (decltype(numbers.size()) i = 0; i != numbers.size() - 1; i++) {
            auto it = lower_bound(numbers.cbegin() + i + 1, numbers.cend(), target - numbers[i]);
            if (it != numbers.cend() && (*it == (target - numbers[i]) )) {
                return {static_cast<int>(i + 1), static_cast<int>(it - numbers.cbegin() + 1)};
            }
                
        }
        return {0,0};
    }
};

int main() {
  
  
  return 0;  
}
