class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int i = 0;
        vector<vector<int>> vect(status.size());
        for (const auto &e: containedBoxes) {
            for (const auto &p: e) {
                vect[i].push_back(p);
            }
            ++i;
        }
        queue<int> q;
        for (const auto &e: initialBoxes) {
            status[e] |= 2;
            q.push(e);
        }
        int answer = 0;
        int top = 0;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            for (const auto &e: keys[top]) {
                status[e] |= true;
            }
            for (const auto &e: vect[top]) {
                if (status[e] <= 1) {
                    q.push(e);
                    status[e] |= 2;
                }
            }
        }
        for (int i = 0; i != status.size(); ++i) {
            if (status[i] == 3) {
                answer += candies[i];
            }
        }        
        return answer;
    }
};
/*
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int i = 0;
        vector<vector<int>> vect(status.size());
        for (const auto &e: containedBoxes) {
            for (const auto &p: e) {
                vect[i].push_back(p);
            }
            ++i;
        }
        queue<int> q;
        vector<bool> visited(status.size(), 0);    
        for (const auto &e: initialBoxes) {
            visited[e] = true;
            q.push(e);
        }
        int answer = 0;
        int top = 0;
        while (!q.empty()) {
            top = q.front();
            q.pop();
            for (const auto &e: keys[top]) {
                status[e] = true;
            }
            for (const auto &e: vect[top]) {
                if (visited[e] == false) {
                    q.push(e);
                    visited[e] = true;           
                }
            }
        }
        for (int i = 0; i != visited.size(); ++i) {
            if (visited[i] == true  && status[i] == true) {
                answer += candies[i];
            }
        }        
        return answer;
    }
};
*/

int main() {
  
  
  
  return 0;  
}
