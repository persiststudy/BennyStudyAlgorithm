#include <iostream>
#include <algorithm>

using namespace std;

/*
 * 常规冒泡算法，注意两轮循环，外循环每次放好一个最大数， 
 * 只要n-1次就行了，内循环经过n-1两两比较，将最大数放到最后。 
*/
void bubbleSort(int a[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}

/*改进的冒泡算法，如果在一轮循环中发现都没有交换元素，也就是没有逆序， 
  结束整个循环，元素都是有序的*/
void bubbleSort1(int a[], int n)
{
    bool swapped;
    for (int i=0; i<n-1; i++)
    {
        swapped = false;
        for (int j=0; j<n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

// 用While循环实现的改进冒泡算法
void bubbleSort2(int a[], int n)
{
    bool swapped;
    int j = n - 1; 
    do
    {
        swapped = false;
        for (int i=0; i<j; i++)
        {
            if (a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        j--;
    } while(swapped);
}
/* 
*/
void selectionSort(int a[], int n)
{
    int minIndex;
    for (int i=1; i<n; i++)
    {
        minIndex = i-1;
        for (int j=i; j<n; j++)
        {
            if (a[j-1] > a[j])
            {
                minIndex = j;
            }
        }
        swap(a[i - 1], a[minIndex]);
    }
}

void selectionSort1(int a[], int n)
{
    int minIndex;
    for (int i=0; i<n-1; i++)
    {
        minIndex = i;
        for (int j=i; j<n-1; j++)
        {
            if (a[j] > a[j+1])
            {
                minIndex = j+1;
            }
        }
        swap(a[i], a[minIndex]);
    }
}
/*插入排序，用交换法*/
void insertionSort(int a[], int n)
{
    for (int i=1; i<n; i++)
    {
        for (int j=i; j>0; j--)
        {
            if (a[j-1] > a[j])
            {
                swap(a[j-1], a[j]);
            }
            else
            {
                break;
            }
        }
    }
}

/*插入排序，如果交换的开开销比较大，那就用赋值法*/
void insertionSort1(int a[], int n)
{
    for (int i=1; i<n; i++)
    {
        int value = a[i];
        int j;
        for (j=i; j>0; j--)
        {
            if (a[j-1] > value)
            {
                //swap(a[j-1], a[j]);
                a[j] = a[j-1];
            }
            else
            {
                break;
            }
        }
        a[j] = value;
    }
}

void printArray(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    //bubbleSort(a, 10);
    //bubbleSort1(a, 10);
    //bubbleSort2(a, 10);
    //selectionSort(a, 10);
    //selectionSort1(a, 10);
    //insertionSort(a, 10);
    insertionSort1(a, 10);
    printArray(a,10);
}
