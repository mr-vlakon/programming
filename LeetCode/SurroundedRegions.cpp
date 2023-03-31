class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        queue<pair<int, int>> q;       
        pair<int, int> top;
        
        for (int j = 0; j != board[0].size(); ++j) {
            if (board[0][j] == 'O') {
                if (visited[0][j] == false) {
                    q.push({0, j});
                    while (!q.empty()) {
                        top = q.front();
                        q.pop();
                        visited[top.first][top.second] = true;
                        if ((top.first - 1) >= 0 && board[top.first - 1][top.second] == 'O' && visited[top.first - 1][top.second] == false) {
                            visited[top.first - 1][top.second] = true;

                            q.push({top.first - 1, top.second});
                        }
                        if ((top.first + 1) < board.size() && board[top.first + 1][top.second] == 'O' && visited[top.first + 1][top.second] == false) {
                            visited[top.first + 1][top.second] = true;
                            
                            q.push({top.first + 1, top.second});
                        }
                        if ((top.second - 1) >= 0 && board[top.first][top.second - 1] == 'O' && visited[top.first][top.second - 1] == false) {
                           visited[top.first][top.second - 1] = true;
                            
                            q.push({top.first, top.second - 1});
                        }
                        if ((top.second + 1) < board[0].size() && board[top.first][top.second + 1] == 'O' && visited[top.first][top.second + 1] == false) {
                            visited[top.first][top.second + 1] = true;
                            
                            q.push({top.first, top.second + 1});
                        }
                    
                    }
                }
            }}

        for (int j = 0; j != board[board.size() - 1].size(); ++j) {
            if (board[board.size() - 1][j] == 'O') {
                                if (visited[board.size() - 1][j] == false) {
                    q.push({board.size() - 1,j});
                    while (!q.empty()) {
                        top = q.front();
                        q.pop();
                        visited[top.first][top.second] = true;
                        if ((top.first - 1) >= 0 && board[top.first - 1][top.second] == 'O' && visited[top.first - 1][top.second] == false) {
                            visited[top.first - 1][top.second] = true;
                            
                            q.push({top.first - 1, top.second});
                        }
                        if ((top.first + 1) < board.size() && board[top.first + 1][top.second] == 'O' && visited[top.first + 1][top.second] == false) {
                           visited[top.first + 1][top.second] = true;
                            
                            q.push({top.first + 1, top.second});
                        }
                        if ((top.second - 1) >= 0 && board[top.first][top.second - 1] == 'O' && visited[top.first][top.second - 1] == false) {
                            visited[top.first][top.second - 1] = true;
                            
                            q.push({top.first, top.second - 1});
                        }
                        if ((top.second + 1) < board[0].size() && board[top.first][top.second + 1] == 'O' && visited[top.first][top.second + 1] == false) {
                            visited[top.first][top.second + 1] = true;
                            
                            q.push({top.first, top.second + 1});
                        }
                    
                    }
                }
            }
        }


        for (int j = 0; j != board.size(); ++j) {
            if (board[j][0] == 'O') {
                if (visited[j][0] == false) {
                    q.push({j, 0});
                    while (!q.empty()) {
                        top = q.front();
                        q.pop();
                        visited[top.first][top.second] = true;
                        if ((top.first - 1) >= 0 && board[top.first - 1][top.second] == 'O' && visited[top.first - 1][top.second] == false) {
                           visited[top.first - 1][top.second] = true;
                            
                            q.push({top.first - 1, top.second});
                        }
                        if ((top.first + 1) < board.size() && board[top.first + 1][top.second] == 'O' && visited[top.first + 1][top.second] == false) {
                           visited[top.first + 1][top.second] = true;
                            
                            q.push({top.first + 1, top.second});
                        }
                        if ((top.second - 1) >= 0 && board[top.first][top.second - 1] == 'O' && visited[top.first][top.second - 1] == false) {
                            visited[top.first][top.second - 1] = true;
                            
                            q.push({top.first, top.second - 1});
                        }
                        if ((top.second + 1) < board[0].size() && board[top.first][top.second + 1] == 'O' && visited[top.first][top.second + 1] == false) {
                            visited[top.first][top.second + 1] = true;
                            
                            q.push({top.first, top.second + 1});
                        }
                    
                    }
                }
            }
        }
        for (int j = 0; j != board.size(); ++j) {
            if (board[j][board[0].size() - 1] == 'O') {
                if (visited[j][board[0].size() - 1] == false) {
                    q.push({j, board[0].size() - 1});
                    while (!q.empty()) {
                        top = q.front();
                        q.pop();
                        visited[top.first][top.second] = true;
                        if ((top.first - 1) >= 0 && board[top.first - 1][top.second] == 'O' && visited[top.first - 1][top.second] == false) {
                            visited[top.first - 1][top.second] = true;
                            
                            q.push({top.first - 1, top.second});
                        }
                        if ((top.first + 1) < board.size() && board[top.first + 1][top.second] == 'O' && visited[top.first + 1][top.second] == false) {
                            visited[top.first + 1][top.second] = true;
                            
                            q.push({top.first + 1, top.second});
                        }
                        if ((top.second - 1) >= 0 && board[top.first][top.second - 1] == 'O' && visited[top.first][top.second - 1] == false) {
                            visited[top.first][top.second - 1] = true;
                            
                            q.push({top.first, top.second - 1});
                        }
                        if ((top.second + 1) < board[0].size() && board[top.first][top.second + 1] == 'O' && visited[top.first][top.second + 1] == false) {
                            visited[top.first][top.second + 1] = true;
                            
                            q.push({top.first, top.second + 1});
                        }
                    
                    }
                }
        }
        }
        
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[0].size(); ++j) {
                if (board[i][j] == 'O' && visited[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {


  
  return 0;
}
