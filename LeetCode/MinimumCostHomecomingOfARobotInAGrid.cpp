class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sizeOfDp =  abs(homePos[0] - startPos[0]) + 1;
        int sizeOfVec =  abs(homePos[1] - startPos[1]) + 1;
        int cost = 0;
        
        if (startPos[0] <= homePos[0] && startPos[1] <= homePos[1]) {
            for (int i = 1; i < sizeOfVec; ++i) {
                cost += colCosts[startPos[1] + i];
            }
            for (int j = 1; j < sizeOfDp; ++j) {
                cost += rowCosts[startPos[0] + j];
            }
            return cost;
        } else if (startPos[0] > homePos[0] && startPos[1] <= homePos[1]) {
            for (int i = 1; i < sizeOfVec; ++i) {
                cost += colCosts[startPos[1] + i];
            }            
            for (int j = 1; j < sizeOfDp; ++j) {
                cost += rowCosts[startPos[0] - j];
            }
            return cost;
        } else if (startPos[0] >= homePos[0] && startPos[1] > homePos[1]) {
            for (int i = sizeOfVec - 2, k = 1; i >= 0 && k <= startPos[1]; --i, ++k) {
                cost += colCosts[startPos[1] - k];
            }
            for (int j = sizeOfDp - 2, k = 1; j >=  0 && k <= startPos[0]; --j, ++k) {
                cost += rowCosts[startPos[0] - k];
            }
            return cost;
        } else if (startPos[0] < homePos[0] && startPos[1] > homePos[1]) {
            for (int i = sizeOfVec - 2, k = 1; i >= 0 && k <= startPos[1]; --i, ++k) {
                cost += colCosts[startPos[1] - k];
            }
            for (int j = 1; j < sizeOfDp; ++j) {
                cost += rowCosts[startPos[0] + j];
            }
            return cost;
        }
        return 0;   
    }
};

int main() {
  
  
  
  return 0;  
}
