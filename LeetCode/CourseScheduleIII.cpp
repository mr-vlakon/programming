class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int> &lhs, vector<int> &rhs) {
            return lhs[1] < rhs[1];
        });
        priority_queue<int> pq;
        pq.push(courses[0][0]);
        int duration = (courses[0][1] >= courses[0][0]) ? courses[0][0] : 0;
        int answer = (duration != 0) ? 1 : 0;
        for (int i = 1; i != courses.size(); ++i) {
            if ((duration + courses[i][0]) <= courses[i][1]) {
                ++answer;
                duration += courses[i][0];
                pq.push(courses[i][0]);
            } else {
                if (pq.top() > courses[i][0]) {
                    auto top = pq.top();
                    duration -= top;
                    pq.pop();
                    pq.push(courses[i][0]);
                    if ((duration + courses[i][0]) <= courses[i][1]) {
                        duration = courses[i][0] + duration;
                    }
                }
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
