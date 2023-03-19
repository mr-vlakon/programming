class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int startX = points[0][0];
        int startY = points[0][1];
        int answer = 0;
        for (int i = 1; i != points.size(); ++i) {
            answer += max(abs(startX - points[i][0]), abs(startY - points[i][1]));
            startX = points[i][0];
            startY = points[i][1];
        }     
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
