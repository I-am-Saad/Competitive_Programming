// In the name of Allah.
/*
Author  : Saad Ibn Abdullah
Created : 21/11/2024
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    long long a,b; cin>>a>>b;

    //checking if the multiplication result negative or not.
    bool negative = ((a<0 and b>0) or (a>0 and b<0));

    string sa = to_string(a);   //multiplier
    string sb = to_string(b);   //multiplicand 

    reverse(sa.begin(),sa.end());   //as multiplication start from right side.
    reverse(sb.begin(),sb.end());   //but loop start form left side.

    //removing negative sign
    if(sa.back() == '-')
        sa.pop_back();
    if(sb.back() == '-')
        sb.pop_back();

    string ans = "";    //product

    for(int i=0;i<sb.size();i++){
        int num_in_sb = sb[i]-'0';  //getting multiplicand one value
        for(int j=0;j<sa.size();j++){
            int num_in_sa = sa[j]-'0';  //getting multiplier one value
            int carry = num_in_sa * num_in_sb;
            int adding_pos_now = i+j;
            //if carry become zero, still have to add it in ans string.(ex: 12*10 = 120)
            while(true){
                if(adding_pos_now<ans.size()){
                    int num_in_ans = ans[adding_pos_now]-'0';   //getting actual carry one value 
                    carry += num_in_ans;
                    ans[adding_pos_now] = (carry%10)+'0';
                }else{
                    ans.push_back((carry%10)+'0');
                }
                adding_pos_now++;
                carry/=10;
                if(not carry)
                    break;
            }
        }
    }

    //if there is multiple zero in front of ans they are useless.
    while(ans.size()>1 and ans.back() == '0')   
        ans.pop_back();

    if(negative)
        ans.push_back('-');

    reverse(ans.begin(),ans.end());     //as we calculate the ans in reverse order.

    cout<<ans<<endl;

    return ((0 - 0));
}
// o.o -_- (•_•) \_(^_^)_/

/*
     12 ---->multiplier
    x 5 ---->multiplicand
    ______
    100 ---->product
*/
