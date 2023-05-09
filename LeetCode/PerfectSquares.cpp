class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        vector<int> memo(n + 1, 0);
        q.push({n, 0});
        pair<int, int> top;
        int i = 1;
        int x = 1;
        while (!q.empty()) {
            i = 1;
            top = q.front();
            q.pop();
            if (memo[top.first] < top.second) {
                continue;
            }
            x = i*i;
            while (x <= n) {
                if ((top.first - x) >= 0) {
                    if (!memo[top.first - x]) {
                        memo[top.first - x] = top.second + 1;
                        q.push({top.first - x, top.second + 1});
                    }
                } else {
                    break;
                }
                ++i;
                x = i*i;
            }
            if (top.first == 0) break;
        }
        return memo[0];
    }
};

int main() {
  
  
  
  
  return 0;  
}
