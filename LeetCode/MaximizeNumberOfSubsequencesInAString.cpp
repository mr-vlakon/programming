class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int cnt1 = 0;        
        int cnt2 = 0;
        long long tmp = 0;
        int addedMax = 0;
        bool status = false;
        int count1 = 0;
        int counter = count(text.cbegin(), text.cend(), pattern[1]);
        for (const auto &e: text) {
            if (e == pattern[0] && !status) {
                ++cnt1;
                ++count1;
            } else if (e == pattern[1]) {
                ++cnt2;
                status = true;
            } else if (e == pattern[0]) {
                ++count1;            
                tmp += counter * cnt1;
                addedMax = max(addedMax, (cnt1));
                addedMax = max(addedMax, (counter));
                counter -= cnt2;
                cnt1 = 1;
                cnt2 = 0;
                status = false;
            }
        }
        addedMax = max(addedMax, cnt1);
        addedMax = max(addedMax, counter);
        addedMax = max(addedMax, count1);
        tmp += static_cast<long long>(counter) * cnt1;
        tmp += addedMax;
        counter -= cnt1;       
        if (pattern[0] == pattern[1]) tmp /= 2; 
        return tmp;
    }
};

int main() {
  
  
  
  
    
  return 0;  
}
