class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for (auto &e: dominoes) {
            sort(e.begin(), e.end());
        }
        map<pair<int, int>, size_t> m;
        for (const auto &e: dominoes) {
            m[{e[0],e[1]}]++;
        }
        int cnt = 0;
        for (const auto &e: m) {
            if (e.second != 1) {
                cnt += (e.second - 1) * e.second / 2;
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
