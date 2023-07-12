class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int s =  0;
        int answer = 0;
        for (int i = 0; i != gas.size(); ++i) {
            sum += gas[i] - cost[i];
            s += gas[i] - cost[i];
            if (sum < 0) {
                answer = i + 1;
                sum = 0;
            }
        }
        if (s < 0) return -1;
        return answer;
    }
};
/*
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i != gas.size(); ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                cnt = 0;
                sum = 0;
            } else {
                ++cnt;
                if (cnt > gas.size() - 1) {
                    return (i - cnt + 1 + gas.size()) % gas.size();
                }
            }   
        }
        for (int i = 0; i != gas.size() - 1; ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                cnt = 0;
                sum = 0;
            } else {
                ++cnt;
                if (cnt > gas.size() - 1) {
                    return (i - cnt + 1 + gas.size()) % gas.size();
                }
            }   
        }
        
        return -1;
    }
};
*/
/*
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i != 2*gas.size() - 1; ++i) {
            sum += gas[i % gas.size()] - cost[i % gas.size()];
            if (sum < 0) {
                cnt = 0;
                sum = 0;
            } else {
                ++cnt;
                if (cnt > gas.size() - 1) {
                    return i - cnt + 1;
                }
            }   
        }
        return -1;
    }
};
*/
int main() {


  
  return 0;
}
