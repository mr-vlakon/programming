class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue< pair<double, vector<int> > , vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
        for (const auto &e: points) {
            double tmp = sqrt( pow(e[0], 2.0) + pow( e[1], 2.0) );
            pq.push({tmp, {e[0], e[1]}});
        }
        int i = 0;
        while (i != k) {
            auto top = pq.top();
            res.push_back(top.second);
            pq.pop();
            ++i;
        }
        
        return res;
        
    }
};

int main() {
  
  
  return 0;  
}
