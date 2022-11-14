class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s;
        while(n) {
            s += to_string(n % 10);
            n /= 10;
        }
        sort(s.begin(), s.end());
        do {
            if (s[0] != '0') {
                int num = stoi(s);
                if((num & (num - 1)) == 0) return true;
            }
        } while(next_permutation(s.begin(), s.end()));
        return false;
    }
};

int main() {
  
  
  
  return 0;  
}
