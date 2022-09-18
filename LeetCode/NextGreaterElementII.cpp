class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        auto it1 = nums.cbegin();
        auto it2 = nums.cbegin();
        vector<int> result;
        int index = 0;
        for (const auto &e : nums ) {
            it1 = find_if(nums.cbegin() + index + 1, nums.cend(),
            [&](const int &x) {return x > e;});
            it2 = find_if(nums.cbegin(), nums.cbegin() + index,
            [&](const int &x) {return x > e;});
            if ((it1 == nums.cend()) && (it2 == nums.cbegin() + index)) {
                result.push_back(-1);
            } else {
                if (it1 != nums.cend() || it2 != nums.cend()) {
                    if (it1 != nums.cend()) {
                        result.push_back(*it1);
                    } else
                        result.push_back(*it2);
                }
            }
            index++;
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}
