#include <iostream>
#include <vector>

typedef std::vector<double> Vec;
using std::cout;


//Here we overload the * operator so that a Vec type can be multiplied by a scalar on the right
Vec operator*(Vec x, double factor) {
  for (size_t i=0;i<x.size();i++) { // Here we use size_t because x.size() is an unsigned integer so we also make i and unsigned integer for comparison purposes
    x[i] = (x[i]*factor);
  }
  return x;
}

//same as above but by scalar on left
Vec operator*(double factor, Vec x) {
  for (size_t i=0;i<x.size();i++) {
    x[i] = (x[i]*factor);
  }
  return x;
}

//Here we overload the / operator so that a Vec type can be divided by a scalar
Vec operator/(Vec x, double denom) {
  for (size_t i=0;i<x.size();i++) {
    x[i] = (x[i]/denom);
  }
  return x;
}

//Here we overload the + operator so that two Vecs can be added
Vec operator+(Vec x, const Vec& y){
  for (size_t i=0;i<x.size();i++) {
    x[i] = (x[i] + y[i]);
  }
  return x;
}

//This function takes all x_i in vector form and returns f_i(x,t) in vector form where f_i = d(x_i)/dt
Vec f(const Vec& x, double t, double a, double b, double c){
  Vec y(3);
  y[0] = (-x[1]-x[2]);
  y[1] = (x[0]+a*x[1]);
  y[2] = (b+x[2]*(x[0]-c));
  return y;
}

//This function runs one iteration of the runge-kutta algorithm for any number of first order differential equations, takes x[t] and returns x[t+h]
Vec steps(Vec x, double t, double h, double a, double b, double c) {
  Vec k1(3), k2(3), k3(3), k4(3);
  k1 = h*f(x,t,a,b,c);
  k2 = h*f((x+k1/2),(t+h/2),a,b,c);
  k3 = h*f((x+k2/2),(t+h/2),a,b,c);
  k4 = h*f((x+k3),(t+h),a,b,c);
  x = x + (k1 + 2*k2 +2*k3 + k4)/6;
  return x;
}


int main(int argc, char const *argv[]) {
  Vec x(3);
  x[0]=0;
  x[1]=0;
  x[2]=0;//initial conditions
  double a=0.2, b=0.2, c=5.7, t_f=50, t = 0;
  int n = 100000;//number of iterations
  double h = (t_f-t)/n;//step size

  for (int i=0; i<n; i++) { //run the runge kutta algoithm n times
    x = steps(x,t,h,a,b,c);
    t += h;
  }
  for (size_t i=0;i<x.size();i++) { // Here we use size_t because x.size() is an unsigned integer so we also make i and unsigned integer for comparison purposes
    cout <<"x"<<i<<"[50] = "<< x[i] << '\n';
  }
  return 0;
}
