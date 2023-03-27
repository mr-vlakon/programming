class Solution {
public:
    void binary(const vector<pair<int, int>> &vect,const int &find, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        if (vect[mid].first >= find) {
            right = mid - 1;
            tmp = v[mid].second;
            binary(vect, find, left, right);
        } else {
            left = mid + 1;
            binary(vect, find, left, right);
        }
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        for (int i = 0; i != intervals.size(); ++i) {
            v.push_back({intervals[i][0], i});
        }
        sort(v.begin(), v.end(), [] (pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.first < rhs.first;
        });
        int left = 0;
        int right = v.size() - 1;
        for(const auto &e: intervals) {
            left = 0;
            right = v.size() - 1;
            binary(v, e[1], left, right);
            answer.push_back(tmp);
            tmp = -1;
            mid = 0;
        }
        return answer;
    }
private:
    int tmp = -1;
    vector<int> answer;
    int mid = 0;
    vector<pair<int, int>> v;
};

int main() {
  
  
  return 0;  
}
