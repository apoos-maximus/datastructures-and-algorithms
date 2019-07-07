#include<iostream>
#include<vector>
#include<iterator>
#include<sstream>
#include<string>
#include<cstdlib>
using namespace std;

    void quickSort(vector<int> &, int, int);
    int partition(vector<int> &, int, int, int);
    void swap(vector<int> &, int,int);

    int main(){
        srand(time(0));
        string str;
        getline(cin,str);
        stringstream input(str);
        string token;
        vector<int> keys;
        int a = 0;
        while(getline(input,token,' ')){
            stringstream(token)>>a;
            keys.push_back(a);
        }
        cout<<endl;
        for(vector<int> :: iterator it = keys.begin(); it != keys.end(); ++it){
            cout<<*it<<" ";    
        }cout<<endl;

        quickSort(keys,0,keys.size() - 1);

        cout<<endl;
        for(vector<int> :: iterator it = keys.begin(); it != keys.end(); ++it){
            cout<<*it<<" ";    
        }cout<<endl;

    return 0;
    }

    void quickSort(vector<int> &a, int leftStart, int rightEnd){
        if(leftStart >= rightEnd) return;

        int pivot = a[(leftStart + rightEnd )/2] ;
        int index = partition(a,leftStart,rightEnd,pivot);
        quickSort(a,leftStart,index-1);
        quickSort(a,index,rightEnd);
    }

    int partition(vector<int> &a, int leftStart, int rightEnd, int pivot){
        int left = leftStart;
        int right = rightEnd;

        while( left <= right ){
            while(a[left] < pivot){
                left++;
            }

            while(a[right] > pivot){
                right--;
            }
            if(left <= right){
                swap(a,left,right);
                left++;
                right--;
            }
        }
        return left;
    }

    void swap(vector<int> &a, int left, int right){
        int temp;
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
    }