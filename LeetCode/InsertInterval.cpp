class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = find_if(intervals.begin(), intervals.end(), [&](const vector<int> &x) {
            return x[0] > newInterval[0]; 
        });
        
        intervals.insert(it, newInterval);
        vector<vector<int>> result;
        int first = intervals[0][0];
        int second = intervals[0][1];
        for (int i = 1; i != intervals.size(); ++i) {
            if (second >= intervals[i][0]) {
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
