#include<iostream>
#include<algorithm>
using namespace std;


void quick_sort_to_binary_array(int array[], int length)
{
    int position = -1 ;

    for(int i = 0 ; i<length ; i++)
    {
        if(array[i]<1)
        {
            position++;
            swap(array[i], array[position]);
        }
    }
}

void sort_by_counting(int array[], int length)
{
    int zero_counter = 0;

    for(int i = 0; i<length; i++)
    {
        if(array[i] == 0)
            zero_counter++ ;
    }

    for(int i = 0; i<zero_counter; i++)
        array[i] = 0 ;

    for(int i = zero_counter; i<length ; i++)
        array[i] = 1 ;
}

void bubble_sort_to_binary_array(int array[], int length)
{
    int current = 0;

    for(int i=0; i<(length-1) ; i++)
    {
        if(array[i] == 1)
        {
            swap(array[i], array[current]);
            current++;
        }
    }

    reverse(array, array+length);
}

int main()
{
    int binary[] = {0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};
    int arr_size = sizeof(binary) / sizeof(binary[0]);


    quick_sort_to_binary_array(binary, arr_size);


        for(int i=0; i<arr_size; i++)
            {
                cout<< binary[i]<<" ";
            }

    cout<<"\n";
    cout<<"================================\n\n";


    int binary_arr[] = {0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};
    int size_arr = sizeof(binary_arr) / sizeof(binary_arr[0]);


    sort_by_counting(binary_arr, size_arr);

        for(int i=0; i<size_arr; i++)
            {
                cout<< binary_arr[i]<<" ";
            }

    cout<<"\n";


    cout<<"================================\n\n";

    int third_binary_arr[] = {0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0};
    int third_size_arr = sizeof(third_binary_arr) / sizeof(third_binary_arr[0]);


    bubble_sort_to_binary_array(third_binary_arr, third_size_arr);

    for(int i=0; i<third_size_arr; i++)
    {
        cout<< third_binary_arr[i]<<" ";
    }

    cout<<"\n";

    return 0;
}


