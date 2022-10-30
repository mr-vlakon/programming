class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        vector<int> v;
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }
        
        long long sum = accumulate(v.cbegin(), v.cend(), 0LL);
        if (sum <= target) return 0;

        long long cnt = 1;
        long long answer = 0;
        for (decltype(v.size()) i = 0; i < v.size(); ++i) {
            auto tmp = v[i];
            v[i] = 0;
            if ((i + 1) < v.size()) {
                v[i + 1]++;
            } else {
                
            }
            sum -= tmp;
            sum += 1;
            
            answer += cnt * static_cast<long long>(10 - tmp);
            
            if (sum <= target) {
                return answer;
            }
            cnt *= 10;    
        }
        return 0;
        
    }
};

int main() {
  
  
  
  return 0;  
}
