class Solution {
public:
    void binary(const vector<vector<int>> &items, const int &pr, int &left, int &right) {
        if (left > right) return;
        middle = (left + right) / 2;  
        if (items[middle][0] <= pr) {
            tmp = middle;
            left = middle + 1;
            binary(items, pr, left, right);
        } else {
            right = middle - 1;
            binary(items, pr, left, right);
        }      
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [] (vector<int> &lhs, vector<int> &rhs) {
            return lhs[0] < rhs[0];
        });
        vector<int> v(items.size(), 0);
        v[0] = items[0][1];
        for (int i = 1; i != items.size(); ++i) {
            v[i] = max(v[i - 1], items[i][1]);
        }
        vector<int> result;
        for (const auto &e: queries) {
            left = 0;
            right = items.size() - 1;
            binary(items, e, left, right);
            if (tmp != -1) {
                result.push_back(v[tmp]);
            } else { 
                result.push_back(0);
            }
            tmp = -1;
        }
        return result;
    }
private:
    int left = 0;
    int right = 0;
    int middle = 0;
    int tmp = -1;
};

int main() {
  
  
  
  return 0;  
}
