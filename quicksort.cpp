#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot=arr[e];
    int pindex=s;
    for(int i=s;i<e;i++){
        if(arr[i]<=pivot){
            int temp=arr[i];
            arr[i]=arr[pindex];
            arr[pindex]=temp;
        pindex++;
        }
    }
    int temp=arr[e];
            arr[e]=arr[pindex];
            arr[pindex]=temp;
return pindex;    
}

void Quick_sort(int arr[],int s,int e){
    if(s<e){
        int p=partition(arr,s,e);
        Quick_sort(arr, s, (p-1));
        Quick_sort(arr, (p+1), e);
    }
}


int main(){
int my_arr[7];
for(int i=0;i<7;i++)
{
    cin>>my_arr[i];
}

for(int i=0;i<7;i++){
    cout<<my_arr[i]<<" ";
}
cout<<endl;
Quick_sort(my_arr,0,6);
for(int i=0;i<7;i++){
    cout<<my_arr[i]<<" ";
}
cout<<endl;


    return 0;
}