class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        set<vector<int>> st(points.cbegin(), points.cend());
        if (st.size() != 3) return false;
        if (points[0][0] - points[1][0] == 0 && points[1][0] - points[2][0] == 0)
            return false;
        double k1 = static_cast<double>(points[0][1] - points[1][1]) / 
            static_cast<double>(points[0][0] - points[1][0]);
        double k2 = static_cast<double>(points[1][1] - points[2][1]) / 
            static_cast<double>(points[1][0] - points[2][0]);
        return k1 != k2;  
    }
};

int main() {
  
  
  
  return 0;  
}
