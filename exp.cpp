#include<iostream>
#include<vector>

using namespace std;

    int main(){
        vector<int> a = {1,1,1,5,9,10,11,13,2,7,10,11,45,1,1,1,1};
        int leftStart = 3;
        int leftEnd = 7;
        int rightStart = 8;
        int rightEnd = 12;

        vector<int> temp;
        vector<int> :: iterator ls,le,rs,re,left,right,t;
        ls = next(a.begin(),leftStart);
        le = next(a.begin(),leftEnd);

        rs = next(a.begin(),rightStart);
        re = next(a.begin(),rightEnd);

        left = ls;
        right = rs;
        while ((left <= le) && (right <= re)){
            if ( (*left) < (*right) ){
                temp.push_back(*left);
                left ++;
            } else {
                temp.push_back(*right);
                right ++;
            }
        }
        while (left <= le){
            temp.push_back(*left);
            left++;
        }

        while (right <= re){
            temp.push_back(*right);
            right++;
        }
        
        for(vector<int> :: iterator i = temp.begin(); i!=temp.end(); ++i){
            cout<<*i<<" ";
        }
        
        t = temp.begin();
        for(vector<int> :: iterator p = ls; p<=re; p++){
            *p = *t;
            t++;
        }
        

        cout<<endl;
        for(vector<int> :: iterator k = a.begin(); k != a.end(); k++){
            cout<<*k<<" ";
        }
        cout<<endl;
        temp.clear();

        return 0;
    }