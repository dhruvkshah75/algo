#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

// Function to demonstrate vector of vector
void demonstrateVectorOfVector() {
    cout << "Demonstrating vector of vectors:" << endl;

    // Creating a 2D vector (vector of vectors)
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Accessing elements of the vector of vectors
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to demonstrate map container
void demonstrateMap() {
    cout << "Demonstrating map container:" << endl;

    // Creating a map (key-value pairs)
    map<string, int> m;
    
    // Inserting elements into the map
    m["Alice"] = 25;
    m["Bob"] = 30;
    m["Charlie"] = 35;

    // Accessing elements of the map
    for (const auto& pair : m) {
        cout << pair.first << " is " << pair.second << " years old." << endl;
    }

    // Searching in the map
    string name = "Bob";
    auto it = m.find(name);
    if (it != m.end()) {
        cout << name << " found, age: " << it->second << endl;
    } else {
        cout << name << " not found in the map." << endl;
    }
}

// Function to demonstrate set container
void demonstrateSet() {
    cout << "Demonstrating set container:" << endl;

    // Creating a set (unique elements)
    set<int> s;

    // Inserting elements into the set
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(10);  // Duplicate element, will be ignored

    // Accessing elements of the set
    for (const int& num : s) {
        cout << num << " ";
    }
    cout << endl;

    // Searching in the set
    int searchElement = 20;
    auto it = s.find(searchElement);
    if (it != s.end()) {
        cout << "Element " << searchElement << " found in the set." << endl;
    } else {
        cout << "Element " << searchElement << " not found in the set." << endl;
    }
}

int main() {
    // Demonstrating vector of vectors
    demonstrateVectorOfVector();

    // Demonstrating map
    demonstrateMap();

    // Demonstrating set
    demonstrateSet();

    return 0;
}
