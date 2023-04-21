class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> answer;
        vector<vector<bool>> visited(8, vector<bool>(8, false));
        for (const auto &e: queens) {
            visited[e[0]][e[1]] = true;
        }
        int start = king[0];
        int startC = king[1];
        while (start >= 0 && startC >= 0) {
            if (visited[start][startC] == true) {
                answer.push_back({start, startC});
                break;
            }
            --start;
            --startC;
        }
        start = king[0];
        startC = king[1];
        while (start < 8 && startC < 8) {
            if (visited[start][startC] == true) {
                answer.push_back({start, startC});
                break;
            }
            ++start;
            ++startC;
        }   
        start = king[0];
        startC = king[1];
        while (startC < 8 && start >= 0) {
            if (visited[start][startC] == true) {
                answer.push_back({start, startC});
                break;
            }
            --start;
            ++startC;
        }
        start = king[0];
        startC = king[1];
        while (start < 8 && startC >= 0) {
            if (visited[start][startC] == true) {
                answer.push_back({start, startC});
                break;
            }
            ++start;
            --startC;
            
        }  
        start = king[0];
        while (start >= 0) {
            if (visited[start][king[1]] == true) {
                answer.push_back({start, king[1]});
                break;
            }
            --start;
        }
        start = king[0];
        while (start < 8) {
            if (visited[start][king[1]] == true) {
                answer.push_back({start, king[1]});
                break;
            }
            ++start;
        }
        start = king[1];
        while (start >= 0) {
            if (visited[king[0]][start] == true) {
                answer.push_back({king[0], start});
                break;
            }
            --start;
        }
        start = king[1];
        while (start < 8) {
            if (visited[king[0]][start] == true) {
                answer.push_back({king[0], start});
                break;
            }
            ++start;
        }
        return answer;    
    }
};

int main() {
  
  
  
  
  return 0;  
}
