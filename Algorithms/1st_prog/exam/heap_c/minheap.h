#ifndef	MINHEAP_H_   /* Include guard */
#define MINHEAP_H_

#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#define N 100
 
int A[N];
 
 
void swap (int a, int b){
	int temp;
	temp = b;
	b = a;
	a = temp;
	return ;
} 
/*
 * Initial heap size 0 as heap is empty
 */
int heapsize = 0;
/*
 * Find the parent node
 */
int parent(int i){
    return ceil(i / 2.0 - 1);
}

/*
 * Search for a specific node to change its value
 * Returns the index the node being searched
 */
 /*
int searchIndex(int n){
    for(int i = 0; i < heapsize; ++i){
        if(A[i] == n)
            return i;
    }
    return heapsize;
}
*/
/*
 * Called initially to create a min heap
 * Also called after a node extraction from min heap
 * Since the smallest value node is at the root of min heap
 * After extraction min heapify is called on root node
 * It compares parent with its children
 * If a smaller child found then its swapped with parent and
 * Min heapify is again called on that child to apply same procedure
 */
void minHeapify(int i){
    int largest;
 
    int l = 2*i +1;
 
    if (l < heapsize && A[l] < A[i])
        largest = l;
    else
        largest = i;
 
    int r = 2*i +2;
 
    if (r < heapsize && A[r] < A[largest])
        largest = r;
 
    if (largest != i){
        swap(A[i], A[largest]);
        minHeapify(largest);
    }
}
/*
 * Does not extract any items only show the minimum element
 */
int heapMinimum(){
    return A[0];
}
/*
 * Increase heap size to create space for new node
 * Insert the node at that space by calling decrease key function
 */
void heapInsert(int n){
    A[heapsize] = n;
    int i = heapsize;
    while(i > 0 && A[parent(i)] > A[i]){
        swap(A[i], A[parent(i)]);
        i = parent(i);
    }
   	++heapsize; 
}
/*
 * Heap size less than zero mean no items in heap so nothing to extract
 * For min heap minimum value is at the root which in here is A[0]
 * Save the root and replace root with last element in the heap and decrease the heap size
 * So the root is still in the array in last position but no longer in the heap
 * Since the last element is now the root the heap may be unbalanced
 * So to balance the heap call min heapify on the root node again
 * Lastly return the saved root
 */
int extractMin(){
    if(heapsize < 0)
        printf("Heap Underflow\n");
 
    int min = A[0];
    A[0] = A[heapsize - 1];
    --heapsize;
    minHeapify(0);
    return min;
}
/*
 * Every time we extract heap size is automatically reduced
 * So no need change heap size in while loop
 */
void printPriorityQueue(){
    printf("Main Output:\n");
    while(heapsize){
        int ext = extractMin();
        printf("%d\n",ext );
    }
}
 /*
int main(){
 
   
    heapInsert(99);
	heapInsert(9);
    heapInsert(29);
    heapInsert(19);
    printPriorityQueue();
    heapInsert({'c',95});
    heapInsert({'g',22});
    heapInsert({'b', 1});
    heapInsert({'e', 5});
    heapInsert({'d', 2});
    //decreaseKey( searchIndex({'a', 9}), {'a', 4} );
 
    return 0;
}*/
#endif
