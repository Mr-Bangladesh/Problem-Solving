#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 1e5 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

int phi[Max];

void phigen(int n) {
        for(int i = 1; i <= n; i++) {
                phi[i] = i;
        }
        for(int p = 2; p <= n; p++) {
                if(phi[p] == p) {
                        phi[p] = p - 1;
                        for(int i = 2 * p; i <= n; i += p) {
                                phi[i] = (phi[i] / p) * (p - 1);
                        }
                }
        }
}

int seg[Max * 4];

void build(int node, int l, int r) {
        if(l == r) {
                seg[node] = 0;
                return;
        }
        int mid = (l + r) >> 1;
        int lf = node * 2;
        int rt = node * 2 + 1;
        build(lf, l, mid);
        build(rt, mid + 1, r);
        seg[node] = seg[lf] + seg[rt];
}

int update(int node, int l, int r, int idx, int val) {
        if(l == r) {
                seg[node] = val;
                return seg[node];
        }
        int mid = (l + r) >> 1, u = seg[node * 2], v = seg[node * 2 + 1];
        if(mid >= idx) {
                u = update(2 * node, l, mid, idx, val);
        }
        else {
                v = update(2 * node + 1, mid + 1, r, idx, val);
        }
        return seg[node] = u + v;
}

int findkth(int node, int l, int r, int k) {
        if(l >= r) {
                return l;
        }

        int mid = (l + r) >> 1;

        if(seg[node * 2] >= k) {
                return findkth(node * 2, l, mid, k);
        }
        else {
                return findkth(node * 2 + 1, mid + 1, r, k - seg[node * 2]);
        }
}


int mp[Max];

int BLOCK_SIZE;
int cnt;

int ar[Max];
int ans[Max];

struct Node {
        int l, r, k, id;

        Node() {};

        Node(int l_, int r_, int k_, int id_) {
                l = l_;
                r = r_;
                k = k_;
                id = id_;
        }

        bool operator<(const Node &b) const {
                if(l / BLOCK_SIZE < b.l / BLOCK_SIZE) {
                        return 1;
                }
                if(l / BLOCK_SIZE > b.l / BLOCK_SIZE) {
                        return 0;
                }
                return ((l / BLOCK_SIZE) & 1) ? r < b.r : r > b.r;
        }
} qr[Max];

void add(int x) {
        mp[x]++;
        if(mp[x] == 1) {
                update(1, 1, 1e5, x, 1);
        }
}

void del(int x) {
        mp[x]--;
        if(mp[x] == 0) {
                update(1, 1, 1e5, x, 0);
        }
}

int main() {
#ifdef Mr_Emrul
        freopen("inputf.in", "r", stdin);
#endif ///Mr_Emrul

        //ios_base::sync_with_stdio(false);
        //cin.tie(0);

        int t, n, m, k, l, r;
        scanf("%d", &t);
        for(int tc = 1; tc <= t; tc++) {
                scanf("%d %d", &n, &m);
                BLOCK_SIZE = 361;
                memset(mp, 0, sizeof mp);
                build(1, 1, 1e5);
                phigen(n);

                for(int i = 1; i <= n; i++) {
                        ar[i] = phi[i];
                }

                for(int i = 1; i <= m; i++) {
                        scanf("%d %d %d", &l, &r, &k);
                        qr[i] = Node(l, r, k, i);
                }
                sort(qr + 1, qr + m + 1);
                int L = 1, R = 0;
                for(int i = 1; i <= m; i++) {
                        int l = qr[i].l;
                        int r = qr[i].r;
                        int k = qr[i].k;

                        while(R < r) {
                                R++;
                                add(ar[R]);
                        }
                        while(R > r) {
                                del(ar[R]);
                                R--;
                        }

                        while(L < l) {
                                del(ar[L]);
                                L++;
                        }

                        while(L > l) {
                                L--;
                                add(ar[L]);
                        }
                        //cout<<l<<" "<<r<<endl;
                        int tot = findkth(1, 1, 1e5, k);
                        ans[qr[i].id] = tot;
                }
                printf("Case %d:\n", tc);
                for(int i = 1; i <= m; i++) {
                        if(ans[i] == 1e5) {
                                printf("No Distinct Phi Number\n");
                                continue;
                        }
                        printf("%d\n", ans[i]);
                }
        }
        return 0;
}
