class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v;
        string tmp1;
        string tmp2;
        for (int i = 0; i != nums.size(); ++i) {
            tmp1.resize(0);
            tmp2 = to_string(nums[i]);
            for (const auto &e: tmp2) {
                tmp1.push_back(mapping[e - '0'] + '0');
            }
            v.push_back({nums[i], stoi(tmp1)});
        }
        stable_sort(v.begin(), v.end(), [] (const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second < rhs.second;
        });
        vector<int> answer;
        for (const auto &e: v) {
            answer.push_back(e.first);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
