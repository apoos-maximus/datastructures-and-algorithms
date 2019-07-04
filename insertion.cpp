#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<list>
using namespace std;
    void insertion_sort(vector<int> &);
    void place_in(vector<int> &,int,vector<int>::iterator);
    int main(){
        string input;
        getline(cin,input);
        stringstream input1(input);
        vector<int> keys = {};
        string token;
        int num = 0;
        while(getline(input1,token,' ')){
            stringstream(token)>>num;
            keys.push_back(num);
        }
        cout<<endl;
        for(vector<int> :: iterator it = keys.begin(); it!= keys.end(); ++it){
            cout<<*it<<" ";
        }cout<<endl;

        insertion_sort(keys);

        for(vector<int> :: iterator it = keys.begin(); it!= keys.end(); ++it){
            cout<<*it<<" ";
        }cout<<endl;
    
    return 0;
    }

    void insertion_sort(vector<int> &a){
        int j = 0;
        int item = 0;
        for(int i = 0; i < a.size(); i++){
            item = a[i];
            j = i-1;
            while( (j>=0) && (a[j] > item) ){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = item;
        } 
    }

