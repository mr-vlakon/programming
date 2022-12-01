class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, size_t> um;
        for (const auto &c: s) {
             ++um[c];
        }
        vector<size_t> v;
        for (const auto &e: um) {
            v.push_back(e.second);
        }
        unordered_map<int, int> um1;
        unordered_set<int> us;
        int score = 0;
        for (const auto &e: v) {
            um1[e]++;
            us.insert(e);
        }
        if (us.size() == v.size()) return 0;
        for (int i = 0; i != v.size(); ++i) {
            int tmp = v[i];
            if (um1[v[i]] > 1) {
                while (us.find(v[i]) != us.cend() && v[i] > 0) {
                    --v[i];
                    ++score;
                }
                um1[tmp]--;
                us.insert(v[i]);
                um1[v[i]]++;
            }
        }
        return score;
    }
};

int main() {
  
  
  
  return 0;  
}
