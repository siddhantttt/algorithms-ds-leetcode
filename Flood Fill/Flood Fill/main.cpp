//Problem: https://leetcode.com/explore/learn/card/queue-stack/239/conclusion/1393/
//Try Doing using stack, recursion solution accepted.


#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


class Solution {
public:
    
    void floodFillHelper(vector<vector<int>>& image, vector<vector<bool>>& visited, int i, int j, int newColor, int color){
        
        if (i >= image.size() || i < 0 || j >= image[0].size() || j < 0 || visited[i][j] == 1)
            return;
        
        if (image[i][j] != color)
            return;
        
        
        image[i][j] = newColor;
        visited[i][j] = true;
        
        floodFillHelper(image, visited, i-1, j, newColor, color);
        floodFillHelper(image, visited, i+1, j, newColor, color);
        floodFillHelper(image, visited, i, j+1, newColor, color);
        floodFillHelper(image, visited, i, j-1, newColor, color);

    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if (sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0)
            return image;
        
        vector<vector<bool>> visited;
        for (int i = 0; i<image.size(); i++){
            vector<bool> inner(image[0].size(), false);
            visited.push_back(inner);
        }
        
        int color = image[sr][sc];
        
        floodFillHelper(image, visited, sr, sc, newColor, color);
        
        return {};
    }
};


int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    Solution().floodFill(image, sr, sc, newColor);
    cout << "Nothing";
    
}
