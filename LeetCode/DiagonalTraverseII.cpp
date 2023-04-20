class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int, int>> answer;
        int size = nums.size();
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = 0; j != nums[i].size(); ++j) {
                answer.push_back({i + j, size - i});    
            }
        }
        sort(answer.begin(), answer.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.second < rhs.second;
        });
        stable_sort(answer.begin(), answer.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        vector<int> ans;
        for (const auto &e: answer) {
            ans.push_back(nums[size - e.second][e.second + e.first - size]);
        }
        return ans;
    }
};

int main() {
  
  
  
  return 0;  
}
