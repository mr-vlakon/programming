class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto cnt = k / nums.size();
        if (cnt == 0) {
            std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
        } else {
            auto md = k % nums.size();
            std::rotate(nums.rbegin(), nums.rbegin() + md, nums.rend());     
        }    
    }
};

int main() {
  
  return 0;
}
