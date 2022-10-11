class Solution {
public:
    int minOperations(string s) {
        int cnt1 = 0;
        int index = 0;
        for (const auto &e: s) {
            if (index % 2 == 0) {
                if (e == '1')
                    ++cnt1;
            } else {
                if (e == '0')
                    ++cnt1;
            }
            ++index;
        }
        
        index = 0;
        int cnt2 = 0;
        for (const auto &e: s) {
            if (index % 2 == 0) {
                if (e == '0')
                    ++cnt2;
            } else {
                if (e == '1')
                    ++cnt2;
            }
            ++index;
        }
        
        return min(cnt1, cnt2);
    }
};


int main() {
  
  return 0;  
}
