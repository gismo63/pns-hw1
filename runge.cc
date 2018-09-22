#include <iostream>
using std::cout;

double f(double x,double t) {
  return t*(x*x-1);
}

int runge(double x_0, double t_0, double h, int n) {
  double x = x_0, t = t_0, k1, k2, k3, k4;
  for (int i=0; i<n; i++) {
    k1 = h*f(x,t);
    k2 = h*f((x+k1/2),(t+h/2));
    k3 = h*f((x+k2/2),(t+h/2));
    k4 = h*f((x+k3),(t+h));
    x += (k1 + 2*k2 +2*k3 + k4)/6;
    t += h;
    cout << t << " " << x << '\n';
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  double x_0 = 0, t_i = 0, t_f = 2;
  int n = 20;
  double h = (t_f-t_i)/n;

  runge(x_0,t_i,h,n);


  return 0;
}
