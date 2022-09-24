class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, size_t> um;
        for (const auto &e: arr) {
            ++um[e];
        }
        vector<pair<int,int>> v;
        for (const auto &e: um) {
            v.push_back({e.first, e.second});
        }
        sort(v.begin(), v.end(), [=](const pair<int, int> &lhs, const pair<int, int> &rhs)          {
            return lhs.second > rhs.second; 
        });
        vector<int> res;
        int index = 0;
        int cnt = 0;
        for (const auto &e : v) {
            int size = e.second;
            ++cnt;
            while(size) {
                res.push_back(e.first);
                --size;
            }
            if (res.size() >= (arr.size() / 2))
                break;
        }
        return cnt;
    }
};

int main() {
  
  return 0;  
}
