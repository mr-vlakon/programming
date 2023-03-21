class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) return m * n;
        pair<int, int> p{100000,100000};
        for (int i = 0; i != ops.size(); ++i) {
            for (int j = 0; j != ops[0].size(); ++j) {
                p.first = min(p.first, ops[i][0]);
                p.second = min(p.second, ops[i][1]);
                
            }
        }
        return p.first * p.second;
    }
};

int main() {
  
  
  
  return 0;  
}
