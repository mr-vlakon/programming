class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s;
        while(n) {
            s += to_string(n % 2);
            n /= 2;
        }
        
        char prev;
        for (const auto &e: s) {
            if (e == prev)
                return false;
            prev = e;
        }
        return true;
        
    }
};

int main() {
  
  
  return 0;  
}
