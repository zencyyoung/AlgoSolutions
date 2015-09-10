#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int INF = INT_MAX / 2;
int w[maxn][maxn];
int lx[maxn], ly[maxn], linky[maxn], slack[maxn];
bool visx[maxn], visy[maxn];
int nx, ny;
bool dfs(int x) {
    visx[x] = true;
    for (int y = 0; y < ny; ++y) {
        if (visy[y]) continue;
        int t = lx[x] + ly[y] - w[x][y];
        if (t == 0) {
            visy[y] = true;
            if (linky[y] == -1 || dfs(linky[y])) {
                linky[y] = x;
                return true;
            }
        }
        else if (slack[y] > t)
            slack[y] = t;
    }
    return false;
}
inline int KM() {
    int i, j;
    memset(linky, -1, sizeof linky);
    memset(ly, 0 , sizeof ly);
    for (i = 0; i < nx; ++i) {
        lx[i] = *max_element(w[i], w[i] + ny);
    }
    for (int x = 0; x < nx; ++x) {
        for (i = 0; i < ny; ++i) slack[i] = INF;
        while (true) {
            memset(visx, 0, sizeof visx);
            memset(visy, 0, sizeof visy);
            if (dfs(x)) break;
            int d = INF;
            for (i = 0; i < ny; ++i) {
                if (!visy[i] && d > slack[i]) d = slack[i];
            }
            for (i = 0; i < nx; ++i) {
                if (visx[i]) lx[i] -= d;
            }
            for(i = 0; i < ny; ++i) {
                if (visy[i]) ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for (i = 0; i < ny; ++i) {
        if (linky[i] >= 0) res += w[linky[i]][i];
    }
    return res;
}
int main() {
    return 0;
}
