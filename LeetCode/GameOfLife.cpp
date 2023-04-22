class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int cnt = 0;
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[0].size(); ++j) {
                cnt = 0;
                if ((i - 1) >= 0) {
                    if (abs(board[i - 1][j]) == 1) {
                        ++cnt;
                    }
                    if ((j - 1) >= 0) {
                        if (abs(board[i - 1][j - 1]) == 1) {
                            ++cnt;
                        }
                    }
                    if ((j + 1) < board[0].size()) {
                        if (abs(board[i - 1][j + 1]) == 1) {
                            ++cnt;
                        }                            
                    }
                }
                if ((j + 1) < board[0].size()) {
                    if (abs(board[i][j + 1]) == 1) {
                        ++cnt;
                    }                            
                }
                if ((j - 1) >= 0) {
                    if (abs(board[i][j - 1]) == 1) {
                        ++cnt;
                    }                            
                }
                if ((i + 1) < board.size()) {
                    if (abs(board[i + 1][j]) == 1) {
                        ++cnt;
                    }
                    if ((j - 1) >= 0) {
                        if (abs(board[i + 1][j - 1]) == 1) {
                            ++cnt;
                        }
                    }
                    if ((j + 1) < board[0].size()) {
                        if (abs(board[i + 1][j + 1]) == 1) {
                            ++cnt;
                        }                            
                    }
                }
                if (cnt < 2) {
                    if (board[i][j] == 1) {
                        board[i][j] = -1;
                    }
                } else if (cnt > 3) {
                    if (board[i][j] == 1) {
                        board[i][j] = -1;
                    }
                } else if (cnt == 3) {
                    if (board[i][j] == 0) {
                        board[i][j] = 2;
                    }
                }     
            }
        }
        for (auto &e: board) {
            for (auto &p: e) {
                if (p == 2) {
                    p = 1;
                } else if (p == -1) {
                    p = 0;
                }
            }
        }
    }
};

int main() {
  
  
  
  return 0;  
}
