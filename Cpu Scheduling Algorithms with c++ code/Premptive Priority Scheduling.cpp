#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
 
const int N = 555;

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> a(n + 1),b(n + 1),p(n + 1),x(n + 1);
  for (int i = 1;i <= n;i++) {
    cin >> a[i];
  }
  for (int i = 1;i <= n;i++) {
    cin >> b[i];
    x[i] = b[i];
  }
  for (int i = 1;i <= n;i++) {
    cin >> p[i];
  }

  int time = 0,cnt = 0;
  vector<int> ct(n + 1,0),wt(n + 1,0),tat(n + 1,0);

  p[n + 5] = -1;
  while (cnt < n) {
    int mn = n + 5;

    for (int i = 1;i <= n;i++) {
      if (a[i] <= time && p[i] > p[mn] && b[i] > 0) {
        mn = i;
      }
    }
    b[mn]--;

    if (b[mn] == 0) {
      ct[mn] = time + 1;
      tat[mn] = ct[mn] - a[mn];
      wt[mn] = tat[mn] - x[mn];
      cnt++;
    }
    time++;
  }

  double tot1 = 0,tot2 = 0;
  for (int i = 1;i <= n;i++) {
    tot1 += tat[i];
    tot2 += wt[i];
  }
  tot1 = tot1 / (n * 1.0);
  tot2 = tot2 / (n * 1.0);
  cout << "Average turn around time: " << tot1 << '\n';
  cout << "Average waiting time: " << tot2 << '\n';
  return 0;
}
