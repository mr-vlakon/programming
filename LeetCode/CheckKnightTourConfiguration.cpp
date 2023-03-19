class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int cnt = 0;
        int startRow = 0;
        int startCol = 0;
        int start = 0;
        if (grid[0][0] != 0)
            return false;
        ++start;
        bool status = false;
        while (cnt != (grid.size() * grid.size() - 1)) {
            status = false;
            if ((startRow + 2) < grid.size() && (startCol + 1) < grid[0].size() && grid[startRow + 2][startCol + 1] == start) {
                startRow = startRow + 2;
                startCol = startCol + 1;
                status = true;
            } else if ((startRow - 2) >= 0 && (startCol + 1) < grid[0].size() && grid[startRow - 2][startCol + 1] == start) {
                startRow = startRow - 2;
                startCol = startCol + 1;
                status = true;
            } else if ((startRow + 2) < grid.size() && (startCol - 1) >= 0 && grid[startRow + 2][startCol - 1] == start) {
                startRow = startRow + 2;
                startCol = startCol - 1;
                status = true;
            } else if ((startRow - 2) >= 0 && (startCol - 1) >= 0 && grid[startRow - 2][startCol - 1] == start) {
                startRow = startRow - 2;
                startCol = startCol - 1;
                status = true;
            } else if ((startRow - 1) >= 0 && (startCol - 2) >= 0 && grid[startRow - 1][startCol - 2] == start) {
                startRow = startRow - 1;
                startCol = startCol - 2;
                status = true;
            } else if ((startRow - 1) >= 0 && (startCol + 2) < grid[0].size() && grid[startRow - 1][startCol + 2] == start) {
                startRow = startRow - 1;
                startCol = startCol + 2;
                status = true;
            } else if ((startRow + 1) < grid.size() && (startCol + 2) < grid[0].size() && grid[startRow + 1][startCol + 2] == start) {
                startRow = startRow + 1;
                startCol = startCol + 2;
                status = true;
            } else if ((startRow + 1) < grid.size() && (startCol - 2) >= 0 && grid[startRow + 1][startCol - 2] == start) {
                startRow = startRow + 1;
                startCol = startCol - 2;
                status = true;
            } 
            if (!status) {
                return false;
            }
            ++start;
            ++cnt;
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}
