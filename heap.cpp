/*
Que. Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() 
{
    int n; // Number of students
    cout << "Enter the number of students: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid number of students.\n";
        return 1;
    }
    
    priority_queue<int> maxHeap; // Max-Heap
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap
    
    cout << "Enter the marks of the students:\n";
    for (int i = 0; i < n; ++i) {
        int mark;
        cin >> mark;
        maxHeap.push(mark);
        minHeap.push(mark);
    }
    
    // Get maximum and minimum marks
    int maxMarks = maxHeap.top();
    int minMarks = minHeap.top();
    
    cout << "Maximum marks obtained: " << maxMarks << endl;
    cout << "Minimum marks obtained: " << minMarks << endl;
    
    return 0;
}

/*
OUTPUT
Enter the number of students: 6
Enter the marks of the students:
80
90
40
60
20
30
Maximum marks obtained: 90
Minimum marks obtained: 20
*/