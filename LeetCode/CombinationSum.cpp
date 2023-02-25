class Solution {
public:

    void generate(const vector<int> &num, int i, vector<int> &v, int target) {
        if (i < 0) {
            if (target == tar) {
                result.push_back(v);
            }
            return;
        }
        if (i >= num.size()) {
            if (target == tar) {
                result.push_back(v);
            }
            return;
        } 
        if (target > tar) {
            return;
        }
        v.push_back(num[i]);
        int tmp = target;
        target += num[i];
        generate(num, i, v, target);
        generate(num, i + 1, v, target);
        v.pop_back();
        generate(num, i + 1, v, tmp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> empty;
        tar = target;
        generate(candidates, 0, empty, 0);
        for (auto &e: result) {
            sort(e.begin(), e.end());
        }
        sort(result.begin(), result.end());
        auto p = unique(result.begin(), result.end());
        return {result.begin(), p};
    }
private:
    int tar = 0;
    vector<vector<int>> result;
};

int main() {
  
  
  return 0;  
}
