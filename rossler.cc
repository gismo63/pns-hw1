#include <iostream>
#include <vector>

typedef std::vector<double> Vec;
using std::cout;

Vec f(const Vec& x, double t, double a, double b, double c){
  Vec f(3);
  f[0] = (-x[1]-x[2]);
  f[1] = (x[0]+a*x[1]);
  f[2] = (b-x[2]*(x[0]-c));
  return f;
}

Vec steps(Vec x, double t, double h, double a, double b, double c) {
  Vec k1(3), k2(3), k3(3), k4(3);
  k1 = f(x,t,a,b,c);
  k2 = h*f((x+k1/2),(t+h/2),a,b,c);
  k3 = h*f((x+k2/2),(t+h/2),a,b,c);
  k4 = h*f((x+k3),(t+h),a,b,c);
  for (i=0, i<k1.size(), i++){
    x[i] += (k1[i] + 2*k2[i] +2*k3[i] + k4[i])/6;
  }
  return x;
}

int main(int argc, char const *argv[]) {
  std::vector<double> x(3);
  x[0]=0;
  x[1]=0;
  x[2]=0;
  double a=0.2, b=0.2, c=5.7, t=0
  int n = 20;
  double h = (t_f-t_i)/n;
  x = f(x,t,h,a,b,c);
  cout << x[0] << '\n';
  return 0;








}
