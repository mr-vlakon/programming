class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string result;        
        vector<vector<int>> hasher(26, vector<int>(votes[0].size() + 1, 0));
        for (int i = 0; i != hasher.size(); ++i) {
            hasher[i][votes[0].size()] = hasher.size() - i;
        }
        for (int i = 0; i != votes.size(); ++i) {
            for (int j = 0; j != votes[0].size(); ++j) {
                hasher[votes[i][j] - 'A'][j]++;
            }
        }
        sort(hasher.begin(), hasher.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs > rhs;
        });
        for (int i = 0; i != votes[0].size(); ++i) {
            result.push_back(hasher.size() - hasher[i].back() + 'A');
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
