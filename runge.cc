#include <iostream>
#include <cmath>
#include <vector>

typedef std::vector<double> Vec;
using std::cout;


//This function returns the analytic value of x(t)
double analytic(double t) {
  return (1-exp(t*t))/(1+exp(t*t));
}

double f(double x,double t) {
  return t*(x*x-1);
}

double runge(double x_0, double t_0, double h, int n) {
  double x = x_0, t = t_0, k1, k2, k3, k4;
  for (int i=0; i<n; i++) {
    k1 = h*f(x,t);
    k2 = h*f((x+k1/2),(t+h/2));
    k3 = h*f((x+k2/2),(t+h/2));
    k4 = h*f((x+k3),(t+h));
    x += (k1 + 2*k2 +2*k3 + k4)/6;
    t += h;
  }
  return x;
}

int main(int argc, char const *argv[]) {
  double x_0 = 0, t_i = 0, t_f = 2;
  double ans = analytic(t_f);
  double h,n, diff;
  Vec step(5);
  step[0] = 0.001, step[1] = 0.005, step[2] = 0.01, step[3] = 0.05, step[4] = 0.1;
  for (int i=0;i<5;i++) {
    h = step[i];
    n = (t_f-t_i)/h;
    diff = fabs(runge(x_0,t_i,h,n)-ans);
    cout << h << ' ' << diff <<"\n";
  }

  return 0;
}
