#include <iostream>
#include <memory>
using namespace std;

int countSub(int arr[], int n)
{
    int* count = new int[n]();
    count[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i])
                count[i] += 1 + count[j];
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++)
        result += count[i];
    result;
    delete []count;
    return result;
}

//Driver program to run the test case;
int main()
{
    int arr[] = {7, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n <<" "<<countSub(arr, n);
    return 0;
}
