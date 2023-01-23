class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> um;
        for (const auto &e: tasks) {
            ++um[e];
        }
        vector<pair<int, char>> v;
        for (const auto &e: um) {
            v.push_back({e.second, e.first});
        }
        sort(v.begin(), v.end(), [](pair<int, char> &lhs, pair<int, char> &rhs) {
            return lhs.first > rhs.first;
        });
        
        int time = 0;
        while (true) {
            auto it = v.begin();
            int j = 0;
            int cnt = 0;
            while (j != (n + 1) && it != v.end()) {
                if (it->first > 0) {
                    ++time;
                    --(it->first);
                    ++j;
                } else {
                    ++cnt;
                }
                ++it;
            }
            sort(v.begin(), v.end(), [](pair<int, char> &lhs, pair<int, char> &rhs) {
                return lhs.first > rhs.first;
            });
            if (v[0].first <= 0) {
                break;
            }
            if (cnt > 0) {
                v.erase(v.end() - cnt, v.end());
            }
            if (j != (n + 1)) {
                time += n - j + 1;
            }
        }
        return time;
  }
};

int main() {
  
  
    
  return 0;  
}
