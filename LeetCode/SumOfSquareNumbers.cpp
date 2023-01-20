class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int> sq;
        int i = 0;
        while (i <= c && ((static_cast<long long>(i) * static_cast<long long>(i)) <= static_cast<long long>(c))) {
            sq.push_back(i * i);
            ++i;
        }
        auto start = sq.begin();
        auto end = --sq.end();
        while (start <= end) {
            if ((static_cast<long long>(*start) + static_cast<long long>(*end)) == c) {
                return true;
            }  else if ((static_cast<long long>(*start) + static_cast<long long>(*end)) > c) {
                --end;
            } else if ((*start + *end) < c) {
                ++start;
            }
        }
        return false;
    }
};

int main() {
  
  
  return 0;  
}
