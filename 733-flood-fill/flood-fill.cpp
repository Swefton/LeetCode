class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int colorCurr, int colorChange) {
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != colorCurr) {
            return;
        }

        image[r][c] = colorChange;

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (auto& dir : directions) {
            dfs(image, r + dir.first, c + dir.second, colorCurr, colorChange);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int colorCurr = image[sr][sc];
        if (colorCurr != color) {
            dfs(image, sr, sc, colorCurr, color);
        }
        return image;
    }
};