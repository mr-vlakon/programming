class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        vector<int> memo(n + 1, 0);
        q.push({n, 0});
        pair<int, int> top;
        int i = 1;
        while (!q.empty()) {
            i = 1;
            top = q.front();
            q.pop();
            if (memo[top.first] < top.second) {
                continue;
            }
            //memo[top.first] = top.second;
            while (i*i <= n) {
                if ((top.first - i*i) >= 0) {
                    if (!memo[top.first - i*i]) {
                        memo[top.first - i*i] = top.second + 1;
                        q.push({top.first - i*i, top.second + 1});
                    }
                } else {
                    break;
                }
                ++i;
            }
        }
        return memo[0];
    }
};

int main() {
  
  
  
  
  return 0;  
}
