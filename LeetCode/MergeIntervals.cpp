class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (vector<int> &lhs, vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        vector<vector<int>> result;
        int first = intervals[0][0];
        int second = intervals[0][1];
        for (int i = 1; i != intervals.size(); ++i) {
            if (second >= intervals[i][0] || second >= intervals[i][1]) {
                second = max(second, intervals[i][1]);
            } else {
                result.push_back({first, second});      
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        result.push_back({first, second});
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
