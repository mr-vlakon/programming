class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        if (n <= (target / 2)) return (n*(n + 1) / 2) % 1000000007;
        int half = target / 2;
        int finish = target + n - half - 1;
        return (static_cast<long long>(half)*(half + 1) / 2 + static_cast<long long>(finish)*(finish + 1) / 2 - static_cast<long long>(target)*(target - 1) /2) % 1000000007;
    }
};

int main()
{


  return 0;
}
