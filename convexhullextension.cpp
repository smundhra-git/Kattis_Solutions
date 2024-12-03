#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL<<50;
typedef long long LL;
class Point {
  public:
  LL x, y;
  Point(LL _x=0, LL _y=0) : x(_x), y(_y) {}
  Point operator+(const Point p) { return Point(x+p.x, y+p.y); }
  Point operator-(const Point p) { return Point(x-p.x, y-p.y); }
  LL operator*(const Point p) { return x*p.x+y*p.y; }
  Point operator*(const LL k) { return Point(x*k, y*k); }
  LL operator^(const Point p) { return x*p.y-y*p.x; }
  Point& operator=(const Point p) {
    x=p.x; y=p.y;
    return *this;
  }
};

LL comparea(Point a, Point b, Point c, Point d) {
  LL t = a.x*b.y + b.x*c.y + c.x*d.y + d.x*a.y - a.y*b.x - b.y*c.x - c.y*d.x - d.y*a.x;
  return abs(t);
}
LL comparea3(Point a, Point b, Point c) {
  return comparea(a, b, c, c);
}
LL mygcd(LL x, LL y) {
  while(x!=0) { y%=x; swap(x, y); }
  return x+y;
}
LL solve(Point u, Point v, Point A, Point B) {
  Point C = v-u;
  
  LL g = mygcd(abs(A.x), abs(A.y));
  A.x/=g;A.y/=g;
  LL gg = mygcd(abs(B.x), abs(B.y));
  B.x/=gg;B.y/=gg;
  
  if ((A^B) > 0) return INF;
  if ((A^B) == 0) {
    // use Pick's theorem.
    LL area = comparea(u, v, v+A, u+A);
    if (area + 2 == 2 + 2) return 0;
    else return INF;
  }
  LL delta = (B^A);
  LL dS = (B^C); // s = dS/delta
  LL dT = (A^C); // t = dT/delta
  if (dS%delta==0) {
    A = A * (dS/delta);
    B = B * (dT/delta);
    
    assert(dS%delta==0 && dT%delta==0);
    assert((u+A).x==(v+B).x && (u+A).y == (v+B).y);
    Point w = u + A;
    // use Pick's theorem.
    LL area = comparea3(u, v, w);
    LL inside = area + 2 - mygcd(abs(C.x), abs(C.y)) - abs(dS/delta) - abs(dT/delta);
    assert(inside%2==0 && inside >= 0);
    inside/=2;
    return inside;
  }
  // bruteforce
  // Scale everything with delta, to avoid floating point issue.
  LL ux = u.x * delta;
  LL uy = u.y * delta;
  LL vx = v.x * delta;
  LL vy = v.y * delta;
  LL wx = u.x * delta + A.x * dS;
  LL wy = u.y * delta + A.y * dS;

  LL miny = min(uy, min(vy, wy));
  LL maxy = max(uy, max(vy, wy));
  LL total = 0;
  auto REM = [&](LL v) { return ((v%delta)+delta)%delta; };
  for (LL y = miny + REM(delta-miny); y <= maxy; y += delta) {
    if (C.y==0 && u.y * delta == y) continue;
    if (A.y==0 && u.y * delta == y) continue;
    if (B.y==0 && v.y * delta == y) continue;
    vector<LL> xs;
    if (min(uy, vy) <= y && y <= max(uy, vy)) {
      LL t = ux + (vx-ux)*(y-uy)/(vy-uy);
      xs.push_back(t);
    }
    if (min(vy, wy) <= y && y <= max(vy, wy)) {
      LL t = vx + (wx-vx)*(y-vy)/(wy-vy);
      xs.push_back(t);
    }
    if (min(wy, uy) <= y && y <= max(wy, uy)) {
      LL t = wx + (ux-wx)*(y-wy)/(uy-wy);
      xs.push_back(t);
    }
    assert(xs.size()>=2);
    sort(xs.begin(), xs.end());
    LL vl = xs[0] + REM(delta - xs[0]), vr = xs.back() - REM(xs.back());
    auto triarea = [&](LL ux, LL uy, LL vx, LL vy, LL wx, LL wy) {
      return abs(ux*vy - uy*vx + vx*wy - vy*wx + wx*uy - wy*ux);
    };
    auto should_not_count = [&](LL x, LL y) {
      auto a1 = triarea(ux, uy, vx, vy, x, y);
      auto a2 = triarea(ux, uy, x, y, wx, wy);
      auto a3 = triarea(x, y, vx, vy, wx, wy);
      auto a4 = triarea(ux, uy, vx, vy, wx, wy);
      return a1==0 || a2==0 || a3==0 || a4 != a1 + a2 + a3;
    };
    while (vl <= vr && should_not_count(vl, y)) vl += delta;
    while (vl <= vr && should_not_count(vr, y)) vr -= delta;
    LL vq = (vr - vl + delta) / delta;
    total += max(0LL, vq);
  }
  return total;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<Point> a(2*n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &a[i].x, &a[i].y);
    a[i+n] = a[i];
  }
  LL answer = 0;
  
  for(int i=1;i<=n;i++) {
    LL t = solve(a[i], a[i+1], a[i]-a[i-1], a[i+1]-a[i+2]);
    if (t == INF) {
      puts("infinitely many");
      return 0;
    }
    answer += t;
  }
  printf("%lld\n", answer);
  return 0;
}
