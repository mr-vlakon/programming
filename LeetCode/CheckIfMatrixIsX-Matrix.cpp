class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int i = 0;
        int cnt = 0;
        for (const auto &e: grid) {
            if (i == e.size() - i - 1 && grid.size() % 2 == 1) {
                ++cnt;
            } else {
                cnt += 2;
            }
            if (e[i] == 0 || e[e.size() - i - 1] == 0)
                return false;
            ++i;
        }
        
        for (const auto &e: grid) {
            cnt += count(e.cbegin(), e.cend(), 0);
        }
        
        cout << cnt << endl;
        
        return cnt == grid.size() * grid.size();
    }
};

int main() {
  
  
  return 0;  
}
