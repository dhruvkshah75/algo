# syntax 
For defining max heap and min heap we use the following syntax 
```cpp
    // syntax to define max heap 
    priority_queue<int> max_heap;

    max_heap.push(10);
    max_heap.push(20);
    max_heap.push(15);

    int top_element = max_heap.top();
    max_heap.pop();


    // syntax to define min heap 
    priority_queue<int, vector<int>, greater<int>> min_heap;

```