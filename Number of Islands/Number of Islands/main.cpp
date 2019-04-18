//Problem: https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1380/
//Solution: https://www.youtube.com/watch?v=CLvNe-8-6s8


#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

class Solution {
public:
    void changeLandToWater(vector<vector<char>>& grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        changeLandToWater(grid, i+1, j);
        changeLandToWater(grid, i-1, j);
        changeLandToWater(grid, i, j-1);
        changeLandToWater(grid, i, j+1);
        
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        stack <int> row, column;
        int islandCount = 0;
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j<grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    islandCount++;
                    changeLandToWater(grid, i, j);
                }
                
            }
        }
        return islandCount;
    }
};

int main(){
    
    vector<vector<char>> grid{
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','1'},
        { '0','0','0','1','0'}};
    
    
    cout << Solution().numIslands(grid);
    
    
}
