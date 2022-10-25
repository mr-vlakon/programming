class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) : rec(rectangle) {
        
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        while (row1 <= row2) {
            int tmp = col1;
            while (tmp <= col2) {
                rec[row1][tmp] = newValue;
                ++tmp;
            }
            ++row1;
        }
    }
    
    int getValue(int row, int col) {
        return rec[row][col];
    }
private:
    vector<vector<int>> rec;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

int main() {
  
  
  
  return 0;  
}
