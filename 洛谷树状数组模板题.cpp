#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll An[5000100] = {0}, Cn[5000100] = {0};
ll lowbit(int x) {
	return (x & -x);
}
void update(int x, int val) {
	for (ll i = x; i <= n; i += lowbit(i)) {
		Cn[i] += val;
	}
}
ll get_sum(int a) {
	ll ans_a = 0;
	for (ll i = a; i > 0; i -= lowbit(i)) {
		ans_a += Cn[i];
	}
	return ans_a;
}
int main() {
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> An[i];
		update(i, An[i]-An[i-1]);
	}
	ll a = 0, x, y, k;
	for (ll i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> x >> y >> k;
			An[x]+=k;
			update(x, k);
			An[y+1]+=-k;
			update(y+1,-k);
		}
		if (a == 2) {
			cin >> k;
			cout << get_sum(k) << endl;
		}
	}
}

