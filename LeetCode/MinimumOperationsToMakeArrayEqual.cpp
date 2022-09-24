class Solution {
public:
    int minOperations(int n) {
        int i = 0;
        vector<int> res;
        while (i != n) {
            res.push_back(2 * i + 1);
            ++i;
        }
        int target = accumulate(res.cbegin(), res.cend(), 0) / n;
        int cnt = 0;
        int size = res.size() / 2;
        i = 0;
        while (i != size) {
            cnt += target - res[i];
            ++i;
        }
        return cnt;
    }
};

int main() {
  

  return 0;
}
