class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> v;
        for (int i = 0; i != dist.size(); ++i) {
            v.push_back(static_cast<double>(dist[i]) / speed[i]);
        }
        sort(v.begin(), v.end());
        int start = 1;
        int answer = 1;
        for (int i = 1; i != v.size(); ++i) {
            if (start < v[i]) {
                ++start;
                ++answer;
            } else {
                break;
            }
        }
        return answer;
    }
};
/*
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> v;
        for (int i = 0; i != dist.size(); ++i) {
            v.push_back(static_cast<double>(dist[i]) / speed[i]);
        }
        sort(v.begin(), v.end());
        double start = 1;
        int answer = 1;
        for (int i = 1; i != v.size(); ++i) {
            if (start < v[i]) {
                ++start;
                ++answer;
            } else {
                break;
            }
        }
        return answer;
    }
};
*/
/*
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> v;
        for (int i = 0; i != dist.size(); ++i) {
            v.push_back(static_cast<double>(dist[i]) / speed[i]);
        }
        sort(v.begin(), v.end());
        double start = 1;
        int answer = 1;
        for (int i = 1; i != v.size(); ++i) {
            if ((start + 0.0000001) < v[i]) {
                ++start;
                ++answer;
            } else {
                break;
            }
        }
        return answer;
    }
};
*/

int main() {
  
  
  
  return 0;  
}
