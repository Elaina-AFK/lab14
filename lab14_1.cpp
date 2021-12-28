#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double B[], int N, double ans[]){
    double a = 0; 
    for(int i = 0; i < N; i++){
        a += B[i];
    }
    ans[0] = a / N;
    a = 0;
    for(int i = 0; i < N; i++){
        a += pow(B[i] - ans[0], 2); 
    }
    ans[1] = sqrt(a / N); 
    a = 1;
    for(int i = 0; i < N; i++){
        a *= B[i];
    }
    ans[2] = pow(a, 1.0 / N);
    a = 0;
    for(int i = 0; i < N; i++){
        a += 1.0 / B[i];
    }
    ans[3] = N / a;
    a = B[0];
    for(int i = 1; i < N; i++){
        if(a < B[i]) a = B[i];
    }
    ans[4] = a;
    a = B[0];
    for(int i = 1; i < N; i++){
        if(a > B[i]) a = B[i];
    }
    ans[5] = a;
}