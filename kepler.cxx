#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


int main(){
  //initial conditions
  const double e = 0.6; //eccentricity
  
  
  double t;
  double dt = 0.05;
  const double t_end = 20.0*M_PI;
  
  ofstream myfile;
  myfile.open ("ellipse.txt");
  
  double q1 = 1.0-e;
  double q2 = 0.0;
  double p1 = 0.0;
  double p2 = sqrt((1.0+e)/(1.0-e));
  
  double H = 0.5*(p1*p1+p2*p2) - 1/(sqrt(q1*q1+q2*q2));
  
    myfile << t << "\t" << H << "\t" << p1 << "\t" << p2 << "\t" << q1 << "\t" << q2 << endl;
    
  for(t=0.0; t<t_end; t+=dt){
    
    p1 = p1 - dt*q1*pow((q1*q1+q2*q2),-3.0/2.0);
    p2 = p2 - dt*q2*pow((q1*q1+q2*q2),-3.0/2.0);
    
    q1 = q1 + dt*p1;
    q2 = q2 + dt*p2;
    
    H = 0.5*(p1*p1+p2*p2) - 1/(sqrt(q1*q1+q2*q2));
    
    myfile << t << "\t" << H << "\t" << p1 << "\t" << p2 << "\t" << q1 << "\t" << q2 << endl;
  }
  //myfile << t << "\t" << p1 << "\t" << p2 << "\t" << q1 << "\t" << q2 << endl;
  
  myfile.close ();
  
 return 0; 
}