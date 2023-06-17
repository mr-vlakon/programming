class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int maxE = *max_element(nums.cbegin(), nums.cend());
        vector<vector<int>> v(nums.size(), vector<int>(maxE, 0));
        vector<int> tmp(maxE, 0);
        for (int i = 0; i != nums.size(); ++i) {
            ++tmp[nums[i] - 1];
            v[i] = tmp;
        }
        vector<int> answer;
        int take = -1;
        int ans = 101;
        for (int i = 0; i != queries.size(); ++i) {
            take = -1;
            ans = 101;
            for (int j = 0; j != tmp.size(); ++j) {
                if ((v[queries[i][1]][j] - ((queries[i][0] == 0) ? 0: v[queries[i][0] - 1][j])) != 0) {
                    if (take != -1) {
                        ans = min(ans, j - take);
                    }
                    take = j;       
                }
            }
            answer.push_back((ans == 101) ? -1 : ans);
        }
        return answer;
    }
};

int main() {

  return 0;
}
