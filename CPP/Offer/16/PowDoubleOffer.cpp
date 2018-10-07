// 
// Created by Insomnia on 18-10-7.
//


#include <iostream>
using namespace std;


float pow(float base, float ex);

float nth_root(float A, int n) {
    const int K = 6;
    float x[K] = {1};
    for (int k = 0; k < K - 1; k++)
        x[k + 1] = (1.0 / n) * ((n - 1) * x[k] + A / pow(x[k], n - 1));
    return x[K-1];
}

float pow(float base, float ex){
    if (base == 0)
        return 0;
    // power of 0
    if (ex == 0){
        return 1;
        // negative exponenet
    }else if( ex < 0){
        return 1 / pow(base, -ex);
        // fractional exponent
    }else if (ex > 0 && ex < 1){
        return nth_root(base, 1/ex);
    }else if ((int)ex % 2 == 0){
        float half_pow = pow(base, ex/2);
        return half_pow * half_pow;
        //integer exponenet
    }else{
        return base * pow(base, ex - 1);
    }
}
int main(int, char **){
    for (int ii = 0; ii< 10; ii++){\
        cout << "pow(" << ii << ", .5) = " << pow(ii, .5) << endl;
        cout << "pow(" << ii << ",  2) = " << pow(ii,  2) << endl;
        cout << "pow(" << ii << ",  3) = " << pow(ii,  3) << endl;
    }
    return 0;
}
