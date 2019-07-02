#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

    int main(){

        vector<int> a = {1,2,3,4,5,6};
        vector<int> :: iterator i = a.begin();
        while(i!=a.end()){
            cout<<*i<<" ";
            i++;
        }
        i = a.begin();
        while(i != a.end()){
            *i = 5;
            i++;
        }
        cout<<endl;
        i = a.begin();
        while(i!=a.end()){
            cout<<*i<<" ";
            i++;
        }

        return 0;
    }