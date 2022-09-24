class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (const auto &e : nums) {
            int sum = 0;
            int cnt = 0;
            int square_root = static_cast<int>(sqrt(e)) + 1;
            for (int i = 1; i < square_root; i++) { 
                if (e % i == 0 && (i * i != e)) {
                    sum += i;
                    sum += e / i;
                    cnt += 2;
                }
                if (e % i == 0 && i*i == e) {
                    sum += i;
                    ++cnt;
                }
            }
            if (cnt == 4) 
                res += sum;
        }
        return res;
        
    }
};

int main() {
  
  
  return 0;  
}
