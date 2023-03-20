class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long sum = accumulate(arr.cbegin(), arr.cend(), 0LL);
        if ((sum % 3) != 0) {
            return false;
        }
        long long tmp = 0;
        int cnt = 0;
        for (int i = 0; i != arr.size(); ++i) {
            tmp += arr[i];
            if (tmp == (sum / 3)) {
                ++cnt;
                tmp = 0;
            }                        
        }
        return cnt >= 3;
    }
};

int main() {

  
  
  return 0;  
}
