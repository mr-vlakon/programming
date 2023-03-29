class Solution {
public:
    void binary(const string &s, const string &t, const int &costs, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        cnt = 0;
        tmp = 100000;
        for (int i = 0; i != mid; ++i) {
            cnt += abs(s[i] - t[i]);
        }
        tmp = min(cnt, tmp);
        for (int i = 1; i < s.size() - mid + 1; ++i) {
            cnt -= abs(s[i - 1] - t[i - 1]);
            cnt += abs(s[mid + i - 1] - t[mid + i - 1]);
            tmp = min(cnt, tmp);
        }
        if (tmp <= costs) {
            answer = max(answer, mid);
            left = mid + 1;
            binary(s, t, costs, left, right);
        } else {
            right = mid - 1;
            binary(s, t, costs, left, right);
        }
    }
    int equalSubstring(string s, string t, int maxCost) {
        left = 0;
        right = s.size();
        binary(s, t, maxCost, left, right);
        return answer;
    }
private:
    int cnt = 0;
    int tmp = 0;
    int answer = 0;
    int left = 0;
    int right = 0;
    int mid = 0;
};

int main() {
  
  
  return 0;  
}
