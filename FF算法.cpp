#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn = 205;

struct edge {
	int to;//�յ�
	ll cap;//����
	int rev;//�����
};

int n, m, s, t;
vector<edge> G[maxn];//����ͼ��ÿ��vector��ɴ�ĵ�
bool used[maxn];//dfs���õ��ķ��ʱ��

void add_edge(int from, int to, ll cap) {
	G[from].push_back((edge) {
		to, cap, G[to].size()
	});
	G[to].push_back((edge) {
		from, 0, G[from].size() - 1
	});
}

ll dfs(int v, int t, ll flow) { //ȥ������·
	if (v == t) //�����㷵��
		return flow;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) { //��������ͼ
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) { //�¸����δ�����ʹ�����������·��������0����
			int d = dfs(e.to, t, min(flow, e.cap));
			if (d > 0) { //�ҵ�����·
				e.cap -= d; //����-d
				G[e.to][e.rev].cap += d; //���������d
				return d;
			}
		}
	}
	return 0;//û���ҵ�
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
