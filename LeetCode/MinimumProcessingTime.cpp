class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());
        int answer = 0;
        int cnt = 0;
        int index = 0;
        for (int i = 0; i != tasks.size(); ++i) {
            if ((cnt % 4) == 0 && cnt != 0) {
                ++index;
            }
            answer = max(answer, tasks[i] + processorTime[index]);
            ++cnt;
        }
        return answer;
    }
};

int main()
{



  return 0;
}
