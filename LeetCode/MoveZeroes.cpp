class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      stable_partition(nums.begin(), nums.end(),[](const int &x) {
         return x != 0; 
      });
    }
};

int main() {
 
  
  return 0;
}
