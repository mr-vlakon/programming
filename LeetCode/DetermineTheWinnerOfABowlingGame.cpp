class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = 0;
        int score2 = 0;
        for (int i = 0; i != player1.size(); ++i) {
            if (((i > 0)) && (player1[i - 1] == 10 || ((i > 1) && player1[i - 2] == 10))) {
                score1 += 2*player1[i];
            } else {
                score1 += player1[i];        
            }   
        }
        for (int i = 0; i != player2.size(); ++i) {
            if ((i > 0) && (player2[i - 1] == 10 || ((i > 1) && player2[i - 2] == 10))) {
                score2 += 2*player2[i];
            } else {
                score2 += player2[i];        
            }
        }
        return (score1 > score2) ? 1 : (score1 < score2) ? 2 : 0;
    }
};

int main() {
  
  
  
  
  return 0;  
}
