//************************* The Monk and Class Marks ***************************//

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    multimap<int,string> m;
    for(int i=0; i<n; i++){
        int marks;
        string name;
        cin >> name >> marks;
        m.insert({marks, name});
    }
    auto it = (--m.end());
    for(;;--it){
        if(it == m.begin()){
            cout << it->second << " " << it->first << endl;
            break;
        }
        cout << it->second << " " << it->first << endl;
    }
}