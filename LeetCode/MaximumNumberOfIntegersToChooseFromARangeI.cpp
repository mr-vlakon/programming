class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int i = 1;
        unordered_set<int> ban;
        for (const auto &e: banned) {
            ban.insert(e);
        }
        int cnt = 0;
        int sum = 0;
        while (i <= n) {
            if (ban.find(i) == ban.cend()) {
                ++cnt;
                sum += i;
            }
            if (sum > maxSum) {
                return cnt - 1;
            }
            ++i;
        }
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}
