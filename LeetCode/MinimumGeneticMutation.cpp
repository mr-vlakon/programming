class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        string initial = startGene;
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({initial, 0});
        int answer = INT_MAX;
        pair<string, int> top;
        int cnt = 0;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            visited.insert(top.first);
            if (top.first == endGene) {
                answer = min(answer, top.second);
            } 
            for (int i = 0; i != bank.size(); ++i) {
                cnt = 0;
                for (int j = 0; j != bank[i].size(); ++j) {
                    if (bank[i][j] != top.first[j]) {
                        cnt++; 
                    }
                }
                if (cnt == 1 && visited.find(bank[i]) == visited.cend()) {
                    q.push({bank[i], top.second + 1});
                }
            }
        }
        if (answer == INT_MAX) return -1;
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
