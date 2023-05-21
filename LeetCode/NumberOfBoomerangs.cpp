class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if (points.size() <= 2) return 0;
        int answer = 0;
        unordered_map<int, int> um;

        for (int i = 0; i != points.size(); ++i) {
            for (int j = 0; j != points.size(); ++j) {
                if (i != j)
                um[abs(points[i][0] - points[j][0])*abs(points[i][0] - points[j][0]) + 
                abs(points[i][1] - points[j][1])*abs(points[i][1] - points[j][1])]++;
            }
            for (const auto &e: um) {
                answer += e.second*(e.second - 1);
            }
            um.clear();
        }
        return answer;
    }
};

int main() {
  
  
  
  
  
  return 0;  
}
