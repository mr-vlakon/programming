class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> answer;
        int count = 0;
        int stepSpiral = 1;
        int countMove = 0;
        int direction = 0;
        int cnt = 0;
        while (cnt != (rows*cols)) {
            if (direction == 0) {
                while (count != stepSpiral) {
                    if ((rStart < rows) && (rStart >= 0) && (cStart < cols) && (cStart >= 0)) {
                        answer.push_back({rStart, cStart});
                        ++cnt;
                    }
                    ++count;     
                    ++cStart;
                }
                count = 0;
                countMove++;
                direction = 1;
            } else if (direction == 1) {
                while (count != stepSpiral) {
                    if ((rStart < rows) && (rStart >= 0) && (cStart < cols) && (cStart >= 0)) {
                        answer.push_back({rStart, cStart});
                        ++cnt;
                    }
                    ++rStart;
                    ++count;
                }
                count = 0;
                countMove++;
                direction = 2;
            } else if (direction == 2) {
                while (count != stepSpiral) {
                    if ((rStart < rows) && (rStart >= 0) && (cStart < cols) && (cStart >= 0)) {
                        answer.push_back({rStart, cStart});
                        ++cnt;
                    }
                    --cStart;
                    ++count;
                }
                count = 0;
                countMove++;
                direction = 3;
            } else if (direction == 3) {
                while (count != stepSpiral) {
                    if ((rStart < rows) && (rStart >= 0) && (cStart < cols) && (cStart >= 0)) {
                        answer.push_back({rStart, cStart});
                        ++cnt;
                    }
                    --rStart;
                    ++count;
                }
                count = 0;
                countMove++;
                direction = 0;
            }
            if (countMove == 2) {
                countMove = 0;
                stepSpiral++;
            }
        }
        return answer;
    }
};

int main() {

  
  
  
  
  return 0;  
}
