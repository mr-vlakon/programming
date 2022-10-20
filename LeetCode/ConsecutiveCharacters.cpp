class Solution {
public:
    int maxPower(string s) {
        int max = 1;
        int cnt = 1;
        char prev;
        for (const auto &e: s) {
            if (cnt > max) {
                max = cnt;
            }
            if (prev == e) {
                ++cnt;
            } else {
                cnt = 1;
            }
            prev = e;      
        }
        if (cnt != 1 && cnt > max) {
            max = cnt;
        }
        return max;
    }
};

int main() {
  
  
  
  return 0;  
}
