class Solution {
public:
    int numPrimeArrangements(int n) {
        if (n == 1) return 1;
        vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}; // 25
        auto it = upper_bound(prime.cbegin(), prime.cend(), n);
        int cnt = it - prime.cbegin();
        int diff = n - cnt;
        long long tmp = 1;
        
        while (cnt != 1) {
            tmp *= cnt;
            tmp %= 1000000007;
            --cnt;
        }
        long long d = 1;
        while (diff != 1) {
            d *= diff;
            d %= 1000000007;
            --diff;
        }
        return (tmp * d) % 1000000007;

    }
};

int main() {
  
  
  
  
  return 0;  
}
