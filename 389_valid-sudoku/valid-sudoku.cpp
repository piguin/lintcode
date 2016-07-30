/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/valid-sudoku
@Language: C++
@Datetime: 16-07-26 07:09
*/

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        vector<int> xflags(9);
        vector<int> yflags(9);
        vector<int> zflags(9);
        
        // every number belong to three groups, there can't be dup numbers in each group
        // x, y group are based on the number index, z is calculated as this
        auto const &zindex = [] (int x, int y) { return (x / 3) * 3 + y / 3; };
        
        for (int x = 0; x < 9; ++x) {
            for (int y = 0; y < 9; ++y) {
                char c = board[x][y];
                if (c >= '0' && c <= '9') {
                    int flag = 0x1 << (c - '0' );
                    int z = zindex(x, y);
                    if (xflags[x] & flag) return false;
                    if (yflags[y] & flag) return false;
                    if (zflags[z] & flag) return false;
                    
                    xflags[x] |= flag;
                    yflags[y] |= flag;
                    zflags[z] |= flag;
                }
            }
        }
        
        return true;
    }
};