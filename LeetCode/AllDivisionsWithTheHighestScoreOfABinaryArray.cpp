class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int cnt1 = count(nums.cbegin(), nums.cend(), 1);
        int cnt0 = 0;
        vector<int> answer;
        unordered_map<int, int> um;
        int max = 0;
        um[0] = cnt1;
        if ((cnt0 + cnt1) > max) {
            max = cnt0 + cnt1;
        }
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == 0) {
                ++cnt0;
            } else {
                --cnt1;
            }
            if ((cnt0 + cnt1) > max) {
                max = cnt0 + cnt1;
            }
            um[i + 1] = (cnt0 + cnt1);
        }
        if ((cnt0 + cnt1) > max) {
            max = cnt0 + cnt1;
        }
        for (const auto &e: um) {
            if (e.second == max) {
                answer.push_back(e.first);
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
