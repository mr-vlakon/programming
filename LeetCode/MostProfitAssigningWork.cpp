class Solution {
public:
    void binary(const vector<pair<int, int>> &v, const int &w, int &left, int &right) {
        if (left > right) {
            return;
        }
        mid = (left + right) / 2;
        if (v[mid].first <= w) {
            tmp = max(tmp, v[mid].second);
            left = mid + 1;
            binary(v, w, left, right);
        } else {
            right = mid - 1;
            binary(v, w, left, right);
        }
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> v;
        for (int i = 0; i != difficulty.size(); ++i) {
            v.push_back({difficulty[i], profit[i]});
        }
        sort(v.begin(), v.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        for (int i = 1; i != v.size(); ++i) {
            v[i].second = max(v[i - 1].second, v[i].second);
        }
        int left = 0;
        int right = v.size() - 1;
        for (int i = 0; i != worker.size(); ++i) {
            left = 0;
            right = v.size() - 1;
            tmp = 0;
            binary(v, worker[i], left, right);
            answer += tmp;
        }
        return answer;
    }
private:
    int tmp = 0;
    int answer = 0;
    int mid  = 0;
};

int main() {
  
  
  return 0;  
}
