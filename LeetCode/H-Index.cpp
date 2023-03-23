class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int cnt = 0;
        int answer = 0;
        for (int i = 0; i != citations.size(); ++i) {
            cnt++;
            if (citations[i] >= cnt) {
                answer = cnt;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
