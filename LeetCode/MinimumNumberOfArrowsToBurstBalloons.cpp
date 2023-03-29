class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [] (vector<int> &lhs, vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        int cnt = 0;
        int tmp = points[0][1];
        for (int i = 1; i != points.size(); ++i) {
            if (tmp < points[i][0]) {
                ++cnt;
                tmp = points[i][1];
            }
            tmp = min(tmp, points[i][1]);
        }
        ++cnt;
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}
