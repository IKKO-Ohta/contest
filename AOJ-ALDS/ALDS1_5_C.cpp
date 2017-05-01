//
// Created by 司田行史 on 2016/03/19.
//

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct point { double x,y;};

void koch(int n,point a,point b){
    if(n == 0) return;
    point s,t,u;
    double th = M_PI * 60.0 / 180.0;

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(n-1,a,s);
    cout <<  setprecision(9) << s.x << " " << setprecision(9) << s.y << endl;
    koch(n-1,s,u);
    cout <<  setprecision(9) << u.x << " " <<  setprecision(9) << u.y << endl;
    koch(n-1,u,t);
    cout <<  setprecision(9) << t.x << " " <<  setprecision(9) << t.y << endl;
    koch(n-1,t,b);
}

int main (){
    point a,b;
    int n;

    cin >> n;
    a.x = 0; a.y = 0;
    b.x = 100; b.y = 0;

    cout << setprecision(9) << a.x << " " <<  setprecision(9) << a.y << endl;
    koch(n,a,b);
    cout << setprecision(9) << b.x << " " <<  setprecision(9) << b.y << endl;
    return 0;
}