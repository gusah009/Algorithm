#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define C(a) (a<0?-1:1)
#define FOR(i,j) for (int i=0;i<j;i++)
#define N d[n]
#define M d[!n]

double T,a[2],b[2],s[2],pd,dis,p1,p2;
int d[2],K,d1,d2,f;
vector<double> x(53),y(53);
bool n,s1=1,dir=0;

double id(bool type,int k)
{
  double di;
  if (a[type]==x[k+1]) {
    di=abs(b[type]-y[k+1]);
  } else{
    di=abs(a[type]-x[k+1]);
  }
  return di;
}
double rd(bool type,int l)
{
  double di;
  if (a[type]==x[l-1]) {
    di=abs(b[type]-y[l-1]);
  } else{
    di=abs(a[type]-x[l-1]);
  }
  return di;
}

int main()
{
  cin >> K;
  FOR(i,K)
    cin >> x[i] >> y[i];
  x[K]=x[0];
  y[K]=y[0];
  a[0]=x[0];
  b[0]=y[0];
  a[1]=x[K/2-1];
  b[1]=y[K/2-1];
  d[0]=0,d[1]=K/2-1;
  
  if (K <= 2) {
    d1 = -1;
    d2 = -1;
  } else {
    FOR(i,K) {
      if (i==K/2-1) {
        p1=dis/2;
        dis=0;
      }
      dis += abs(x[i]-x[i+1]+y[i]-y[i+1]);
    }
    p2=dis/2+p1*2;
    dis=0;
    auto xb=x.begin();
    auto yb=y.begin();
    for(int i=1;i<K+2;i++) {
      pd=dis;
      dis += abs(x[i]-x[i-1]+y[i]-y[i-1]);
      if (s1 && p1<dis) {
        d1=i;
        if (p1==pd) {
          d1=i-1;
        } else {
          if (x[i-1]==x[i]) {
            xb=x.insert(xb+1,x[i]);
            yb=y.insert(yb+1,y[i-1]+C(y[i]-y[i-1]) * (p1-pd));
          } else {
            xb=x.insert(xb+1,x[i-1]+C(x[i]-x[i-1]) * (p1-pd));
            yb=y.insert(yb+1,y[i]);
          }
          d[1]++;
          a[1] = x[d[1]];
          b[1] = y[d[1]];
          i++;
          K++;
        }
        s1=0;
      }
      if (p2<dis) {
        d2=i;
        if (x[i-1]==x[i]) {
          if (p2==pd) {
            d2=i-1;
          } else {
            x.insert(xb+1,x[i]);
            y.insert(yb+1,y[i-1]+C(y[i]-y[i-1]) * (p2-pd));
            K++;
          }
        } else {
          if (p2==pd) {
            d2=i-1;
          } else {
            y.insert(yb+1,y[i]);
            x.insert(xb+1,x[i-1]+C(x[i]-x[i-1]) * (p2-pd));
            K++;
          }
        }
        break;
      }
      xb++;
      yb++;
    }
  }

  cin >> T;
  while(true) {
    if (!dir) {
      d[0] %= K;
      d[1]==0 ? d[1]=K : d[1] ;
    } else {
      d[1] %= K;
      d[0]==0 ? d[0]=K : d[0] ;
    }
    if (K==1 || T==0)
      break;

    if (!dir) {
      s[0]=id(0,d[0]);
      s[1]=rd(1,d[1]);
    } else {
      s[1]=id(1,d[1]);
      s[0]=rd(0,d[0]);
    }

    n=s[0] > s[1] ? true: false;
    f = dir != n ? -1 : 1;

    if (s[n] > T) {
      if (a[n]==x[N+f]) {
        b[n] += C(y[N+f]-b[n]) * T;
      } else {
        a[n] += C(x[N+f]-a[n]) * T;
      }
      s[n]=T;
      T=0;
    } else {
      a[n]=x[N+f];
      b[n]=y[N+f];
      N+=f;
      T -= s[n];
    }

    f = dir != n ? 1 : -1;
    if (a[!n]==x[M+f]) {
      b[!n] += C(y[M+f]-b[!n]) * s[n];
      if (y[M+f]==b[!n])
        M+=f;
    } else {
      a[!n] += C(x[M+f]-a[!n]) * s[n];
      if (x[M+f]==a[!n])
        M+=f;
    }
  
    if (!dir) {
      d[0] %= K;
      d[1]==0 ? d[1]=K : d[1] ;
    } else {
      d[1] %= K;
      d[0]==0 ? d[0]=K : d[0] ;
    }
    
    if (d[0]==d1 && d[1]==d1 || d[0]==d2 && d[1]==d2) {
      dir=!dir;
    }
  }
  cout << a[0] << " " << b[0] << "\n";
  cout << a[1] << " " << b[1] << "\n";
}