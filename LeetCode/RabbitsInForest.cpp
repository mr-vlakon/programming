class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> um;
        for (const auto &e: answers) {
            um[e]++;
        }
        int answer = 0;
        for (const auto &e: um) {
            if (e.second >= (e.first + 1)) {
                answer += (e.first + 1)*ceil((static_cast<double>(e.second) /(e.first + 1)));
            } else {
                answer += (e.first + 1);
            }
        }
        return answer;
    }
};
/*
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> um;
        for (const auto &e: answers) {
            um[e]++;
        }
        int answer = 0;
        for (const auto &e: um) {
            answer += (e.first + 1)*ceil((static_cast<double>(e.second) /(e.first + 1)));
        }
        return answer;
    }
};
*/
/*
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> um(1001, 0);
        for (const auto &e: answers) {
            um[e]++;
        }
        int answer = 0;
        for (int i = 0; i != um.size(); ++i) {
            answer += (i + 1)*ceil((static_cast<double>(um[i]) /(i + 1)));
        }
        return answer;
    }
};
*/

int main() {
  
  
  
  return 0;  
}
