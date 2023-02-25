class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxV = 0;
        double a = 0.0;
        double b = 0.0;
        double c = 0.0;
        double p = 0.0;
        for (int i = 0; i != points.size() - 2; ++i) {
            for (int j = i + 1; j != points.size() - 1; ++j) {
                for (int k = j + 1; k != points.size(); ++k) {
                    a = sqrt(pow((points[i][0] - points[j][0]),2.0) 
                    + pow((points[i][1] - points[j][1]), 2.0)); 
                    b = sqrt(pow((points[i][0] - points[k][0]), 2.0)
                    + pow((points[i][1] - points[k][1]), 2.0)); 
                    c = sqrt(pow((points[j][0] - points[k][0]), 2.0) 
                    + pow((points[j][1] - points[k][1]), 2.0)); 
                    p = (a + b + c) / 2.0;
                    maxV = max<double>(maxV, sqrt(p*(p - a)*(p - b)*(p - c)));
                }
            }    
        }
        return maxV;
    }
};

int main() {
  
  
  return 0;  
}
