class Solution {
public:
    int maxArea(vector<int>& height) {
        auto beg = height.cbegin();
        auto end = --height.cend();
        vector<int> v;
        while (beg < end) {
            if (*beg < *end) {
                v.push_back((end - beg) * *beg);
                ++beg;
            } else {
                v.push_back((end - beg) * *end);
                --end;
            }
        }
        return *max_element(v.cbegin(), v.cend());
    }
};

int main() {
  
  
  return 0;  
}
