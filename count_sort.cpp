#include <iostream>
using namespace std;

void counting_sort(int input_arr[], int n, int r)
{
    int count_arry[r], output_arr[n];
    for (int i=0;i<r;i++)
    {
        count_arry[i]= 0;
    }

    for (int i = 0; i < n; i++)
    {
        ++count_arry[input_arr[i]];
    }
    for (int i = 1; i < r; i++)
    {
        count_arry[i]=count_arry[i]+count_arry[i-1];
    }
    for(int i=0;i<n;i++){
        output_arr[--count_arry[input_arr[i]]]=input_arr[i];
    }
    for(int i=0;i<n;i++){
        input_arr[i]=output_arr[i];
    }
}

int main()
{
    int n;
    cout << "enter the size of array" << endl;
    cin >> n;
    int my_arr[n], range;
    cout << "enter range" << endl;
    cin >> range;
    cout << "enter the elements of unsortted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> my_arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << my_arr[i]<<" ";
    }
    cout<<endl;
    counting_sort(my_arr, n, range);

    for (int i = 0; i < n; i++)
    {
        cout << my_arr[i]<<" ";
    }

cout<<endl;
    return 0;
}