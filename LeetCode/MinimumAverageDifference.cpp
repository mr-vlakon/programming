class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> prefix;
        vector<long long> suffix;
        long long prefSum = 0;
        size_t size = 1;
        for (const auto &e: nums) {
            prefSum += e;
            prefix.push_back( prefSum / size);
            ++size;
        }
        reverse(nums.begin(), nums.end());
        
        suffix.push_back(0);
        long long sufSum = 0;
        size = 1;
        for (const auto &e: nums) {
            sufSum += e;
            suffix.push_back( sufSum / size);
            ++size;
        }
        suffix.erase(--suffix.cend());
        reverse(suffix.begin(), suffix.end());
     
        long long min = 100000000;
        size_t minInd = 0;
        for (decltype(prefix.size()) i = 0; i != prefix.size(); ++i) {
            if (abs(prefix[i] - suffix[i]) < min) {
                min = abs(prefix[i] - suffix[i]);
                minInd = i;
            }
            
        }        
        
        return minInd;
    }
};

int main() {
  
  
  return 0;  
}
