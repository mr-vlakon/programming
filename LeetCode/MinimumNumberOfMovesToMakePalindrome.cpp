class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        list<char> lst(s.cbegin(), s.cend());
        auto start = lst.begin();
        auto end = lst.end();
        int cnt = 0;
        int rem = 0;
        int counter = 0;
        bool flag = false;
        while ((start != end) && (counter != lst.size() / 2)) {
            auto end_ = end;
            --end_;
            int tmp = 0;
            while ((*start != *end_) && (start != end_)) {
                ++tmp;
                --end_;
            }
            if (start != end_) {
                cnt += tmp;
                lst.erase(end_);
                end = lst.insert(end, *start);
            } else if (lst.size() % 2 == 1 && !flag) {
                flag = true;
                rem = counter;
                ++counter;
                ++start;
                continue;
            } else if (lst.size() % 2 == 0) {
                return cnt;
            } else if (lst.size() % 2 == 1 && flag) {
                return cnt + (flag ? abs(rem - static_cast<int>(lst.size() / 2)) : 0);
            }
            ++counter;
            ++start;
        }
        return cnt + (flag ? abs(rem - static_cast<int>(lst.size() / 2)) : 0);
    }
};

int main() {
  
  
  
  return 0;  
}
