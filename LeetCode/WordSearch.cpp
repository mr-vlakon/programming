class Solution {
public:
    bool generate(vector<vector<char>> &board, const string &word, int k, string &str, int row, int col) {
        if (str == word) {
            return true;
        }
        if (str.size() >= word.size()) {
            return false;
        }
        if (str.size() == 0) {
            for (int i = 0; i != board.size(); ++i) {
                for (int j = 0; j != board[0].size(); ++j) {
                    if (visited[i][j] == false && board[i][j] == word[0]) {
                        visited[i][j] = true;
                        str.push_back(word[0]);
                        if (str.size() <= word.size()) {
                            status |= generate(board, word, k + 1, str, i, j);
                            visited[i][j] = false;
                        }
                        str.pop_back();                                               
                    }
                }
            }
        } else {
            for (int i = 0; i != board.size(); ++i) {
                for (int j = 0; j != board[0].size(); ++j) {
                    if (visited[i][j] == false && board[i][j] == word[k]) {
                        if ( ((row + 1) == i && col == j) || ((row - 1) == i && col == j) || ((row) == i && (col + 1) == j) || ((row) == i && (col - 1) == j)) {
                            visited[i][j] = true;
                            str.push_back(word[k]);
                            if (str.size() <= word.size()) {
                                status |= generate(board, word, k + 1, str, i, j);
                                visited[i][j] = false;
                            }
                            str.pop_back();    
                        }
                    }
                }
            }
        }
        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char, int> umB;
        for (const auto &e: board) {
            for (const auto &p: e) {
                umB[p]++;
            }
        }
        unordered_map<char, int> umW;
        for (const auto &e: word) {
            umW[e]++;
        }
        for (const auto &e: umW) {
            if (e.second > umB[e.first]) {
                return false;
            }
        }
        string empty;
        visited.resize(board.size(), vector<bool>(board[0].size(), false));
        return generate(board, word, 0, empty, -1, -1);
    }
private:
    bool status = false;
    vector<vector<bool>> visited;
};

int main() {
  
  
  
  
  return 0;  
}
