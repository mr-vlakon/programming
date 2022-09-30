class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        auto it = s.cbegin();
        auto prev = it;
        while (it != s.cend()) {
            it = find_if(it, s.cend(), [=](const char &c) {
               return c != *it;
            });
            auto size = it - prev;
            if (*prev == '1') ++cnt;
            if (cnt > 1) return false;
            prev = it;
        }
        //cout << cnt << endl;
        return true;
    }
};

int main() {
  
  return 0;  
}
