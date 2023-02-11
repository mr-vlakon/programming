class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row = 0;
        int col = 0;
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[0].size(); ++j) {
                if (board[i][j] == 'R') {
                    row = i;
                    col = j;
                    break;
                }
            }
        } 
        int rowTmp = row;
        int answer = 0;
        while (rowTmp >= 0) {
            if (board[rowTmp][col] == 'B') {
                break;
            } else if (board[rowTmp][col] == 'p') {
                ++answer;
                break;
            } else {
                --rowTmp;
            }
        }
        rowTmp = row;
        while (rowTmp < board.size()) {
            if (board[rowTmp][col] == 'B') {
                break;
            } else if (board[rowTmp][col] == 'p') {
                ++answer;
                break;
            } else {
                ++rowTmp;
            }
        }
        int colTmp = col;
        while (colTmp < board[0].size()) {
            if (board[row][colTmp] == 'B') {
                break;
            } else if (board[row][colTmp] == 'p') {
                ++answer;
                break;
            } else {
                ++colTmp;
            }
        }
        colTmp = col;
        while (colTmp >= 0) {
            if (board[row][colTmp] == 'B') {
                break;
            } else if (board[row][colTmp] == 'p') {
                ++answer;
                break;
            } else {
                --colTmp;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
