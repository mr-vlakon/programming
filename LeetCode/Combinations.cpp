class Solution {
public:
    void generate(const vector<int> &num, int i, vector<int> &v) { 
        if (i == num.size()) {
            if (v.size() == k_)
                result.push_back(v);
            return;
        }
        if (i > num.size()) {
            return;
        } 
        v.push_back(num[i]);
        if (v.size() <= k_)
            generate(num, i + 1, v);
        v.pop_back();
        if (v.size() <= k_)
            generate(num, i + 1, v);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> empty;
        vector<int> candidates;
        k_ = k;
        int i = 1;
        while (i <= n) {
            candidates.push_back(i);
            ++i;
        }
        generate(candidates, 0, empty);
        return result;
    }
private:
    int k_ = 0;
    vector<vector<int>> result;
};

int main() {
  
  
  return 0;  
}
