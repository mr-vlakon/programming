class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> um;   
        for (int i = 0; i != board.size(); i += 3) {
            for (int j = 0; j != board[0].size(); j += 3) {
                um.clear();
                if (board[i][j] != '.') {
                    um[board[i][j]]++;
                    if (um[board[i][j]] > 1) {
                        return false;
                    }
                }
                if (board[i][j + 1] != '.') {
                    um[board[i][j + 1]]++;
                    if (um[board[i][j + 1]] > 1) {
                        return false;
                    }
                }
                if (board[i][j + 2] != '.') {
                    um[board[i][j + 2]]++;
                    if (um[board[i][j + 2]] > 1) {
                        return false;
                    }
                }
                if (board[i + 1][j] != '.') {
                    um[board[i + 1][j]]++;
                    if (um[board[i + 1][j]] > 1) {
                        return false;
                    }
                }
                if (board[i + 1][j + 1] != '.') {
                    um[board[i + 1][j + 1]]++;
                    if (um[board[i + 1][j + 1]] > 1) {
                        return false;
                    }
                }
                if (board[i + 1][j + 2] != '.') {
                    um[board[i + 1][j + 2]]++;
                    if (um[board[i + 1][j + 2]] > 1) {
                        return false;
                    }
                }
                if (board[i + 2][j] != '.') {
                    um[board[i + 2][j]]++;
                    if (um[board[i + 2][j]] > 1) {
                        return false;
                    }
                }
                if (board[i + 2][j + 1] != '.') {
                    um[board[i + 2][j + 1]]++;
                    if (um[board[i + 2][j + 1]] > 1) {
                        return false;
                    }
                }
                if (board[i + 2][j + 2] != '.') {
                    um[board[i + 2][j + 2]]++;
                    if (um[board[i + 2][j + 2]] > 1) {
                        return false;
                    }
                }
            }
        }
        vector<vector<char>> trans(board.size(), vector<char>(board[0].size(), '.'));
        for (int i = 0; i != trans.size(); ++i) {
            for (int j = 0; j != trans[0].size(); ++j) {
                trans[j][i] = board[i][j];
            }
        }
        for (int i = 0; i != trans.size(); ++i) {
            um.clear();
            for (int j = 0; j != trans[0].size(); ++j) {
                um[trans[i][j]]++;
                if (um[trans[i][j]] > 1 && trans[i][j] != '.') {
                    return false;
                }
            }    
        }
        for (int i = 0; i != board.size(); ++i) {
            um.clear();
            for (int j = 0; j != board[0].size(); ++j) {
                um[board[i][j]]++;
                if (um[board[i][j]] > 1 && board[i][j] != '.') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}
