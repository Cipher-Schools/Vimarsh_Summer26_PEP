class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            // 1. Move left to right across top boundary
            for (int j = left; j <= right; j++) result.push_back(matrix[top][j]);
            top++;
            
            // 2. Move top to bottom along right boundary
            for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
            right--;
            
            // 3. Move right to left across bottom boundary (check if row still valid)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) result.push_back(matrix[bottom][j]);
                bottom--;
            }
            
            // 4. Move bottom to top along left boundary (check if col still valid)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
                left++;
            }
        }
        return result;
    }
};