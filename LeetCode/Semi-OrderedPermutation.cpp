class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int answer = 0;
        int find1 = 0;
        int findN = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == 1) {
                find1 = i;
            }
            if (nums[i] == nums.size()) {
                findN = i;
            }
        }
        if (find1 > findN) {
            answer = find1 + (nums.size() - findN - 1) - 1;
        } else {
            answer = find1 + (nums.size() - findN - 1);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
