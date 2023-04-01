class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int pref = arr[0];
        vector<int> prefix;
        prefix.push_back(0);
        prefix.push_back(pref);
        for (int i = 1; i != arr.size(); ++i) {
            pref ^= arr[i];
            prefix.push_back(pref);
        }
        vector<int> answer;
        for (int i = 0; i != queries.size(); ++i) {
            answer.push_back(prefix[queries[i][1] + 1] ^ prefix[queries[i][0]]);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
