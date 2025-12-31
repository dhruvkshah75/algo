#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define mod 1e9+7
#define PI 3.14159265358979323846
#define f(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define all(a) (a).begin(), (a).end()

bool is_positive(int x){
    return x>0;
}

void solve(){
    /*
        all_of , none_of, and any_of and lambda functions
        all_of checks a given condition on all elements if all satisfy then it returns true;
    */
    // lambda function

    auto func1 = [](int x, int y){
        return x+y;
    };
    cout << func1(2, 8) << endl;
    //*******************************************************

    vector<int> v = {2, 3, 5};
    cout << all_of(v.begin(), v.end(), 
        [](int x){return x>0;}) << endl;     
    // all_of(all(v), condtion as a lamda function)

    cout << all_of(all(v), is_positive) << endl;

    // any_of if the condition satisfies on at least 1 element then it will return true otherwise false

    cout << any_of(all(v), 
        [](int x){return x<0;}) << endl;

    // none_of if no element in the vector satisfies the condition then it will return true otherwise false



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}