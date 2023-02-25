/*
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
*/

class Solution {
public:
    void generate(const vector<int> &num, int i, vector<int> &v) {
        if (i == num.size()) {
            result.push_back(v);
            return;
        }
        v.push_back(num[i]);
        generate(num, i + 1, v);
        v.pop_back();
        generate(num, i + 1, v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> empty;
        sort(nums.begin(), nums.end());
        generate(nums, 0, empty);
        sort(result.begin(), result.end());
        auto p = unique(result.begin(), result.end());
        //result.erase(p, result.end());
        return {result.begin(), p};
    }
private:
    vector<vector<int>> result;
};

int main() {
  
  
  return 0;  
}
