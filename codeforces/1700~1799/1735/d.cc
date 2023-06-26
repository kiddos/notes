#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<vector<int>> cards;
  for (int i = 0; i < n; ++i) {
    vector<int> features(k);
    for (int j = 0; j < k; ++j) {
      cin >> features[j];
    }
    cards.push_back(features);
  }

  auto to_hash = [&](vector<int>& feature) -> ll {
    ll ans = 0;
    for (int i = 0; i < feature.size(); ++i) {
      ans = ans * 3 + feature[i];
    }
    return ans;
  };

  vector<int> count(n);
  map<ll, int> index;
  for (int a = 0; a < n; ++a) {
    for (int b = 0; b < a; ++b) {
      ll hash2 = 0;
      for (int j = 0; j < k; ++j) {
        int f1 = cards[a][j];
        int f2 = cards[b][j];
        int f3 = f1 == f2 ? f1 : 3 - f1 - f2;
        hash2 = hash2 * 3 + f3;
      }

      if (index.count(hash2)) {
        count[a]++;
        count[b]++;
        count[index[hash2]]++;
      }
    }

    ll hash = to_hash(cards[a]);
    index[hash] = a;
  }

  for (int i = 0; i < n; ++i) {
    count[i] /= 2;
  }

  // for (int i = 0; i < n; ++i) cout << count[i] << " ";
  // cout << endl;

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (count[i] >= 2) {
      ans += count[i] * (count[i]-1) / 2;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
