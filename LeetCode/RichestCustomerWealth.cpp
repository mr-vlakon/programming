class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for (const auto &e: accounts) {
            int sum = accumulate(e.cbegin(), e.cend(), 0);
            if (sum > max)
                max = sum;
        }
        return max;
    }
};

int main() {
  
  
  return 0;  
}
