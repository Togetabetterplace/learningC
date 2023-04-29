#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn = 205;

struct edge {
	int to;//终点
	ll cap;//容量
	int rev;//反向边
};

int n, m, s, t;
vector<edge> G[maxn];//整个图，每个vector存可达的点
bool used[maxn];//dfs中用到的访问标记

void add_edge(int from, int to, ll cap) {
	G[from].push_back((edge) {
		to, cap, G[to].size()
	});
	G[to].push_back((edge) {
		from, 0, G[from].size() - 1
	});
}

ll dfs(int v, int t, ll flow) { //去找增广路
	if (v == t) //到达汇点返回
		return flow;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) { //遍历整幅图
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) { //下个结点未被访问过，并且这条路容量大于0就走
			int d = dfs(e.to, t, min(flow, e.cap));
			if (d > 0) { //找到增广路
				e.cap -= d; //容量-d
				G[e.to][e.rev].cap += d; //反向边增加d
				return d;
			}
		}
	}
	return 0;//没有找到
}

ll get_maxFlow(int s, int t) {
	ll maxFlow = 0;
	for (;;) {
		memset(used, 0, sizeof(used));
		ll f = dfs(s, t, INF);
		if (f == 0)
			return maxFlow;
		maxFlow += f;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> s >> t;
	int u, v;
	ll w;
	while (m--) {
		cin >> u >> v >> w;
		add_edge(u, v, w);
	}
	ll ans = get_maxFlow(s, t);
	cout << ans << endl;
	return 0;
}
