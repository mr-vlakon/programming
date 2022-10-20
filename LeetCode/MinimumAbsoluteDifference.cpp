class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        for (decltype(arr.size()) i = 0; i != arr.size() - 1; ++i) {
            result.push_back({arr[i], arr[i + 1]});
        }
        
        int min = 100000;
        for (decltype(result.size()) i = 0; i != result.size(); ++i) {
            if (abs(result[i][0] - result[i][1]) < min) {
                min = abs(result[i][0] - result[i][1]);
            }   
        }
        vector<vector<int>> answer;
                
        for (decltype(result.size()) i = 0; i != result.size(); ++i) {
            if (abs(result[i][0] - result[i][1]) == min) {
                answer.push_back({result[i][0], result[i][1]});
            }   
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
