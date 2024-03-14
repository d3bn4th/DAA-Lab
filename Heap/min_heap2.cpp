#include<bits/stdc++.h>

using namespace std;
class minHeap {
public:
    vector<int> heap;
    int size;
    // Constructor for the class.
    minHeap(int sz) {
        // Write your code here.
        size = sz;
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        // Write you code here.
        size = heap.size();
        if(size == 0) return -1;
        if(size == 1) return heap[0];
        int root = heap[0]; // Min Element
        heap[0] = heap[size - 1];
        // cout << heap[0];
        heap.pop_back();
        // propogation of new root
        int index = 0;
        while(index < size) {
            int left = 2*index + 1;
            int right = 2 *index + 2;
            int leftval = 0, rightval = 0;
            if(left < size ) leftval = heap[left];
            if(right < size) rightval = heap[right];
            if(leftval > heap[index] && rightval > heap[index]) {
                break; // heap[index] is in its correct place
            }
            else if(leftval <= rightval) {
                swap(heap[index], heap[left]);
                index = left;
            }
            else {
                swap(heap[index], heap[right]);
                index = right;
            }
        }  
        return root;
        
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        // Check if the heap is empty or the index is out of bounds
        if(heap.size() == 0 || ind < 0 || ind >= heap.size()) {
            cout << "Index is out of bounds or heap is empty." << endl;
            return;
        }

        // Replace the element to be deleted with the last element in the heap
        // swap(heap[ind], heap[heap.size() - 1]);
        heap[ind] = heap[heap.size() - 1];
        size--;

        // Remove the last element (which is now the element to be deleted)
        heap.pop_back();

        // Heapify the heap starting from the index of the deleted element
        int parent = (ind - 1) / 2;
        if(ind != 0 && heap[parent] > heap[ind]) {
            // If the current node is smaller than the parent, we need to sift up
            while(ind != 0 && heap[parent] > heap[ind]) {
                swap(heap[ind], heap[parent]);
                ind = parent;
                parent = (ind - 1) / 2;
            }
        } else {
            // Otherwise, we need to sift down
            while(true) {
                int left = 2 * ind + 1; // left child
                int right = 2 * ind + 2; // right child
                int smallest = ind;

                if(left < heap.size() && heap[left] < heap[smallest]) {
                    smallest = left;
                }
                if(right < heap.size() && heap[right] < heap[smallest]) {
                    smallest = right;
                }
                if(smallest != ind) {
                    swap(heap[ind], heap[smallest]);
                    ind = smallest;
                } else {
                    break;
                }
            }
        }
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        // Write you code here.
        heap.push_back(val);
        int index = heap.size() - 1;
        while(index > 0) {
            // find the parent node
            int parent = (index - 1)/2;
            if(heap[parent] > heap[index]) {
                // swap
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }
    void print(){
        cout << "Heap: ";
        for(int i = 0; i < heap.size(); i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    
    minHeap h(0);
    int T; cin >> T;
    while(T--) {
        int q;
        cin >> q;
        if(q == 0){
            cout << h.extractMinElement() << endl;
        }
        else if(q == 2){
            int val; cin >> val;
            h.insert(val);
        }
        else {
            int idx; cin >> idx;
            h.deleteElement(idx);
        }
        // h.print();
    }
    return 0;
}