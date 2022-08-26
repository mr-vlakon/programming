class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto n = remove(nums.begin(),nums.end(), val);
        nums.erase(n, nums.end());
        return nums.size();
    }
};

int main() {
  
  return 0; 
}
