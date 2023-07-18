class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> um;
        for (const auto &e: nums) ++um[e];
        int dom = 0;
        for (const auto &e: um) {
            if ((2*e.second) > nums.size()) {
                dom = e.first;
                break;
            }
        }
        int count = 0;
        int gen = um[dom];
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == dom) {
                --gen;
                ++count;
            }
            if ((count * 2) > (i + 1) && (gen * 2) > (nums.size() - i - 1)) {
                return i;
            }   
        }
        return -1;
    }
};

int main() {



  return 0;
}
