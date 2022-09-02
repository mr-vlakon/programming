class Solution {
public:
    int compress(vector<char>& chars) {
        vector<string> nums;
        int cnt = 0;
        auto prev = chars.cbegin();
        for (decltype(chars.size()) i = 0; i < chars.size();) {  
            nums.push_back(string(1,chars[i]));
            auto it = find_if(chars.cbegin() + i, chars.cend(), [=](const char &c) {
                return c != chars[i];
            });
            auto cnt = it - prev;
            if (cnt != 1 && cnt != 0) {
                nums.push_back(to_string(cnt));
            }
            if (cnt != 0)
                i += cnt;
            else 
                ++i;
            prev = it;
        }
        chars.resize(0);
        for (const auto &e: nums) {
            for (const auto &p: e) {
                chars.push_back(p);
            }
        }
        return chars.size();
    }
};

int main() {

  return 0;  
}
