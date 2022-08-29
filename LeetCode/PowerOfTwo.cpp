class Solution {
public:
    bool isPowerOfTwo(int n) {
        vector<int> v(32);
        int i = 0;
        while(n) {
            v[i++] = n % 2;
            n /=2;
        }
        if (v.size() == 0) return 0;
        if (count(v.cbegin(), v.cend(), 1) == 1) return true;
        return false;
    }
};

int main() {
  
 return 0; 
}
