/*Problem Statement: Reverse LL (Recursive)
Problem Level: EASY
Problem Description:
Given a singly linked list of integers, reverse it using recursion and return the head to the modified list.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^4
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1

Sample Output 1 :
8 7 6 5 4 3 2 1

Sample Input 2 :
2
10 -1
10 20 30 40 50 -1

Sample Output 2 :
10 
50 40 30 20 10*/
#include<iostream>
#include<utility>
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
        }else{
        prev->next = n;
        prev = prev->next;
        }

        cin>>data;
    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}
pair<Node*,Node*> rev(Node* head){
    //cout<<head->next<<" "<<head->next->data<<endl;
    if(head->next == NULL || head == NULL){
        pair<Node*,Node*> p;
        p.first = head;
        p.second = head;
        return p;
    }
    pair<Node*,Node*> x = rev(head->next);
    x.second->next = head;
    x.second  = x.second->next;
    x.second->next = NULL;
    return x;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Node* head = takeInput();

        pair<Node*,Node*> x = rev(head);
        print(x.first);
    }
    return 0;
}