class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        auto p = minmax_element(nums.cbegin(), nums.cend());
        int min = *p.first;
        int max = *p.second;
        int minE = 100000;
        for (auto &e: nums) {
            e -= min;
            minE = std::min(e, minE);
        }   
        //int m = *min_element(nums.cbegin(), nums.cend());     
        vector<int> v(max + 1 - minE, 0);
        for (int i = 0; i != nums.size(); ++i) {
            v[nums[i] - minE]++;
        }
        int answer = 0;
        for (int i = 0; i != v.size() - 1; ++i) {
            if (v[i] >= 2) {
                answer += v[i] - 1;
                v[i + 1] += v[i] - 1;
            }
        }
        answer += (v.back() * (v.back() - 1)) / 2;
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
