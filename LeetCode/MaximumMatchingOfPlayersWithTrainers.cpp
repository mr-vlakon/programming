class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        auto it = trainers.cbegin();
        int cnt = 0;
        for (const auto &e: players) {
            it = find_if(it, trainers.cend(), [=](const int &x) {
                return e <= x;
            });
            if (it != trainers.cend()) {
                ++cnt;
                ++it;
            } else {
                break;
            }
        }
        return cnt;
        
    }
};

int main() {
  
  
  return 0;  
}
