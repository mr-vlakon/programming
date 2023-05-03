class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        vector<bool> v(2000, 0);
        for (int i = 0; i != fronts.size(); ++i) {
            if (fronts[i] == backs[i]) {
                v[fronts[i] - 1] = true;
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i != fronts.size(); ++i) {
            if (v[fronts[i] - 1] == false) {
                ans = min(fronts[i], ans);
            }
            if (v[backs[i] - 1] == false) {
                ans = min(backs[i], ans);
            }
        }
        return (ans == INT_MAX) ? 0: ans;
    }
};

int main() {
  
  
  
    
  return 0;  
}
