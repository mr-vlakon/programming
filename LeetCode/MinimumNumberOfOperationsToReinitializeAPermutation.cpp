class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        vector<int> initial(perm);
        int cnt = 0;
        
        do {
            vector<int> arr(perm.size());
            for (decltype(perm.size()) i = 0; i != perm.size(); ++i) {
                if (i % 2 == 0) {
                    arr[i] = perm[i / 2];
                } else {
                    arr[i] = perm[perm.size() / 2 + (i - 1) / 2];
                }
            }
            perm = arr;
            ++cnt;
        } while (initial != perm);
        
        return cnt;
        
    }
};

int main() {
  
  
  return 0;  
}
