class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min = 1000000;
        int ind = 0;
        int minInd = -1;
        for (const auto &e: points) {
            if (abs(x - e[0]) + abs(y - e[1]) < min && (e[0] == x || e[1] == y)) {
                min = abs(x - e[0]) + abs(y - e[1]);
                minInd = ind;
            }    
            ++ind;
        }
        return minInd;
    }
};

int main() {

  
  return 0;  
}
