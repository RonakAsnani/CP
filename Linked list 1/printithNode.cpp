/*Problem Statement: Print i-th Node Data
Problem Level: EASY
Problem Description:
For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.
Note :
Assume that the Indexing for the singly linked list always starts from 0.

If the given position 'i',  is greater than the length of the given singly linked list, then don't print anything.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line contains the value of 'i'. It denotes the position in the given singly linked list.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case, print the node data at the 'i-th' position of the linked list(if exists).

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
i  >= 0
Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3

Sample Output 1 :
2

Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
9 8 4 0 7 8 -1
3

Sample Output 2 :
3
0*/

#include<iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput()
{
    int data;
    cin>>data;
    Node* head = NULL;
    Node* prev =NULL;
    while(data != -1){
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
            prev =n;
        }
        prev->next = n;
        prev = prev->next;
        

        cin>>data;
    }
    return head;
}
void prin(Node* head,int x){
    int ans = 0;
    while(head != NULL){
        if(ans == x){
            cout<<head->data<<endl;
            return;
        }
        ans++;
        head = head->next;
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        Node* head = takeInput();
        int i;
        cin>>i;
        prin(head,i);
    }
    return 0;
}