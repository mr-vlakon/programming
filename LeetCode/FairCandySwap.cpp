class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long long aliceSum = accumulate(aliceSizes.cbegin(), aliceSizes.cend(), 0LL);
        long long bobSum = accumulate(bobSizes.cbegin(), bobSizes.cend(), 0LL);
        sort(aliceSizes.begin(), aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        for (int i = 0; i != aliceSizes.size(); ++i) {
            aliceSum -= aliceSizes[i];
            bobSum += aliceSizes[i];
            auto it = lower_bound(bobSizes.cbegin(), bobSizes.cend(), abs(aliceSum - bobSum) / 2);
            if ((it != bobSizes.cend()) && ((*it + aliceSum ) == (bobSum - *it))) {
                return {aliceSizes[i], *it};
            }
            aliceSum += aliceSizes[i];
            bobSum -= aliceSizes[i];
        }
        return {};       
    }
};

int main() {
  
  
  
  return 0;  
}
