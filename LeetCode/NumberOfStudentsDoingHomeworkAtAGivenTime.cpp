class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int cnt = 0;
        for (decltype(startTime.size()) i = 0; i != startTime.size(); ++i) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
