class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1) return {};
        long long cnt = 2;
        unordered_set<long long> us;
        while(finalSum > 0) {
            if (cnt > finalSum) {
                auto tmp = *(us.begin());
                us.erase(us.cbegin());
                us.insert(tmp + finalSum);
                break;
            } else {
                us.insert(cnt);
            }
            finalSum -= cnt;
            cnt += 2;
        }
        return {us.cbegin(), us.cend()};
    }
};

int main() {
  
  
  return 0;  
}
