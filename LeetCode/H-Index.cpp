/*
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
*/
class Solution {
public:
    void binary(const vector<int> &cit, int left, int right) {
        if (left < 0) return;
        if (right > cit.size()) return;
        if (left > right) return;
        mid = (left + right) / 2;
        if (cit[mid] >= (mid + 1)) {
            ans = max(ans, mid + 1);
            if (left != right) {
                binary(cit, mid + 1, right);
            }
            return;
        } else {
            if (left != right) {
                binary(cit, left, mid - 1);
            }
            return;
        }
    }
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        binary(citations, 0, citations.size() - 1);
        return ans;
    }
private:
    int mid = 0;
    int ans = 0;
};

int main() {
  
  
  
  return 0;  
}
