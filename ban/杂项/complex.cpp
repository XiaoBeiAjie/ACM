#include <bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
struct Complex 
{
    double x,y;
    Complex(double _x=0.0,double _y=0.0):x(_x),y(_y){}
    Complex operator-(const Complex &b) const {return Complex(x-b.x,y-b.y);}
    Complex operator+(const Complex &b) const {return Complex(x+b.x,y+b.y);}
    Complex operator*(const Complex &b) const {return Complex(x*b.x-y*b.y,x*b.y+y*b.x);}
};
int main()
{

}