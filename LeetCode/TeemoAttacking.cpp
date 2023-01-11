class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int end = 0;
        int cnt = 0;
        for (int i = 0; i != timeSeries.size(); ++i) {
            if (timeSeries[i] <= end) {
                cnt -= (end - timeSeries[i]);
            }
            cnt += duration;
            end = timeSeries[i] + duration;
        }
        return cnt;
    }
};

int main() {
  
 
  return 0;
}
