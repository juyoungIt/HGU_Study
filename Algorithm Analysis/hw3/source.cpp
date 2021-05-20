// Algorithm Analysis hw3
// Writer : 21700760 Juyoung Ha

#include <iostream>
using namespace std;

// class definition
class Heap
{
public:
    // data field
    int heap_size; // the number of element of array which belong to heap
    int length;    // the number of element of array
    int* array;    // the array which store heap's node
    // function
    Heap(); // constructor
};

// function declaration
void insertion_sort(int*, int); // execute the insertion sort
int leftChildIdx(int cur_idx);  // calculate left child node's index
int rightChildIdx(int cur_idx); // calculate right child node's index
void maxHeapify(Heap* heap, int idx); // maintain the max-heap's properties
void buildMaxHeap(Heap* heap, int* array, int len); // build max-heap from the normal array
void swap(int* a1, int* a2); // exchange a1 with a2 (the array element)
void heap_sort(Heap* heap, int* array, int len);    // execute the heap sort
int partition(int* array, int idx1, int idx2); // find the index location of pivot
void quick_sort(int* array, int idx1, int idx2); // execute the quick sort
void insertion_result(int* array, int len); // print out the insertion sort result
void heap_result(Heap* heap); // print out the heap sort result
void quick_result(int* array, int len); // print out the quick sort result

// main function
int main()
{
    // sample array to test sorting algorithms
    // pleas enter the your array here...
    int list[100] = {100, 54, 73, 25, 76, 72, 90, 9, 84, 33, 70, 87, 68, 23, 30, 29, 43, 18, 67, 17, 8, 36, 14, 20, 13, 11, 99, 83, 59, 34, 10, 96, 58, 6, 94, 19, 97, 37, 89, 88, 40, 28, 38, 75, 86, 7, 51, 55, 66, 44, 24, 26, 50, 27, 31, 71, 42, 80, 35, 3, 63, 93, 1, 60, 95, 32, 46, 12, 41, 4, 15, 45, 77, 65, 92, 69, 57, 47, 62, 82, 16, 78, 74, 85, 98, 81, 91, 53, 52, 48, 56, 79, 2, 21, 61, 49, 39, 64, 5, 22};

    int len = sizeof(list) / sizeof(int); // calculate the length of array

    int* listForInst = (int*)malloc(sizeof(int) * len);  // list for insertion sort
    int* listForHeap = (int*)malloc(sizeof(int) * len);  // list for heap sort
    int* listForQuick = (int*)malloc(sizeof(int) * len); // list for quick sort

    // generate list for each sorting algorithm
    for(int i=0 ; i<len ; i++) {
        listForInst[i] = list[i];
        listForHeap[i] = list[i];
        listForQuick[i] = list[i];
    }

    // print out initial array (before the sorting)
    cout << "<<Before the sorting>>" << endl << endl;
    cout << "initial array = ";
    for(int i=0 ; i<len ; i++)
        cout << list[i] << " ";
    cout << endl << endl;

    Heap heap; // create the heap which object of Heap class

    // execute the insertion sort
    clock_t insertion_start = clock(); // start the time checking
    insertion_sort(listForInst, len);
    clock_t insertion_end = clock(); // end the time checking

    // execute the heap sort
    clock_t heap_start = clock(); // start the time checking
    heap_sort(&heap, listForHeap, len);
    clock_t heap_end = clock(); // end the time checking

    // execute the quick sort
    clock_t quick_start = clock(); // start the time checking
    quick_sort(listForQuick, 0, len-1);
    clock_t quick_end = clock(); // end the time checking

    // print out the result (after the sorting)
    cout << "<<After the sorting>>" << endl << endl;
    insertion_result(listForInst, len);
    cout << "Running Time: "<< (double)(insertion_end - insertion_start)/CLOCKS_PER_SEC << endl << endl;
    heap_result(&heap);
    cout << "Running Time: "<< (double)(heap_end - heap_start)/CLOCKS_PER_SEC << endl << endl;
    quick_result(listForQuick, len);
    cout << "Running Time: "<< (double)(quick_end - quick_start)/CLOCKS_PER_SEC << endl << endl;

    free(heap.array); // deallocate the heap array memory space
    free(listForInst);
    free(listForHeap);
    free(listForQuick);

    return 0;
}

// function definition for class Heap
Heap::Heap()
{
    heap_size = 0;
    length = 0;
    array = nullptr;
}

// general function definition
void insertion_sort(int* list, int len)
{
    int key;  // key value
    int i, j; // loop variable

    for(j=1 ; j<len ; j++) {
        key = list[j]; // set the key
        i = j-1;
        while(i>=0 && list[i]>key) {
            list[i+1] = list[i];
            i = i-1;
        }
        list[i+1] = key;
    }
}

int leftChildIdx(int cur_idx)
{
    return cur_idx*2;
}

int rightChildIdx(int cur_idx)
{
    return cur_idx*2+1;
}

void swap(int* a1, int* a2)
{
    int tmp;
    tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

void maxHeapify(Heap* heap, int idx)
{
    int left_idx = leftChildIdx(idx);
    int right_idx = rightChildIdx(idx);
    int largest;

    if(left_idx<=heap->heap_size && heap->array[left_idx]>heap->array[idx])
        largest = left_idx;
    else
        largest = idx;

    if(right_idx<=heap->heap_size && heap->array[right_idx]>heap->array[largest])
        largest = right_idx;
    if(largest != idx) {
        swap(&heap->array[largest], &heap->array[idx]);
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(Heap* heap, int* array, int len)
{
    int i; // 반복문 변수

    heap->length = len;
    heap->heap_size = len;
    heap->array = (int*)malloc(sizeof(int) * (len+1));

    for(i=1 ; i<=len ; i++)
        heap->array[i] = array[i-1];

    for(i=len/2 ; i>=1 ; i--)
        maxHeapify(heap, i);
}

void heap_sort(Heap* heap, int* array, int len)
{
    buildMaxHeap(heap, array, len);
    for(int i=heap->length ; i>=2 ; i--) {
        swap(&heap->array[1], &heap->array[i]);
        heap->heap_size -= 1;
        maxHeapify(heap, 1);
    }
}

int partition(int* array, int idx1, int idx2)
{
    int pivot = array[idx2];
    int i = idx1-1;

    for(int j=idx1 ; j<idx2 ; j++) {
        if(array[j]<=pivot) {
            i = i+1;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[idx2]);
    return i+1;
}

void quick_sort(int* array, int idx1, int idx2)
{
    int q;

    if(idx1 < idx2) {
        q = partition(array, idx1, idx2);
        quick_sort(array, idx1, q-1);
        quick_sort(array, q+1, idx2);
    }
}

void insertion_result(int* array, int len)
{
    cout << "insertion sort = ";
    for(int i=0 ; i<len ; i++)
        cout << array[i] << " ";
    cout << endl;
}

void heap_result(Heap* heap)
{
    cout << "heap sort = ";
    for(int i=1 ; i<=heap->length ; i++)
        cout << heap->array[i] << " ";
    cout << endl;
}

void quick_result(int* array, int len)
{
    cout << "quick sort = ";
    for(int i=0 ; i<len ; i++)
        cout << array[i] << " ";
    cout << endl;
}