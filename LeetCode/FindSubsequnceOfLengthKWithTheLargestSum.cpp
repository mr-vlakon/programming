class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> answer;
        for (int i = 0; i != nums.size(); ++i) {
            answer.push_back({nums[i], i});
        }
        sort(answer.begin(), answer.end(), [=] (const pair<int,int> &lhs, const pair<int,int> &rhs) {
            return lhs.first > rhs.first;
        });
        int i = 0;
        vector<pair<int,int> > result;
        while(i != k) {
            result.push_back({answer[i].first, answer[i].second});
            ++i;
        }
        sort(result.begin(), result.end(), [=](const pair<int, int> &lhs,
                                              const pair<int, int> &rhs) {
            return lhs.second < rhs.second;
        });
        
        vector<int> res;
        for (const auto &e: result) {
            res.push_back(e.first);
        }
        
        return res;
    }
};

int main() {
  
  
  return 0;  
}
