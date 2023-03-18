class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        long long answer = 0;
        priority_queue<pair<int, int>, deque<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i != nums.size(); ++i) {
            pq.push({nums[i], i});
        }
        pair<int, int> top;
        while (!pq.empty()) {
            top = pq.top();
            pq.pop();
            if (visited[top.second] == true) {
                continue;
            }
            if ((top.second + 1) < nums.size()) {
                visited[top.second + 1] = true;
            }
            if ((top.second - 1) >= 0) {
                visited[top.second - 1] = true;
            }
            answer += nums[top.second];
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
