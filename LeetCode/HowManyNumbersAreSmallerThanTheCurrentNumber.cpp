class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        int index = 0;
        for (const auto &e: nums) {
            auto cnt1 = count_if(nums.cbegin() + index + 1, nums.cend(),[=](const int &x)             {
                return e > x;  
            });
            auto cnt2 = count_if(nums.cbegin(), nums.cbegin() + index + 1,[=](const int &x)             {
                return e > x;  
            });

            result.push_back(cnt1 + cnt2);
            ++index;
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}
