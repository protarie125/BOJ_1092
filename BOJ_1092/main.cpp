#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto wl = vi(n);
	for (auto&& w : wl) {
		cin >> w;
	}

	sort(wl.rbegin(), wl.rend());

	int m;
	cin >> m;

	auto ps = vi(m);
	for (auto&& x : ps) {
		cin >> x;
	}

	sort(ps.rbegin(), ps.rend());

	if (wl[0] < ps[0]) {
		cout << -1;
		return 0;
	}

	auto ans = int{ 0 };
	while (true) {
		auto c = int{ 0 };
		for (const auto& w : wl) {
			for (auto&& x : ps) {
				if (x <= w) {
					x = wl[0] + 1;
					++c;
					break;
				}
			}
		}

		if (0 == c) {
			break;
		}
		else {
			++ans;
		}
	}

	cout << ans;

	return 0;
}