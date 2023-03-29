class Solution {
public:
    void binary(const string &s, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        if (position[mid] != -1 && position[mid] >= l) {
            tmp = mid;
            right = mid - 1;
            binary(s, left, right);
        } else {
            left = mid + 1;
            binary(s, left, right);
        }
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int pos = -1;
        vector<int> prefix;
        int pref = 0;
        for (int i = 0; i != s.size(); ++i) {
            if (s[i] == '|') {
                pos = i;
                position.push_back(pos);
            } else {
                pref++;
                position.push_back(pos);
            }
            prefix.push_back(pref);
        }
        vector<int> result;
        for (const auto &e: queries) {
            left = e[0];
            right = e[1];
            tmp = -1;
            l = e[0];
            binary(s, left, right);
            if (tmp != -1 && position[tmp] >= e[0]) {
                result.push_back(prefix[position[e[1]]] - prefix[position[tmp]]);
            } else {
                result.push_back(0);
            }
        }
        return result;
    }
private:
    int l = 0;
    vector<int> position;    
    int tmp = -1;
    int left = 0;
    int right = 0;
    int mid = 0;
};

int main() {
  
  
  return 0;  
}
