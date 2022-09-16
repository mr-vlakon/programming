class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int> v;
        if (n == 0) return 1;
        while(n) {
            int tmp = n % 2;
            v.push_back(tmp);
            n /= 2;
        }
        for (auto &e: v) {
            e = (e == 1) ? 0 : 1;
        }
        long long x = 0;
        int index = 0;
        for (const auto &e: v) {
            x += pow(2, index) * e;
            ++index;
        }
        return x;
        
    }
};

int main() {
  
  
  return 0;  
}
