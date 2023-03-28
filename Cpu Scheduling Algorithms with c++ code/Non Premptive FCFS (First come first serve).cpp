#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;

const int N = 555;

bool cmp(pair<pair<int,int>,int>& a,pair<pair<int,int>,int>& b) {
  if (a.F.S == b.F.S) {
    return a.S < b.S;
  }
  return a.F.S < b.F.S;
}

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector< pair<pair<int,int>,int> > v;

  vector<int> at(n + 1,0),bt(n + 1,0);
  for (int i = 0;i < n;i++) {
    int id,a,b;
    cin >> id >> a >> b;
    at[id] = a;
    bt[id] = b;
    v.pb({{id,a},b});
  }
  sort(all(v),cmp);

  vector<int> ct(n + 1,0),wt(n + 1,0),tat(n + 1,0);

  int time = 0,cnt = 0,i = 0;
  while (i < n) {
    int cur = v[i].F.F;
    if (at[cur] > time) {
      time = time + (at[cur] - time);
      continue;
    }
    time = time + bt[cur];
    ct[cur] = time;
    tat[cur] = ct[cur] - at[cur];
    wt[cur] = tat[cur] - bt[cur];
    i++;
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
