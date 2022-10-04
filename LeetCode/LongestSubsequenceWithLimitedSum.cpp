class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int cnt = 0;
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        for (decltype(queries.size()) i = 0; i != queries.size(); ++i) {
            int res = 0;
            if (sum <= queries[i]) {
                result.push_back(nums.size());
                continue;
            }
            for (decltype(nums.size()) j = 0; j != nums.size(); ++j) {
                    res += nums[j];
                    if (res > queries[i]) {
                        result.push_back(cnt);
                        break;
                    }
                    ++cnt;
            }
            cnt = 0;
            
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}
