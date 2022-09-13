class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double k = 0.0;
        int cnt = count_if(coordinates.cbegin(), coordinates.cend(), 
                           [=](const vector<int> &v) {
          return v[0] == coordinates[0][0];  
        }); 
        if (cnt == coordinates.size()) return true;
        if ((coordinates[0][0] - coordinates[1][0]) == 0) {
            if (coordinates[1][0] != 0) 
                k = static_cast<double>(coordinates[0][1]) 
                   / static_cast<double>(coordinates[1][0]);
        }
        else {
            k = static_cast<double>(coordinates[0][1] - coordinates[1][1]) /
                static_cast<double>(coordinates[0][0] - coordinates[1][0]);
        }
        
        double b = static_cast<double>((static_cast<double>(coordinates[0][1]) - 
                                        k * static_cast<double>(coordinates[0][0])));
        for (const auto &e: coordinates) {
            if (static_cast<double>(e[1]) != (k * static_cast<double>(e[0]) + b)) {
                return false;
            }
        }   
        return true;
    }
};

int main() {
  
  
  return 0;  
}
