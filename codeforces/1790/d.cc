#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    map<int, int> dolls;
    for (int i = 0; i < n; ++i) {
      int d = 0;
      cin >> d;
      dolls[d]++;
    }

    int ans = 0;
    while (dolls.size() > 0) {
      vector<int> to_remove;
      for (auto it = dolls.begin(); it != dolls.end(); ++it) {
        if (it != dolls.begin() && it->first != prev(it)->first+1) {
          break;
        }
        it->second--;
        if (it->second == 0) to_remove.push_back(it->first);
      }

      for (int r : to_remove) dolls.erase(r);
      ans++;
    }

    cout << ans << endl;
  }
  return 0;
}
