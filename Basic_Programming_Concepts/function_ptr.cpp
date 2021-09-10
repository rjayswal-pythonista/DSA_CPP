#include<iostream>
using namespace std;

int max(int x, int y) {
    return x>y?x:y;
}

int min(int x, int y) {
    return x<y?x:y;
}

int main() {
    int (*fp)(int, int);
    fp = &max;                 // int (*fp)(int, int) = &max;
    cout<<"Max value: "<<(*fp)(10,8)<<endl;
    fp = &min;
    cout<<"Min value: "<<(*fp)(10,8)<<endl;
return 0;
}