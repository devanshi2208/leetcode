class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr, sc, totalL = 0;

    
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L')
                    litterId[i][j] = totalL++;
            }
        }

        int fullMask = (1 << totalL) - 1;

        
        queue<tuple<int, int, int, int>> q;


        vector<vector<vector<int>>> visited(
            m, vector<vector<int>>(n, vector<int>(1 << totalL, -1))
        );

        q.push({sr, sc, 0, energy});
        visited[sr][sc][0] = energy;

        int moves = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X' || e == 0)
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    
                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << litterId[nr][nc]);
                    }

        
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Visit only if we reach this state with more energy
                    if (visited[nr][nc][newMask] >= newEnergy)
                        continue;

                    visited[nr][nc][newMask] = newEnergy;
                    q.push({nr, nc, newMask, newEnergy});
                }
            }

            moves++;
        }

        return -1;
    }
};