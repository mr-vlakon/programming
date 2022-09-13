class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0;
        int i = 1;
        while (cnt != k) {
            if (count(arr.cbegin(), arr.cend(), i) == 0)
                ++cnt;
            ++i;
        }
        return i - 1;
    }
};

int main() {
  
  
  return 0;  
}
