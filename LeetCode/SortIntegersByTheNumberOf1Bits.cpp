class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        stable_sort(arr.begin(), arr.end(), [] (const int &lhs, const int &rhs) {
           int cnt = 0, bit1 = 0, bit2 = 0;
           while(cnt != 32) {
               if (lhs & (1 << cnt)) {
                   ++bit1;
               } 
               if (rhs & (1 << cnt)) {
                   ++bit2;
               }
               ++cnt;
           }
            return bit1 < bit2;
        });
        return arr;
    }
};

int main() {

  return 0;
}
