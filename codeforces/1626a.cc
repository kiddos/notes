#include <bits/stdc++.h>

using namespace std;

struct Character {
  char c;
  int count;
};

struct CompareCharacter {
  bool operator()(const Character& c1, const Character& c2) {
    return c1.count < c2.count;
  }
};

string solve(string s) {
  priority_queue<Character, vector<Character>, CompareCharacter> pq;
  unordered_map<char, int> count;
  for (char c : s) count[c]++;
  for (auto& p : count) {
    pq.push(Character{p.first, p.second});
  }

  string ans;
  while (pq.size() >= 2) {
    auto c1 = pq.top();
    pq.pop();
    auto c2 = pq.top();
    pq.pop();

    int size1 = min(c1.count, 2);
    c1.count -= size1;
    ans += string(size1, c1.c);
    int size2 = min(c2.count, 2);
    c2.count -= size2;
    ans += string(size2, c2.c);

    if (c1.count > 0) pq.push(c1);
    if (c2.count > 0) pq.push(c2);
  }
  if (!pq.empty()) {
    ans += string(pq.top().count, pq.top().c);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0 ;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string s;
    cin >> s;
    string ans = solve(s);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
