class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            if (i % 10 == nums[i])
                return i;
        }
        return -1;
    }
};

int main() {
  
  
  return 0;  
}
