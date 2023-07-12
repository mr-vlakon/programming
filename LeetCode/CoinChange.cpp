class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        queue<pair<long long, int>> q;
        q.push({0, 0});
        vector<int> vecAmn(amount + 1, INT_MAX);
        pair<long long, int> top;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            for (const auto &e: coins) {
                if ((top.first + e) <= amount) {
                    if ((top.second + 1) < vecAmn[top.first + e]) {
                        q.push({top.first + e, top.second + 1});
                        vecAmn[top.first + e] = top.second + 1;
                    }
                }
            }
        }
        return (vecAmn[amount] == INT_MAX) ? -1 : vecAmn[amount];
    }
};

int main() {

  
  return 0;
}
