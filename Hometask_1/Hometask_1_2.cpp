#include <iostream>
using namespace std;

void Clock(int h, int m, int s, int passedseconds, int &returnH, int &returnM, int &returnS) {

    int passedhours = 0;
    int passedminutes = 0;

    passedhours = passedseconds/3600;
    passedseconds = passedseconds - passedhours*3600;
    passedminutes = passedseconds/60;
    passedseconds = passedseconds - passedminutes*60;

    returnH = (h + passedhours) % 24;
    returnM = (m + passedminutes) % 60;
    returnS = (s + passedseconds) % 60;

return;
}


int main() {

int h = 0;
int m = 0;
int s = 0;

Clock(1,2,3,3600,h,m,s);
cout << "The clock shows: " << h << ":" << m << ":" << s << endl;
return 0;
}