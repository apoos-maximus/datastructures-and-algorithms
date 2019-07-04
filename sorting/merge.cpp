#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<iterator>
using namespace std;
#define SIZE 10

    void mergesort(vector<int>&);
    void mgsort(vector<int> &,vector<int>  , int, int);
    void mergeHalves(vector<int> &,vector<int> ,int , int);

    int main(){

        vector<int> a = {};
        vector<int> :: iterator i;
        string input,token;
        int item;
        getline(cin,input);
        // cout<<"$$";
        stringstream input1(input);
        // cout<<"34";
        while(getline(input1,token, ' ')){
            stringstream(token)>>item;
            a.push_back(item);
        }
        // for(vector<int> :: iterator i = a.begin(); i != a.end(); i++){
        //     cout<<*i<<" ";
        // }
        mergesort(a);        
        cout<<endl;
        for(vector<int> :: iterator i = a.begin(); i != a.end(); i++){
            cout<<*i<<" ";
        }
    }
        void mergesort(vector<int> &v){
            vector<int> temp;
            mgsort(v,temp,0,v.size()-1);
        }
        void mgsort(vector<int> &v,vector<int> temp , int leftStart, int rightEnd){
            if(leftStart == rightEnd)
                return;
            int middle = ((leftStart + rightEnd) / 2);
            mgsort(v,temp,leftStart,middle);
            mgsort(v,temp,middle+1,rightEnd);
            mergeHalves(v,temp,leftStart,rightEnd);
        }

        void mergeHalves(vector<int> &a,vector<int> temp,int leftStart,int rightEnd){
            int leftEnd = (rightEnd+leftStart)/2 ;
            int rightStart = leftEnd + 1;

          vector<int> :: iterator ls,le,rs,re,left,right,t;
        ls = next(a.begin(),leftStart);
        le = next(a.begin(),leftEnd);

        rs = next(a.begin(),rightStart);
        re = next(a.begin(),rightEnd);

        left = ls;
        right = rs;
        while ((left <= le) && (right <= re)){
            if ( (*left) < (*right) ){
                // cout<<"left";
                temp.push_back(*left);
                left ++;
            } else {
                // cout<<"right";
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
        
        t = temp.begin();
        for(vector<int> :: iterator p = ls; p<=re; p++){
            *p = *t;
            t++;
        }
        // for(auto g = a.begin(); g!=a.end(); g++){
        //     cout<<*g<<" ";
        // temp.clear(); 
        // }
        }