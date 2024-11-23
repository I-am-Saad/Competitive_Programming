// In the name of Allah.
//Topic: how to get the first and last k digit of n^x exponent or the first and last k digits of an exponentiation
//Problem link: https://www.codechef.com/problems/A4
// https://toph.co/contests/training/qjqle8v  (name : F. Heads of the Dragon)

#include<bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long b, long long mod){     //mod = 10^last digit
    long long ans = 1;
    while(b){
        if(b&1)     //b%2 == 1
            ans = ans*a %mod;
        a = a*a %mod;
        b>>=1;  //b = b/2;
    }
    return ans;
}

// function to calculate the first k digits of n^x
long long first_k_digits(long long n,long long x,long long k){

    //take log10 of n^x. log10(n^x) = x*log10(n)
    long double product = log10l(n) * x;    //Caution it must be in log10l(n) not log10(n)
    // long double product = log10(n) * x;    //some problem work log10(n) but show wa for log10l(n)

    long double decimal_part = product - floor(product);

    decimal_part = pow(10, decimal_part);

    long long digits = pow(10, (int)k-1); //make k an integer; otherwise, it will give 999 instead of 1000.

    return decimal_part * digits;
}

// function to calculate last k digits of n^x
string last_k_digit(long long n, long long x, long long k ){
    long long pow10 = pow(10,(int)k);    //make k is an integer otherwise it gives 999 instead of 1000.
    
    long long result = modPow(n,x,pow10);   //as exponent % 100 always provide last 2 digit
    
    string ans = to_string(result);
    string zero = {};
    while(ans.size() + zero.size() < k)
        zero.push_back('0');    
    ans = zero + ans;   //just added some extra zero in front of the result.

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int T; cin>>T; while(T--){
        int n,x,k;
        // cin>>n>>x>>k;
        cin>>n>>x;
        k = 4;
        cout<<first_k_digits(n,x,k)<<endl;
        // <<' '<<last_k_digit(n,x,k)<<endl;
    }  
    return ((0 - 0));
}
// o.o -_- (•_•) \_(^_^)_/

/*
Example :
    How to find the first k digits: 

9^9 = 387420489 = 10^x
now log both sides,
 9 * log10(9) = x * log10(10) //log10(10) = 1
 9 * log10(9) = x  // log10(10) = 1

now x = 8.588182..
what we see 
    10^8.588182 =  10^8 * 10^588182
    by 10^8 we know that the length is 8 for our result
    (8.588182..) - 8 = 0.588182..
    0.588182.. + (first n digit - 1) 
    let n = 3,
    0.588182.. + (3-1) = 2.588182..

    And now the 10^2.588182.. = 387.41 
    after remove decimal point = 387 // whereas 9^9 = 387420489
    here is how the first 3 digits came out (o_O)

Input : 

4
2 2 4
2 10 4
2 15 4
9 9 4

*/
