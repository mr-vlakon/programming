class Solution {
public:
    void binary(const string &s, string &p, const vector<int> &rem, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        v.assign(s.size(), 0);
        for (int i = 0; i != mid; ++i) {
            v[rem[i]] = -1;
        }
        j = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == p[j] && v[i] != -1) {
                ++j;
            }
        }
        if(j == p.size()) {
            answer = max(answer, mid);
            left = mid + 1;
            binary(s, p, rem, left, right);
        } else {
            right = mid - 1;
            binary(s, p, rem, left, right);
        }
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0;
        int right = removable.size();
        binary(s, p, removable, left, right);
        return answer;
    }
private:
    vector<int> v;  
    int j = 0;
    int answer = 0;
    int mid = 0;
};

int main() {

  
  
  
  return 0;  
}
