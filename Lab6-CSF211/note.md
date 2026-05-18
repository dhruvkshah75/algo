# syntax 
For defining max heap and min heap we use the following syntax 
## Max Heap 
```cpp
    // syntax to define max heap 
    priority_queue<int> max_heap;

    max_heap.push(10);
    max_heap.push(20);
    max_heap.push(15);

    int top_element = max_heap.top();
    max_heap.pop();

    // we can also store pair in max heap
    priority_queue<pair<int,int>> max_heap;

```

## Min Heap 
```cpp

    // syntax to define min heap 
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // we can also define min heap to store pairs 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    minHeap.push({10, 100});
    minHeap.push({10, 500});
    minHeap.push({5, 1000});

    // the top element will be {5, 1000} as first the pair.first value is compared 

```