class Solution {
public:
    bool isPalindrome(int x) {
        int tmp = 0;
        int t = x;
        if (t & (1 << 31)) {
            return false;
        }
        vector<unsigned> v;
        bool status = false;
        while (x) {
            tmp = (x % 10);
            if (tmp == 0 && status == false) {
            } else {
                v.push_back(tmp);
            }
            status = true;
            x /= 10;
        }
        unsigned result = 0, cnt = 1;
        int size = v.size() - 1;
        while (size >= 0) {
            result += cnt * v[size];
            cnt *= 10;
            --size;
        }
        if (result == t) {
            return true;
        } else {
            return false;
        }
    }    
    bool isStrictlyPalindromic(int n) {
        int i = 2;
        while(i <= n - 2) {
            long x = n;
            long y = 0;
            long cnt = 1;
            while(x) {
                long tmp = x % i;
                y += tmp * cnt;
                cnt *= 10;
                x /= i;
            }
            bool status = isPalindrome(y);
            if (!status)
                return false;
            ++i;
        }
        
        
        return true;
    }
};

int main() {

 
  return 0;
}
