class Solution {
public:
    string generate(const vector<string> &nums, int i, string &s) {
        if (i == nums.size()) {
            if (s.size() == n_) {
                if (us.find(s) == us.end()) {
                    return s;
                }
            }
        }
        if (i > nums.size()) {
            return "";
        }
        s.push_back('0');
        string s1;
        s1 = generate(nums, i + 1, s);
        if (s1.size() != 0) {
            return s1;
        }
        s.pop_back();
        s.push_back('1');
        s1 = generate(nums, i + 1, s);
        s.pop_back();
        if (s1.size() != 0) {
            return s1;
        }
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n_ = nums[0].size();
        for (const auto &e: nums) {
            us.insert(e);
        }
        string str;
        return generate(nums, 0, str);
    }
private:
    unordered_set<string> us;
    int n_ = 0;
};

int main() {
  
  
  return 0;  
}
