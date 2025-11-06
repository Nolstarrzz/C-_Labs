#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void merge(int arr[], int left[], int leftSize, int right[], int rightSize);

void build_array(int array[]);
// fill the given array with random numbers between 0 and 99

void sort_array(int array[], int left, int right);
// array is sorted in place in ascending order

bool array_contains(const int array[], int num, int& position, int first, int last);
// returns true if num is found in array, false otherwise.
// position is updated with the index of num when found or -1 if not.

void get_input(int& num);
// num is updated with the number entered

void display_array(int array[]);
// the contents of array are printed out in a square 
// with size sqrt(ARRAY_SIZE)

// total array size
const int ARRAY_SIZE = 100;

int main() 
{
    srand(time(0));
    int my_array[ARRAY_SIZE - 1];
    int check_num = 0, position = 0;
    char ask = 'N';

    // fill our array
    build_array(my_array);

    cout << "Array before sorting:";
    display_array(my_array);
    
    // sort it
    sort_array(my_array, 0 , ARRAY_SIZE - 1);
    cout << endl << endl;

    cout << "Array after sorting:";
    display_array(my_array);

    do 
    {
        get_input(check_num);
        array_contains(my_array, check_num, position, 0, ARRAY_SIZE);
        cout << "The position of your number is: " << position << " if its -1 then it failed" ;
        
        cout << "Would you like to look for another number? [Y|N]: ";
        cin >> ask;
    } while (ask == 'Y' || ask == 'y');
}

void build_array(int array[])
{
    for(int i=0;i<ARRAY_SIZE;i++)
        {
            array[i] = rand() % 100;
        }
}

/*void sort_array(int array[], int left, int right)
{
    if(left >= right)
        return;
    int mid = left + (right - left) / 2;
    sort_array(array, left, mid); //sort left half
    sort_array(array, mid + 1, right); //sort right half
    int leftArr[mid-left+1], rightArr[right-mid];
    for(int i=0;i <= mid - left; i++)
    {
        leftArr[i] = array[left + i];
    }
    for(int i=0; i<right - mid; i++)
    {
        rightArr[i] = array[mid + 1 + i];
    }
    merge(array, leftArr, mid-left+1, rightArr, right-mid);
}*/
void sort_array(int array[], int left, int right)
{
    if(left >= right)
        return;
    
    int mid = left + (right - left) / 2;
    
    sort_array(array, left, mid);      // sort left half
    sort_array(array, mid + 1, right); // sort right half
    
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    // VLA's (Variable Length Arrays) are a GCC extension, often avoided in C++
    // but OK for this context.
    int leftArr[leftSize], rightArr[rightSize];
    
    // Correctly copy elements from array[left] up to array[mid]
    for(int i = 0; i < leftSize; i++) // use < leftSize to avoid index error
    {
        leftArr[i] = array[left + i]; // FIXED: Use array[left + i]
    }
    
    // Correctly copy elements from array[mid + 1] up to array[right]
    for(int i = 0; i < rightSize; i++)
    {
        rightArr[i] = array[mid + 1 + i];
    }
    
    merge(array, leftArr, leftSize, rightArr, rightSize);
}

void get_input(int& num)
{
    cout << "Give me number to look for: ";
    cin >> num;
}

void display_array(int array[])
{
    for (int x = 0; x < ARRAY_SIZE; x++)
    {
        if ((x % static_cast<int>(sqrt(ARRAY_SIZE))) == 0)
            cout << endl;
        if (array[x] < 10)
            cout << " ";
        cout << array[x] << " ";
    }
}


bool array_contains(const int array[], int num, int& position, int first, int last)
{
    int mid = first + (last-first)/2;
    if(array[mid] == num)
    {
        position = mid;
        return true;
    }
    else if(num < array[mid])
    {
        last = mid - 1;
        return array_contains(array,num,position,first,last);
    }
    else if(num > array[mid])
    {
        first = mid + 1;
        return array_contains(array,num,position,first,last);
    }
    else
    {
        position = -1;
        return false;
    }
    
}




void merge(int arr[], int left[], int leftSize, int right[], int rightSize) 
{
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}


