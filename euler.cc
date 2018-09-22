#include <iostream>
using std::cout;

double f(double x,double t) {
  return t*(x*x-1);
}

int euler(double x_0,double t_0, double h, int n) {
  double x = x_0, t = t_0;
  for (int i=0; i<n; i++) {
    x += h*f(x,t);
    t += h;
    cout << t << " " << x << '\n';
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  double x_0 = 0, t_i = 0, t_f = 2;
  int n = 20;
  double h = (t_f-t_i)/n;

  euler(x_0,t_i,h,n);


  return 0;
}
