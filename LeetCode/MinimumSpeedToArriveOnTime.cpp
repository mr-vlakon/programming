/*
class Solution {
public:
    void binary(const vector<int> &dist, const double &d, int &left, int &right) {
        if (left > right) return;
        tmp = 0;
        mid = (left + right) / 2;
        for (int i = 0; i != dist.size(); ++i) {
            tmp += static_cast<double>(dist[i]) / static_cast<double>(mid + 1);
            if (i != (dist.size() - 1)) {
                tmp = ceil(tmp);
            }
        }
        if (tmp <= d) {
            right = mid - 1;
            answer = min(answer, (mid + 1));
            binary(dist, d, left, right);
        } else {
            left = mid + 1;
            binary(dist, d, left, right);
        }
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int right = 10000001;
        int left_ = 0;
        binary(dist, hour, left_, right);
        if (answer == 10000001) return -1;
        return answer;
    }
private:
    int mid = 0;
    double tmp = 0;
    int answer = 10000001;
};
*/

class Solution {
public:
    void binary(const vector<int> &dist, const double &d, int &left, int &right) {
        if (left > right) return;
        tmp = 0;
        mid = (left + right) / 2;
        for (int i = 0; i != dist.size(); ++i) {
            tmp += static_cast<double>(dist[i]) / static_cast<double>(mid + 1);
            if (i != (dist.size() - 1)) {
                tmp = ceil(tmp);
            }
        }
        if (tmp <= d) {
            right = mid - 1;
            answer = min(answer, (mid + 1));
            binary(dist, d, left, right);
        } else {
            left = mid + 1;
            binary(dist, d, left, right);
        }
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int right = 10000001;
        int left_ = accumulate(dist.cbegin(), dist.cend(), 0LL) / hour - 1;
        binary(dist, hour, left_, right);
        if (answer == 10000001) return -1;
        return answer;
    }
private:
    int mid = 0;
    double tmp = 0;
    int answer = 10000001;
};

int main() {
  
    
  return 0;  
}
