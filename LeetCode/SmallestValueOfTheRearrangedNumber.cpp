class Solution {
public:
    long long smallestNumber(long long num) {
        bool status = (num < 0);
        if (status) {
            num = -num;
        }
        vector<int> v;
        while(num) {
            int tmp = num % 10;
            v.push_back(tmp);
            num /= 10;
        }
        reverse(v.begin(), v.end());
        long long x = 0;
        if(!status) {
            sort(v.begin(), v.end());
            auto it = find(v.begin(), v.end(), 0);
            auto fnd = find_if(v.begin(), v.end(), [](const int &x) {
               return x > 0; 
            });
            if((it != v.cend()) && (fnd != v.cend())) {
                swap(*it, *fnd);
            }
            long long cnt = 1;
            reverse(v.begin(), v.end());
            for (const auto &e: v) {
                x += cnt * e;
                cnt *= 10;
            }
        } else {
            sort(v.rbegin(), v.rend());
            long long cnt = 1;
            reverse(v.begin(), v.end());
            for (const auto &e: v) {
                x += cnt * e;
                cnt *= 10;
            }
            x = -x;
        }
        return x;
    }
};

int main() {
  
  return 0;  
}
