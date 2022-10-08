class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        long long sum = accumulate(chalk.cbegin(), chalk.cend(), 0LL);
        long long q = static_cast<long long>(k) / static_cast<long long>(sum);
        long long kk = static_cast<long long>(k) - q * sum;
        if (chalk.size() == 1) return 0;
        while (k > 0) {
            kk -= chalk[i];
            if (kk < 0)
                return i;
            if (i == chalk.size() - 1)
                i = 0;
            else
                ++i;
        }
        return 0;
    }
};

int main() {
  
  
  
  return 0;  
}
