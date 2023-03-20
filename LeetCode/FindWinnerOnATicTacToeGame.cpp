class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> mat(3, vector<int>(3, -1));
        for (int i = 0; i != moves.size(); ++i) {
            if ((i % 2) == 0) {
                mat[moves[i][0]][moves[i][1]] = 1;
            } else {
                mat[moves[i][0]][moves[i][1]] = 0;   
            }
        }
        for (int i = 0; i != moves.size(); ++i) {
            if (((moves[i][0] - 1) >= 0 && (moves[i][1] - 1) >= 0) && 
            ((moves[i][0] + 1) < 3 && (moves[i][1] + 1) < 3)) {
                if ((i % 2) == 0) {
                    if (mat[moves[i][0] - 1][moves[i][1] - 1] == 1 
                    && mat[moves[i][0] + 1][moves[i][1] + 1] == 1) {
                        return "A";
                    }
                } else {
                    if (mat[moves[i][0] - 1][moves[i][1] - 1] == 0 
                    && mat[moves[i][0] + 1][moves[i][1] + 1] == 0) {
                        return "B";
                    }    
                }
            }
            if (((moves[i][0] + 1) < 3 && (moves[i][1] - 1) >= 0) && 
            ((moves[i][0] - 1) >= 0 && (moves[i][1] + 1) < 3)) {
                if ((i % 2) == 0) {
                    if (mat[moves[i][0] + 1][moves[i][1] - 1] == 1 
                    && mat[moves[i][0] - 1][moves[i][1] + 1] == 1) {
                        return "A";
                    }
                } else {
                    if (mat[moves[i][0] + 1][moves[i][1] - 1] == 0 
                    && mat[moves[i][0] - 1][moves[i][1] + 1] == 0) {
                        return "B";
                    }    
                }
            }
        }
        int cnt1 = 0;
        int cnt0 = 0;
        vector<vector<int>> trans(3, vector<int>(3, -1));
        for (int i = 0; i != mat.size(); ++i) {
            cnt1 = 0;
            cnt0 = 0;
            for (int j = 0; j != mat[0].size(); ++j) {
                trans[j][i] = mat[i][j];
                if (mat[i][j] == 0) {
                    ++cnt0;
                } else if (mat[i][j] == 1) {
                    ++cnt1;
                }
            }
            if (cnt0 == 3) {
                return "B";
            }
            if (cnt1 == 3) {
                return "A";
            }
        }
        for (const auto &e: trans) {
            cnt1 = 0;
            cnt0 = 0;
            for (const auto &p: e) {
                if (p == 0) {
                    ++cnt0;
                } else if (p == 1) {
                    ++cnt1;
                }
            }
            if (cnt0 == 3) {
                return "B";
            }
            if (cnt1 == 3) {
                return "A";
            }
        }
        for (const auto &e: mat) {
            for (const auto &p : e) {
                if (p == -1) {
                    return "Pending";
                }
            }
        }
        return "Draw";
    }
};

int main() {
  
  
  
  return 0;  
}
