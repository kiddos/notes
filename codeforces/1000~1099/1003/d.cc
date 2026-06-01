#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(q);
  for (int i = 0; i < q; ++i) {
    cin >> b[i];
  }

  vector<int> count(32);
  for (int i = 0; i < n; ++i) {
    for (int bit = 0; bit < 32; ++bit) {
      if (a[i] & (1<<bit)) {
        count[bit]++;
        break;
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    vector<int> require(32);
    for (int bit = 31; bit >= 0; --bit) {
      if (b[i] & (1<<bit)) {
        require[bit] = 1;
      }
    }

    int result = 0;
    vector<int> c = count;
    for (int bit = 31; bit >= 0; --bit) {
      if (require[bit]) {
        int take = min(require[bit], c[bit]);
        c[bit] -= take;
        require[bit] -= take;
        result += take;

        if (require[bit]) {
          if (bit > 0) {
            require[bit-1] += require[bit] * 2;
          } else {
            result = -1;
            break;
          }
        }
      }
    }
    ans.push_back(result);
  }

  for (int result : ans) {
    cout << result << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
