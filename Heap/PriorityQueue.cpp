#include<iostream>
#include<queue>

using namespace std;

int main(){
    // To create a Max Heap
    priority_queue<int> pq; // Max Heap

    // Insertion - O(logn)
    pq.push(1); 
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5); 

    // Peek - O(1)
    cout << "Top : " << pq.top() << endl;

    // Removal -  O(logn)
    pq.pop();

    cout << "Top : " << pq.top() << endl;

    // Size - O(1)
    cout << "Size : " << pq.size() << endl;

    // isEmpty - O(1)
    if(pq.empty()) {
        cout << "Heap is empty" << endl;
    }else {
        cout << "Heap is not empty" << endl;
    }

    // To create a Min Heap
    priority_queue<int, vector<int>, greater<int>> pq_;

    // Insertion - O(logn)
    pq_.push(1); 
    pq_.push(2);
    pq_.push(3);
    pq_.push(4);
    pq_.push(5); 

    // Peek - O(1)
    cout << "Top : " << pq_.top() << endl;

    // Removal -  O(logn)
    pq_.pop();

    cout << "Top : " << pq_.top() << endl;

    // Size - O(1)
    cout << "Size : " << pq_.size() << endl;

    // isEmpty - O(1)
    if(pq_.empty()) {
        cout << "Heap is empty" << endl;
    }else {
        cout << "Heap is not empty" << endl;
    }

    return 0;
}