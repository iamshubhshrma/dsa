// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <stdio.h>
void insert(int *a,int pos,int ele ){
    for (int i = 4; i>=pos;i--){
        a[i]=a[i-1];
    }
    a[pos] = ele;
}

int main() {
    // Write C++ code here
    cout << "array inserting";
    int  a[5];
    cout<<a<<endl;
    insert(a,0,10);
    insert(a,1,11);
    insert(a,2,22);
    insert(a,3,33);
    insert(a,4,44);
    insert(a,5,55);
    cout<<a[0]<<endl;
    cout<<a[1]<<endl;
    cout<<a[2]<<endl;
    cout<<a[3]<<endl;
    cout<<a[4]<<endl;
    cout<<a[5]<<endl;
    printf("\n\n%d",a[4]);

    return 0;
}