#include <iostream>
using namespace std;
void Ascending_selectionsort(int arr[],int n)
{
   // int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        // minimum equal to i
        int min = i;

        // checking
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        // swapping
        if (min != i)
        {
            swap(arr[i], arr[min]);
        }
    }
}
void Descending_selectionsort(int arr[],int n){
   // int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        // maximum equal to i
        int max = i;

        // checking
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max])
                max = j;
        }
        // swapping
        if (max != i)
        {
            swap(arr[i], arr[max]);
        }
    }
}

int main()
{
    int n;
    cout << "number of elements ";
    cin >> n;
    int arr[n];
    cout << "enter the elements of arry\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
Ascending_selectionsort(arr,n);
    cout << "ascended sorted array\n";
    for (auto a : arr)
    {
        
        cout << a<<",";
    }
cout<<endl;
    Descending_selectionsort(arr,n);
    cout << "descended sorted array\n";
    for (auto a : arr)
    {
        cout << a <<",";
    }
    cout<<endl;
    return 0;
}