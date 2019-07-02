#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<iterator>
using namespace std;
#define SIZE 10

    void mergesort(vector<int>);
    void mgsort(vector<int> ,vector<int>  , int, int);
    void mergeHalves(vector<int> ,vector<int> ,int , int);

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
        for(vector<int> :: iterator i = a.begin(); i != a.end(); i++){
            cout<<*i<<" ";
        }
        mergesort(a);        
        cout<<endl;
        for(vector<int> :: iterator i = a.begin(); i != a.end(); i++){
            cout<<*i<<" ";
        }
    }
        void mergesort(vector<int> v){
            vector<int> temp;
            mgsort(v,temp,0,v.size()-1);
        }
        void mgsort(vector<int> v,vector<int> temp , int leftStart, int rightEnd){
            if(leftStart == rightEnd)
                return;
            int middle = ((leftStart + rightEnd) / 2);
            mgsort(v,temp,leftStart,middle);
        
            mgsort(v,temp,middle+1,rightEnd);
            mergeHalves(v,temp,leftStart,rightEnd);
        }

        void mergeHalves(vector<int> v,vector<int> temp,int leftStart,int rightEnd){
            int leftEnd = (rightEnd+leftStart)/2 ;
            int rightStart = leftEnd + 1;
            vector<int> :: iterator m = v.begin();
            vector<int> :: iterator ls = next(m,leftStart);
            vector<int> :: iterator rs = next(m,rightStart);
            vector<int> :: iterator le = next(m,leftEnd);
            vector<int> :: iterator re = next(m,rightEnd);
            cout<<endl;
            vector<int> :: iterator left,right;
            left = ls;
            right = rs;

            while ((left <= le) && (right <= re)){
                if( (*left) < (*right) ){
                    temp.push_back(*left);
                    left++;
                } else {
                    temp.push_back(*right);
                    right ++;
                }
            }
            while(left <= le){
                temp.push_back(*left);
                left++;
            }
            while(right <= re){
                temp.push_back(*right);
                right++;
            }

            auto t = temp.begin();
            for(auto w = ls; w<=re; w++){
                *w = *t;
                t++;
            }

                // cout<<endl;
                // for(auto o = temp.begin(); o!= temp.end(); o++){
                //     cout<<*o<<" ";
                // }cout<<endl;
            temp.clear();
            for(auto it = ls; it <= le; it++){
                cout<<*it<<" ";
            }
            cout<<endl;
            for(auto it = rs; it <= re; it++){
                cout<<*it<<" ";
            }
            cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"; 
        }