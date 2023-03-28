class TopVotedCandidate {
public:
    void binary(const int &t, int &left, int &right) {
        if (left > right) return;
        mid = (left + right) / 2;
        if (time[mid] > t) {
            right = mid - 1;
            binary(t, left, right);
        } else {
            tmp = max(tmp, mid);
            left = mid + 1;
            binary(t, left, right);
        }
    }

    TopVotedCandidate(vector<int>& persons, vector<int>& times) : per(persons), time(times) {
        hash.resize(per.size(), 0);
        for (int i = 0; i != times.size(); ++i) {
            um[per[i]]++;
            if (um[per[i]] >= maxV) {
                maxV = um[per[i]];
                maxP = per[i];
            }
            hash[i] = maxP;
        }
    }

    int q(int t) {
        left = 0;
        right = time.size() - 1;
        tmp = 0;
        mid = 0;
        binary(t, left, right);
        return hash[tmp];
    }
private:
    int left = 0;
    int right = 0;
    int mid = 0;
    int tmp = 0;
    int maxV = 0;
    int maxP = 0;
    vector<int> hash;
    vector<int> per;
    vector<int> time;
    unordered_map<int, int> um;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

int main() {
  
  
  
  return 0;  
}
