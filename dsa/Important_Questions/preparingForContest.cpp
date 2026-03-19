#include<bits/stdc++.h>
using namespace std;

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

// question link: https://codeforces.com/contest/377/problem/B
// VERY IMPORTANT Question => on Binary search on answer and Priority Queues (min heap)

struct Bug {
    int val;
    int index;
};

struct Student {
    int ability;
    int passes;
    int index;
};

// stores the final ans 
vector<int> ans;

bool isPossible(vector<Bug> &bugs, vector<Student> &students, int s, int days) {
    // can we complete the bugs in d days => work for each student = m / days 
    int n = students.size();
    int m = bugs.size();
    // we must take days long chunks => as we give student A to solve these chunks to be solved 

    auto cmp = [&](const Student &a, const Student &b) {
        // based on their passes 
        // return true if a has low priority than b 
        return a.passes > b.passes;
    };

    // use a min heap to store the students 
    priority_queue<Student, vector<Student>, decltype(cmp)> minHeap(cmp);

    vector<int> temp_ans(m);

    // we dont keep pushing the students very time => we maintain a pointer to handle traversal 
    int student_ptr = 0;

    // this should not exceed s
    long long total_passes = 0;

    // we must assign the best student with days bugs at the same time 
    // eg => 10 8 5 4 => 4 bugs can be assigned to anyone with ability >= 10 so we choose best 
    for(int i = 0; i < m; i += days) {
        int biggestBug = bugs[i].val;

        // push all the students who can do the biggestTask 
        while(student_ptr < n && students[student_ptr].ability >= biggestBug) {
            minHeap.push(students[student_ptr]);
            student_ptr++;
        } 

        // no student has the ability to fix this bug 
        if(minHeap.empty()) 
            return false;

        // assign the bug to the student with least passes  
        auto [ability, passes, student_idx] = minHeap.top();
        minHeap.pop();

        total_passes += passes * 1LL;

        if(total_passes > s) return false;

        // now populate the temp array 
        for(int j = i; j < i + days && j < m; j++) {
            temp_ans[bugs[j].index] = student_idx;
        }
    }

    ans = temp_ans;

    return true;
}


void solve(vector<Bug>&bugs, vector<Student>&students, int s) {
    // since we are supposed to fix the bugs fast we must apply binary search on the no of days 
    int m = bugs.size();

    int n = students.size();

    // the bugs are supposed to be sorted descending 
    auto cmp1 = [&](const Bug &a, const Bug &b) {
        // return true if a should be placed first => descending 
        return a.val > b.val;
    };

    // bugs are now in descending order 
    sort(bugs.begin(), bugs.end(), cmp1);

    auto cmp2 = [&](const Student &a, const Student &b) {
        // sort the students in desc on the basis of their ability 
        if(a.ability == b.ability) 
            return a.passes < b.passes;
        
        return a.ability > b.ability;
    };

    // sort the students in descending order on their ability 
    sort(students.begin(), students.end(), cmp2);

    // the main binary search on the days 
    // return FFFFTTTT => find the min no of days => first occurrence of Tree
    int low = 1, high = m;           // all the bugs fixed in one day or bugs finished in m days 
    int best_days = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(bugs, students, s, mid)) {
            best_days = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    // if best days = -1 then work cant be done 
    if(best_days == -1) {
        no;
    }
    else {
        yes;

        for(int i: ans)
            cout << i << " ";
        cout << endl;
    }
 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ans.clear();

    int n, m, s;
    cin >> n >> m >> s;

    vector<Bug> bugs(m);
    vector<Student> students(n);

    for(int i = 0; i < m; i++) {
        cin >> bugs[i].val;
        bugs[i].index = i;
    }

    for(int j = 0; j < n; j++) 
        cin >> students[j].ability;
    
    for(int j = 0; j < n; j++) {
        cin >> students[j].passes;
        students[j].index = j + 1;       // 1 based indexing 
    }

    solve(bugs, students, s);
}
