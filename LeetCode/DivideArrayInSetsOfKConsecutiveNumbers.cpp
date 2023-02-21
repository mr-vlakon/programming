class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (const auto &e: nums) {
            um[e]++;
        }
        vector<pair<int, int>> v;
        for (const auto &e: um) {
            v.push_back({e.first, e.second});
        }
        sort (v.begin(), v.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        int start = 0;
        int cnt = 0;
        int prev = -1;
        bool status = false;
        while (true) {
            cnt = 0;
            prev = -1;
            status = false;
            for (int i = start; i < v.size(); ++i) {
                if (cnt == k) {
                    break;
                }
                if ((v[i].second != 0) && (prev == -1 || ((prev + 1) == v[i].first))) {
                    ++cnt;
                    --v[i].second;
                    if ((v[i].second != 0 ) && !status) {
                        start = i;
                        status = true;
                    }
                } else if (prev != (v[i].first + 1)) {
                    return false;
                }
                prev = v[i].first;
            }
            if (cnt != k) {
                return false;
            }
            if (!status && (start + k) < v.size()) {
                start += k;
            } else if (!status) {
                break;
            }
        }

        return true;
    }
};

int main() {

  
  
  return 0;  
}
