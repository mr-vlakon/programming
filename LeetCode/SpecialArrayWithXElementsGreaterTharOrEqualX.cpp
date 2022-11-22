class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int i = 0; i <= nums.size(); ++i) {
            auto cnt = count_if(nums.cbegin(), nums.cend(), [=](const int &x) {
                return x >= i;
            });
            if (cnt == i)
                return i;
        }
        return -1;
    }
};

int main() {
  
  
  
  return 0;  
}
