#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& a, int l, int r) {
  int pivot = a[r];
  int i = l;
  for (int j = l ; j < r; ++j) {
    if (a[j] < pivot) {
      swap(a[i++], a[j]);
    }
  }
  swap(a[i], a[r]);
  return i;
}

int quick_select(vector<int>& a, int l, int r, int k) {
  if (l < r) {
    int p = partition(a, l, r);
    if (p == k) return a[p];
    else if (p < k) {
      return quick_select(a, p+1, r, k);
    } else {
      return quick_select(a, l, p-1, k);
    }
  }
  return a[k];
}

int quick_select_iterative(vector<int>& a, int l, int r, int k) {
  while (l <= r) {
    int p = partition(a, l, r);
    if (p == k) return a[p];
    else if (p < k) {
      l = p + 1;
    } else {
      r = p - 1;
    }
  }
  return -1;
}


int main(void) {
  int n = 0;
  cin >> n;
  mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(0, n-1);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) a[i] = i+1;

  cout << "swapping values..." << endl;
  for (int i = 0; i < n; ++i) {
    int i1 = dist(gen);
    int i2 = dist(gen);
    swap(a[i1], a[i2]);
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

  int k = dist(gen);
  int ans = quick_select(a, 0, n-1, k);
  cout << (k+1) << "th smallest: " << ans << endl;

  ans = quick_select_iterative(a, 0, n-1, k);
  cout << (k+1) << "th smallest: " << ans << endl;

  return 0;
}
