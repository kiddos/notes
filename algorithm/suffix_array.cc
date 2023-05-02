#include <bits/stdc++.h>

using namespace std;

#define ALPHABET 256

vector<int> sort_cyclic_shift(const string& s) {
  int n = s.length();
  vector<int> p(n), c(n), chars(ALPHABET);
  for (char ch : s) {
    chars[ch]++;
  }
  for (int i = 1; i < ALPHABET; ++i) {
    chars[i] += chars[i-1];
  }
  for (int i = n-1; i >= 0; --i) {
    p[--chars[s[i]]] = i;
  }

  c[p[0]] = 0;
  int classes = 1;
  for (int i = 1; i < n; ++i) {
    if (s[p[i]] != s[p[i-1]]) {
      classes++;
    }
    c[p[i]] = classes-1;
  }

  vector<int> pn(n), cn(n), chars_n(n);
  for (int k = 0; (1<<k) < n; ++k) {
    for (int i = 0; i < n; ++i) {
      pn[i] = (p[i] - (1<<k) + n) % n;
    }

    fill(chars_n.begin(), chars_n.end(), 0);
    for (int i = 0; i < n; ++i) {
      chars_n[c[pn[i]]]++;
    }
    for (int i = 1; i < n; ++i) {
      chars_n[i] += chars_n[i-1];
    }
    for (int i = n-1; i >= 0; --i) {
      p[--chars_n[c[pn[i]]]] = pn[i];
    }
    cn[p[0]] = 0;
    classes = 1;
    for (int i = 1; i < n; ++i) {
      pair<int,int> current = {c[p[i]], c[(p[i] + (1<<k)) % n]};
      pair<int,int> pre = {c[p[i-1]], c[(p[i-1] + (1<<k)) % n]};
      if (current != pre) {
        classes++;
      }
      cn[p[i]] = classes-1;
    }
    c.swap(cn);
  }
  return p;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "aabbaacc$";
  // string s = "aaba";
  vector<int> p = sort_cyclic_shift(s);
  for (int idx : p) cout << idx << " ";
  cout << endl;
  return 0;
}
