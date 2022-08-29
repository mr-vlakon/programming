class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> v(32);
        int i = 0;
        while(n) {
            v[i++] = n % 2;
            n /=2;
        }
        unsigned cnt = 1;
        uint32_t result = 0;
        reverse(v.begin(), v.end());
        for(const auto &e: v) {
            result += e * cnt; 
            cnt *= 2;
        }
        return result;
    }
};

int main() {
  
  return 0;  
}
