class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        if (s.size() == 1) return s;
        while (i < s.size()) {
          if ( i % (2*k)  == 0 ) {
                if (s.size() - i < k) {
                    reverse(s.begin() + i, s.end());
                } else {
                    reverse(s.begin() + i, s.begin() + i +  k);
                }
            }
            i += k;
        }
        return s;
    }
};

int main() {
  
  return 0;  
}
