//733. Flood Fill

// Similar to previous

//CODE
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int start = image[sr][sc];
        if(start != color){
            image[sr][sc] = color;
        }else{
            return image;
        }
        q.push({sr,sc});
        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            int first = cell.first;
            int second = cell.second;
            for(int d=0 ; d<4 ; d++){
                int nx = first+dx[d];
                int ny = second+dy[d];
                if(nx >=0 && ny>=0 && nx<n && ny<m && image[nx][ny] == start){
                    image[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
        
    }
};
