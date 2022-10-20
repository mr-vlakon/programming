class Solution {
public:
    
    int countPrimeSetBits(int left, int right) {
        int counter = 0;
        unordered_set<int> us{2,3,5,7,11,13,17,19};
        while (left <= right) {
            int x = left;
            int cnt1 = 0;
            while (x) {
                cnt1 += (x % 2);
                x /= 2;
            }
            if (us.find(cnt1) != us.cend())
                ++counter;
            ++left;
        }        
        return counter;
    }
};

int main() {
  
  
  return 0;  
}
