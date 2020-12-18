/*
Binary Heap

It’s a complete tree (Binary Tree) ,all levels are completely filled except possibly the last level and the 
last level has all keys as left as possible. This property of Binary Heap makes them suitable to be stored in an array.

In a Min Heap, the key at root must be minimum among all keys present in Binary Heap.

How is Binary Heap represented?
A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an array.

    The root element will be at Arr[0].
    Arr[floor((i-1)/2) 	Returns the parent node
    Arr[(2*i)+1] 	Returns the left child node
    Arr[(2*i)+2] 	Returns the right child node
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y);

class minHeap{
    private:
        int size;
        int capacity;
        vector<int> heap;

    public: 
        minHeap(int capacity); //constructor
        void heapify(int i); //function to rearrange the heap in order

        int parent(int i) { return (i-1)/2; } //parent of i
        int left(int i) { return (2*i + 1); } //left child of i
        int right(int i) { return (2*i + 2); } //right child of i
        
        void insertKey(int k); 
        void deleteKey(int k);
        int getMin() { return heap[0]; }
        int extractMin(); 
        void printHeap();
        void replaceKey(int i, int new_val);
};

minHeap::minHeap(int cap){
    size = 0; //curr element, total elements currently present in the heap
    capacity = cap; //total capacity of the heap
    heap.resize(capacity);
}

void minHeap::insertKey(int k){
    if(size == capacity){
        cout<<"Its Full"<<endl;
        return;
    }

    size++; //incr the number of elements currently in the heap
    int i = size-1; //inserting at the end
    heap[i] = k;

    while(i != 0 && heap[parent(i)] > heap[i]){ //then checking if it is less or greater than the parent
        swap(heap[i], heap[parent(i)]); //swapping if less than the parent
        i = parent(i); //setting it is as the parent
    }

}

int minHeap::extractMin(){
    if(size <= 0){
        cout<<"Empty Heap"<<endl;
        return -1;
    }
    else if(size == 1){
        size--;
        return heap[0];
    }
    else{
        int root = heap[0]; //item to be extracted (min)

        heap[0] = heap[size-1]; //making the last element as the root
        size--; //decreasing the size, as to remove the last element thats the new root
        heapify(0); //now heapifying from the root

        return root;
    }
}

void minHeap::heapify(int i){ //checking for ith node
    int l = left(i);  //getting its left
	int r = right(i);  //getting its right
	int smallest = i;  
	if(l < size && heap[l] < heap[smallest]) 
		smallest = l; 
	if(r < size && heap[r] < heap[l]) 
		smallest = r;  //getting the smallest of i and its two children

    if (smallest != i){  // if any of its child is smaller
		swap(heap[i], heap[smallest]);  //swap with it
		heapify(smallest);  //call heapify for its child, until reached the leaf
	} 
}

void minHeap::replaceKey(int i, int new_val){
    heap[i] = new_val;

    while(i!=0 && heap[parent(i)] > heap[i]){ //checking if the new element is smaller than the parent, and then swapping accordingly
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void minHeap::deleteKey(int k) 
{ 
    replaceKey(k, INT_MIN);  //replacing the particular key, with INT_MIN, which will make it root
    extractMin();  //extracting the root
} 
 

void minHeap::printHeap(){
    for(int i=0;i<size;i++){
       cout<<heap[i]<<" ";
   }
}

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

int main() 
{ 
    minHeap h(11); 
    h.insertKey(2); 
    h.insertKey(3); 
    //h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(7); 
    h.insertKey(4); 
    h.insertKey(45);
    //h.insertKey(1); 
    h.printHeap();
    cout<<endl;
    cout<<h.extractMin()<<endl; 
    h.printHeap();
    cout<<endl;
    cout<<h.getMin()<<endl;
     
    
    h.replaceKey(2, 1); 
    cout <<h.getMin()<<endl; 
    h.printHeap();
    cout<<endl;
    /*
    h.printHeap();
    h.insertKey(5);
    cout<<endl;
    h.printHeap();*/
} 