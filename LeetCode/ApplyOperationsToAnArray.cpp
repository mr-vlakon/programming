class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i != nums.size() - 1; ++i) {
            if (nums[i] != nums [i + 1]) {
                continue;
            } else {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        vector<int> answer;
        for (const auto &e: nums) {
            if (e != 0)
                answer.push_back(e);
        }
        while(answer.size() != nums.size()) {
            answer.push_back(0);
        }
        
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
