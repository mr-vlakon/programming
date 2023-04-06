class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs[1] > rhs[1];
        });
        stable_sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        int rem = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i != intervals.size(); ++i) {
            if (start <= intervals[i][0] && end >= intervals[i][1]) {
                ++rem;
            }
            start = min(intervals[i][0], start);
            end = max(intervals[i][1], end);
        }
        return intervals.size() - rem;
    }
};

int main() {
  
  
  
  return 0;  
}
