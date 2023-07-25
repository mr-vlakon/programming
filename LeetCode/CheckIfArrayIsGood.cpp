class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> v(nums.size() - 1, 0); 
        for (const auto &e: nums) {
            if ((e - 1) >= v.size()) {
                return false;
            }
            ++v[e - 1];
        }
        for (int i = 0; i < static_cast<int>(v.size()) - 1; ++i) {
            if (v[i] != 1) return false;
        }
        if (v.back() != 2) return false;
        return true;
    }
};

int main() {


  return 0;
}
