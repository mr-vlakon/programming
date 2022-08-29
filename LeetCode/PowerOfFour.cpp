class Solution {
public:
    bool isPowerOfFour(int n) {
        vector<int> v1(32);
        int i = 0;
        while(n) {
            v1[i++] = n % 2;
            n /=2;
        }
        vector<int> v;
        for (decltype(v1.size()) i = 0; i != v1.size(); ++i) {
            if (i % 2 == 0)
                v.push_back(v1[i]);
        }
        if (count(v.cbegin(), v.cend(), 1) == 1 && count(v1.cbegin(), v1.cend(), 1) == 1) return true;
        return false;
    }
};

int main() {
  
 return 0; 
}
