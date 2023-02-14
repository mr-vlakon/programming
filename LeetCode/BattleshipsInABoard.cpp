class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int answer = 0;
        bool status1 = true;
        bool status2 = true;
        for (int i = 0; i != board.size(); ++i) {
            for (int j = 0; j != board[i].size(); ++j) {
                if (board[i][j] == 'X') {
                    status1 = true;
                    status2 = true;               
                    if ((i + 1) < board.size() && board[i + 1][j] == 'X') {
                        status1 = false;
                    } 
                    if ((j + 1) < board[0].size() && board[i][j + 1] == 'X') {
                        status2 = false;
                    }
                    if (status1 && status2)
                        answer++;
                }            
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
