/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/number-of-islands
@Language: C++
@Datetime: 16-07-26 08:46
*/

vector<vector<bool>>* pgrid;
int w = 0;
int h = 0;

class Solution {
public:
    int getXY(int x, int y) {
        if (x < 0 || x >= w) return 0;
        if (y < 0 || y >= h) return 0;
        return (*pgrid)[x][y] ? 1 : 0;
    }
    
    int numNeighbor(int x, int y) {
        int n = 0;
        n += getXY(x - 1, y);
        n += getXY(x + 1, y);
        n += getXY(x, y - 1);
        n += getXY(x, y + 1);
        return n;
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        pgrid = &grid;
        w = grid.size();
        if (w == 0) return 0;
        h = grid[0].size();
    
        int maxNeighbor;
        do {
            maxNeighbor = 0;
            bool hasOneNeighborCell = false;
            for (int x = 0; x < w; ++x) {
                for (int y = 0; y < h; ++y) {
                    if (grid[x][y]) {
                        // update min neighbor if the cell == 1
                        int numN = numNeighbor(x, y);
                        if (numN == 1) hasOneNeighborCell = true;
                        maxNeighbor = max(maxNeighbor, numN);
                    }
                }
            }
    
            if (hasOneNeighborCell == 1) { // if there are cell that has only 1 neighbor, remove it
                for (int x = 0; x < w; ++x) {
                    for (int y = 0; y < h; ++y) {
                        if (grid[x][y] && numNeighbor(x, y) == 1) {
                            grid[x][y] = false; // remove this cell
                        }
                    }
                }
            }
            else {
                for (int x = 0; x < w; ++x) {
                    for (int y = 0; y < h; ++y) {
                        if (grid[x][y] && numNeighbor(x, y) == 2) {
                            grid[x][y] = false; // remove this cell
                            goto out; // exit nested for
                        }
                    }
                }
            out:
                continue;
            }
        } while (maxNeighbor);
    
        // count 1s
        int num = 0;
        for (int x = 0; x < w; ++x) {
            for (int y = 0; y < h; ++y) {
                if (grid[x][y]) {
                    ++num;
                }
            }
        }
    
        return num;
    }
};