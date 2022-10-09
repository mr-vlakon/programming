class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int start = 0;
        int max = 0;
        int tmp = 0;
        for (decltype(logs.size()) i = 0; i != logs.size(); ++i) {
            tmp = logs[i][1] - start;
            start = logs[i][1];
            if (tmp > max) {
                max = tmp;
            }
        }
        start = 0;
        tmp = 0;
        vector<int> v;
        for (decltype(logs.size()) i = 0; i != logs.size(); ++i) {
            tmp = logs[i][1] - start;
            start = logs[i][1];
            if (tmp == max) {
                v.push_back(logs[i][0]);
            }
        }
        
        return *min_element(v.cbegin(), v.cend());
        
    }
};

int main() {
  
  
  return 0;  
}
