class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> tmp;
        for (const auto &e: mat) {
            tmp.push_back(count(e.cbegin(), e.cend(), 1));
        }
        
        vector<pair<int, size_t>> v;
        for (decltype(tmp.size()) i = 0; i != tmp.size(); ++i) {
            auto cnt1 = count(tmp.cbegin() + i + 1, tmp.cend(), tmp[i]);
            
            auto cntLess1 = count_if(tmp.cbegin(), tmp.cbegin() + i, [=](const int &x) {
                return x > tmp[i];
            });
            
            auto cntLess2 = count_if(tmp.cbegin() + i + 1, tmp.cend(), [=](const int &x) {
                return x > tmp[i];
            });
            
            v.push_back({cnt1 + cntLess1 + cntLess2, i});
        }
        
        sort(v.begin(), v.end(), [=] (const pair<int, size_t> &lhs, const pair<int, size_t> &rhs) {
            return lhs.first > rhs.first;
        });
        
        vector<int> answer;
        for (const auto &e: v) {
            answer.push_back(e.second);
        }
        return {answer.cbegin(), answer.cbegin() + k};
    }
};


int main() {
  
  
  
  return 0;  
}
