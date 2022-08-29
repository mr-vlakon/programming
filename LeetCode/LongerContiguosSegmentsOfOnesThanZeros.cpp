class Solution {
public:
    bool checkZeroOnes(string s) {
        int count1 = 0;
        int max1 = 0;
        int count0 = 0;
        int max0 = 0;
        for(decltype(s.size()) i = 0; i != s.size(); ++i) {
            if (s[i] == '1') { 
                ++count1;
            } else
                ++count0;
            if (s[i] == '0') {
                if(count1 > max1) {
                    max1 = count1;
                }
                count1 = 0;
            }
            if (s[i] == '1') {
                if(count0 > max0) {
                    max0 = count0;
                }
                count0 = 0;
            }
        }
        if (count1 > max1)
            max1 = count1;
        if (count0 > max0)
            max0 = count0;
        return max1 > max0;
    
    }
};

int main() {
  
  return 0;  
}
