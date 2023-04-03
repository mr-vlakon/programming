class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n, vector<int>(n, -1));
        int startRow = 0;
        int startCol = 0;
        int bordLeft = 0;
        int bordRight = n - 1;
        int bordUp = 0;
        int bordDown = n - 1; 
        int direction = 0;
        int i = 1;
        while (i <= (n * n)) {
            answer[startRow][startCol] = i;
            ++i;
            if (startCol == bordRight && startRow == bordUp && direction == 0) {
                startRow++;
                bordUp++;
                direction = 1;
            } else if (startRow == bordDown && startCol == bordRight && direction == 1) {
                --bordRight;
                --startCol;
                direction = 2;
            } else if (startRow == bordDown && startCol == bordLeft && direction == 2) {
                direction = 3;
                --startRow;
                --bordDown;
            } else if (startRow == bordUp && startCol == bordLeft && direction == 3) {
                direction = 0;
                ++startCol;
                ++bordLeft;
            } else if (direction == 0) {
                ++startCol;
            } else if (direction == 1) {
                ++startRow;
            } else if (direction == 2) {
                --startCol;
            } else {
                startRow--;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  
  return 0;  
}
