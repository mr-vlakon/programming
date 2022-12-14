class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int> tmp;
        tmp.push(nums[0]);
        int j = 0;
        for (int i = 1; i != nums.size(); ++i) {
            if ((nums[i] != tmp.top()) || (j % 2 == 1)) { 
                tmp.push(nums[i]);
                ++j;
            }
        }
        return nums.size() - ((tmp.size() % 2 == 0) ? tmp.size() : (tmp.size() - 1));
    }
};

int main() {
  
  
  return 0;  
}
