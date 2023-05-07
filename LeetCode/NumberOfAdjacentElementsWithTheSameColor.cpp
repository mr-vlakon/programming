class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> initialAr(n, 0);
        vector<int> answer;
        initialAr[queries[0][0]] = queries[0][1];
        answer.push_back(0);
        int cnt = 0;
        int tmp = 0;
        int tmpV = 0;
        for (int i = 1; i != queries.size(); ++i) {
            if (initialAr[queries[i][0]] == 0) {
                if ((queries[i][0] - 1) >= 0) {
                    if (initialAr[queries[i][0] - 1] == queries[i][1]) {
                        ++cnt;
                    }
                }
                if ((queries[i][0] + 1) < n) {
                    if (initialAr[queries[i][0] + 1] == queries[i][1]) {
                        ++cnt;
                    }
                }
                answer.push_back(cnt);
            } else if (initialAr[queries[i][0]] != queries[i][1]){
                tmp = 0;
                tmpV = initialAr[queries[i][0]];
                if ((queries[i][0] - 1) >= 0) {
                    if (initialAr[queries[i][0] - 1] == tmpV) {
                        ++tmp;
                    }
                }
                if ((queries[i][0] + 1) < n) {
                    if (initialAr[queries[i][0] + 1] == tmpV) {
                        ++tmp;
                    }
                }
                if ((queries[i][0] - 1) >= 0) {
                    if (initialAr[queries[i][0] - 1] == queries[i][1]) {
                        ++cnt;
                    }
                }
                if ((queries[i][0] + 1) < n) {
                    if (initialAr[queries[i][0] + 1] == queries[i][1]) {
                        ++cnt;
                    }
                }
                cnt -= tmp;            
                answer.push_back(cnt);
            } else {
                answer.push_back(cnt);
            }
            initialAr[queries[i][0]] = queries[i][1];
        }
        return answer;
    }
};

int main() {
  
  
  
  
  
  
  return 0;  
}
