class Solution {
public:
    void generate(long long &finalSum, vector<long long> &v, long long &start) {
        if (status) {
            return;
        }
        if (finalSum == x && !status) {
            answer = v;
            status = true;
            return;
        }
        if (finalSum > x) {
            return;
        }
        if (start > x) {
            return;
        }

        if (!status) {
            finalSum += start;
            v.push_back(start);
            if (finalSum  <= x) {
                start += 2;
                generate(finalSum, v, start);
                start -= 2;
                if (status) {
                    return;
                }
                v.pop_back();
                finalSum -= start;
                if (finalSum <= x && (finalSum + start + 2) <= x) {
                    start += 2;
                    generate(finalSum, v, start);
                    if (status) {
                        return;
                    }
                    start -= 2;        
                }
                finalSum += start;
                start += 2;
            } else {
                v.pop_back();
                finalSum -= start;
            }
        }
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        if ((finalSum % 2 ) == 1) return {};
        vector<long long> empty;
        x = finalSum;
        long long t = 0;
        long long st = 2;
        generate(t, empty, st);
        return answer;
    }
private:
    bool status = false;
    long long x = 0;
    vector<long long> answer;
};
/*
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1) return {};
        long long cnt = 2;
        unordered_set<long long> us;
        while(finalSum > 0) {
            if (cnt > finalSum) {
                auto tmp = *(us.begin());
                us.erase(us.cbegin());
                us.insert(tmp + finalSum);
                break;
            } else {
                us.insert(cnt);
            }
            finalSum -= cnt;
            cnt += 2;
        }
        return {us.cbegin(), us.cend()};
    }
};
*/

int main() {
  
  
  return 0;  
}
