class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        auto maxE = (*max_element(segments.cbegin(), segments.cend(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[1] < rhs[1];
        }))[1];
        vector<long long> v(maxE + 1, 0);
        vector<bool> vis(maxE + 1, 0);
        for (const auto &e: segments) {
            v[e[1]] += e[2];
            v[e[0]] -= e[2];
            vis[e[1]] = true;
            vis[e[0]] = true;
        }
        long long tmp = v.back();
        int t = maxE;
        vector<vector<long long>> result;
        for (int i = v.size() - 2; i >= 0; --i) {
            if (v[i] != 0) {
                if (tmp != 0)
                    result.push_back({i, t, tmp});
                t = i;
            } else if (vis[i] == true) {
                if (tmp != 0)
                    result.push_back({i, t, tmp});
                t = i;    
            }
            tmp += v[i];
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
