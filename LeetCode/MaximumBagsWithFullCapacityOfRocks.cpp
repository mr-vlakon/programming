class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int, deque<int>, greater<int>> pq;
        int answer = 0;
        vector<int> tmp;
        for (int i = 0; i != capacity.size(); ++i) {
            if ((capacity[i] - rocks[i]) == 0) {
                ++answer;
            } else {
                tmp.push_back(capacity[i] - rocks[i]);
            }
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i != tmp.size(); ++i) {
            if (tmp[i] <= additionalRocks) {
                ++answer;
                additionalRocks -= tmp[i];
            } else {
                break;
            }
        }
        return answer;
    }
};

int main() {

  
  
  return 0;  
}
