class Solution {
public:
    void generate(int index = -1, vector<int> curr = {}) {
        if (index == v.size())
            return; 
        if (!curr.empty()) {
            res.push_back(curr);
        }
        for (int i = index + 1; i < v.size(); i++) {
            curr.push_back(v[i]);
            generate( i, curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        v = nums;
        res.resize(1);
        generate();
        for (auto &e: res)
            sort(e.begin(), e.end());
        sort(res.begin(), res.end());
        auto p = unique(res.begin(), res.end());
        return {res.begin(), p};
    }
private:
    vector<int> v;
    vector<vector<int>> res;
};

int main() {
  
  
  return 0;  
}
