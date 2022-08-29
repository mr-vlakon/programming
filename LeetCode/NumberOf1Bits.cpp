class Solution {
public:
    int hammingWeight(uint32_t n) {
        vector<int> v(32);
        int i = 0;
        while(n) {
            v[i++] = n % 2;
            n /=2;
        }
        int cnt = count(v.cbegin(), v.cend(), 1);
        return cnt;   
    }
};

int main() {
  
  return 0;  
}
