class Solution {
public:
    vector<int> f(int n) {
        vector<int> result;
        while(n) {
            int tmp = n % 10;
            result.push_back(tmp);
            n /=10;
        }
        return result;
    }
    bool isHappy(int n) {
        vector<int> result;
        int tmp = n;
        int count = 1000;
        if (n == 1) return true;
        while(count--) {
            auto v = f(tmp);
            int q = 0;
            for (const auto &e : v) {
                q += e*e;
            }
            if (q == 1 ) return true;
            tmp = q;
        }
        return false;
    }
};

int main() {
  
  return 0; 
}
