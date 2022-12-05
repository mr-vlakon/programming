class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        string tmp = to_string(nums[0]);
        vector<string> v;
        vector<long long> num(nums.cbegin(), nums.cend());
        for (int i = 1; i != num.size(); ++i) {
            if (num[i] - num[i - 1] == 1) {
            } else {
                if (tmp != to_string(num[i - 1]))
                    tmp += "->" + to_string(num[i - 1]);
                v.push_back(tmp);
                tmp = to_string(num[i]);
            }
        }
        if (tmp != to_string(num[num.size() - 1]))
            tmp += "->" + to_string(num[num.size() - 1]);
        v.push_back(tmp);
        return v;
    }
};

int main() {
  
  
  return 0;  
}
