class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> us(nums.cbegin(), nums.cend());
        for (const auto &e: nums) {
            string s = to_string(e);
            reverse(s.begin(), s.end());
            us.insert(stoi(s));
        }
        return us.size();
    }
};

int main() {
  
  
  return 0;  
}
