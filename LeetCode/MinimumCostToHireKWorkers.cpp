class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        if (k == 1) {
            return *min_element(wage.cbegin(), wage.cend());
        }        
        vector<pair<double, double>> vec;
        for (int i = 0; i != quality.size(); ++i) {
            vec.push_back({static_cast<double>(wage[i]) / static_cast<double>(quality[i]) , 
                static_cast<double>(quality[i])});
        }
        sort(vec.begin(), vec.end(), [&](pair<double, double> &lhs, pair<double, double> &rhs) {
            return lhs.first < rhs.first;
        });
        priority_queue<double> pq;
        double tmp = 0;
        for (int i = 0; i != k; ++i) {
            tmp += vec[i].second;
            pq.push(vec[i].second);
        }
        double answer = tmp * vec[k - 1].first;
        double tmpAnswer = 0.0;
        for (int i = k; i != vec.size(); ++i) {
            auto top = pq.top();
            pq.pop();
            pq.push(vec[i].second);
            tmp -= top;
            tmp += vec[i].second;
            tmpAnswer = vec[i].first * tmp;
            if (tmpAnswer < answer) {
                answer = tmpAnswer;
            } 
        }
        return answer;
  }
};

int main() {
  
  
  return 0;  
}
