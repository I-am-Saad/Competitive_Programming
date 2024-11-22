// In the name of Allah.
//Author : Saad Ibn Abdullah

//Topic : how to get first n digit of a^b exponent or first n digits of an exponentiation
//Created : 22/11/2024

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int T; cin>>T; while(T--){
        long double a,b; cin>>a>>b;   //a^b
        int n = 4;      //how many first digits wanted.
        // cin>>n;
        long double x = b*log10(a);     //10^x  from equation.  

        long cut_x = x;      //value after remove decimal point.

        if(cut_x < n){      //when result have less digit than required.

            // any of next three line provide same result

            // cout<<static_cast<long long>(pow(a,b))<<endl;   //just delete decimal point
            // cout<<floor(pow(a,b))<<endl;
            cout << fixed << setprecision(0) << powl(a,b)<<endl;

        }else{
            x -= cut_x;
            x += n-1;
            long double ten = 10;   //  or powl(static_cast<long double>(10),x)
            long first_n_digit = powl(ten,x);
            //result = pow(base, exponent); function return type = long double (if provided value are long double.)
            cout<<first_n_digit<<endl;
        }
    }  
    return ((0 - 0));
}
// o.o -_- (•_•) \_(^_^)_/

/*
Example :

9^9 = 387420489 = 10^x
now log both size,
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
    here how first 3 digit came out (o_O)


Input : 

4
2 2
2 10
2 15
9 9

*/
