class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        queue<pair<int, int>> q;
        q.push({click[0], click[1]});
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
        int cnt = 0;
        pair<int, int> top;
        visited[click[0]][click[1]] = true;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            cnt = 0;
            if (board[top.first][top.second] == 'M') {
                board[top.first][top.second] = 'X';
                break;
            } else if (board[top.first][top.second] == 'E') {
                if ((top.first + 1) < board.size()) {
                    if (board[top.first + 1][top.second] == 'M') {
                        ++cnt;
                    }
                    if ((top.second + 1) < board[0].size()) {
                        if (board[top.first + 1][top.second + 1] == 'M') {
                            ++cnt;
                        }
                    }
                    if ((top.second - 1) >= 0) {
                        if (board[top.first + 1][top.second - 1] == 'M') {
                            ++cnt;
                        }
                    }        
                }
                if ((top.first - 1) >= 0) {
                    if (board[top.first - 1][top.second] == 'M') {
                        ++cnt;
                    }
                    if ((top.second + 1) < board[0].size()) {
                        if (board[top.first - 1][top.second + 1] == 'M') {
                            ++cnt;
                        }
                    }
                    if ((top.second - 1) >= 0) {
                        if (board[top.first - 1][top.second - 1] == 'M') {
                            ++cnt;
                        }
                    }
                }
                if ((top.second + 1) < board[0].size()) {
                    if (board[top.first][top.second + 1] == 'M') {
                        ++cnt;
                    }
                }
                if ((top.second - 1) >= 0) {
                    if (board[top.first][top.second - 1] == 'M') {
                        ++cnt;
                    }
                }
                if (cnt != 0) {
                    board[top.first][top.second] = cnt + '0';
                } else {
                    board[top.first][top.second] = 'B';
                    if ((top.first + 1) < board.size()) {
                        if (!visited[top.first + 1][top.second]) {
                            visited[top.first + 1][top.second] = true;
                            q.push({top.first + 1, top.second});
                        }
                        if ((top.second + 1) < board[0].size() && !visited[top.first + 1][top.second + 1]) {
                            visited[top.first + 1][top.second + 1] = true;
                            q.push({top.first + 1, top.second + 1});
                        }
                        if ((top.second - 1) >= 0 && !visited[top.first + 1][top.second - 1]) {
                            visited[top.first + 1][top.second - 1] = true;
                            q.push({top.first + 1, top.second - 1});
                        }        
                    }
                    if ((top.first - 1) >= 0) {
                        if (!visited[top.first - 1][top.second]) {
                            visited[top.first - 1][top.second] = true;
                            q.push({top.first - 1, top.second});
                        }
                        if ((top.second + 1) < board[0].size() && !visited[top.first - 1][top.second + 1]) {
                            visited[top.first - 1][top.second + 1] = true;
                            q.push({top.first - 1, top.second + 1});
                        }
                        if ((top.second - 1) >= 0 && !visited[top.first - 1][top.second - 1]) {
                            visited[top.first - 1][top.second - 1] = true;
                            q.push({top.first - 1, top.second - 1});
                        }
                    }
                    if ((top.second + 1) < board[0].size() && !visited[top.first][top.second + 1]) {
                        visited[top.first][top.second + 1] = true;
                        q.push({top.first, top.second + 1});
                    }
                    if ((top.second - 1) >= 0 && !visited[top.first][top.second - 1]) {
                        visited[top.first][top.second - 1] = true;
                        q.push({top.first, top.second - 1});
                    }
                }
            }
        }
        return board;
    }
};

int main() {
  
  
  
  
  return 0;  
}
