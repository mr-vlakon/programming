class Solution {
public:
    int numSub(string s) {
        int cnt = 0;
        auto it = s.cbegin();
        auto prev = it;
        while (it != s.cend()) {
            it = find_if(it, s.cend(), [=](const char &c) {
               return c != *it;
            });
            auto size = it - prev;
            while(size && *prev != '0') {
                cnt += size;
                if (cnt > 1000000000)
                    cnt %= 1000000007;        
                --size;
            }
            prev = it;
        }
        return cnt;
    }
};

int main() {
  
  return 0;  
}
