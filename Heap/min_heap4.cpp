#include<bits/stdc++.h>
using namespace std;

class minHeap {
public:
    int capacity, heapSize;
    int *heapArray;
    
    // Constructor to initialize the heap
    minHeap(int cap) {
        capacity = cap;
        heapSize = 0;
        heapArray = new int[capacity]; // dynamically creating heap array
    }
    
    // Function to get the index of the parent node.
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Function to get the index of the left child node.
    int left(int i) {
        return 2 * i + 1;
    }

    // Function to get the index of the right child node.
    int right(int i) {
        return 2 * i + 2;
    }

    // Extract the minimum element from the heap.
    int extractMinElement() {
        if(heapSize <= 0) {
            return -1;
        }
        if(heapSize == 1) {
            heapSize--;
            return heapArray[0];
        }

        // Store the Root(min) element
        int root = heapArray[0];

        heapSize--;
        heapArray[0] = heapArray[heapSize]; // copy the last element to the root
        heapArray[heapSize] = 0; // remove the last element

        // Resotre min heap invariant
        heapify(0); // places the newly updated root node to its correct position

        return root;
    }

    // Insert a new element into the heap
    void insert(int val) {
        int index = heapSize;
        heapSize++;
        heapArray[index] = val;
        
        // Resotre the heap property by swapping with the parent if necessary
        while(index > 0 && heapArray[index] < heapArray[parent(index)]){
            swap(heapArray[index], heapArray[parent(index)]);
            index = parent(index);
        }
    }

    // Delete an element ar a given index
    void deleteElement(int index) {
        if(index < heapSize) {
            // Decrease the key to the minimum possible value
            decreaseKeyElement(index, INT_MIN);

            // Remove the element from the heap.
            extractMinElement();
        }
    }
    void decreaseKeyElement(int index, int new_val) {
        // Update the element's value
        heapArray[index] = new_val;
        while(index > 0 && heapArray[index] < heapArray[parent(index)]){
            swap(heapArray[index], heapArray[parent(index)]);
            index = parent(index);
        }
    }
    
    // Heapify the heap from a given index
    void heapify(int index) {
        int l = left(index);
        int r = right(index);
        int smallest = index;

        // compare with child nodes
        if(l < heapSize && heapArray[smallest] > heapArray[l]){
            smallest = l;
        }
        if(r < heapSize && heapArray[smallest] > heapArray[r]){
            smallest = r;
        }

        // swap
        if(smallest != index) {
            swap(heapArray[index], heapArray[smallest]);
            // call the heapify for the swapped down node
            heapify(smallest);
        }
    } 
};

int main(){
    minHeap h(0);
    int T; cin >> T;
    while(T--) {
        int q; cin >> q;
        if(q == 0) {
            cout << h.extractMinElement() << endl;
        }
        else if(q == 2) {
            int val; cin >> val;
            h.insert(val);
        }
        else { // 1
            int index; cin >> index;
            h.deleteElement(index);
        }
    }
    // h.print();

    return 0;
}