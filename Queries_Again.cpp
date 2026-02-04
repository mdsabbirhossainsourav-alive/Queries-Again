#include <bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myQueue 
{
    public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;
    bool insert(int idx, int val) 
    {
        if (idx<0 || idx>sz)
        {
            return false;
        } 
        Node* newnode = new Node(val);
        sz++;
        if (idx == 0) 
        { 
            if (!head) 
            {
                head = tail = newnode;
            } 
            else 
            {
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
            return true;
        }
        Node* temp = head;
        for (int i=0; i<idx - 1; i++) 
        {
            temp = temp->next;
        }
        if (!temp->next) 
        { 
            temp->next = newnode;
            newnode->prev = temp;
            tail = newnode;
        } 
        else 
        { 
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next->prev = newnode;
            temp->next = newnode;
        }
        return true;
    }

    void push() 
    {
        cout << "L -> ";
        Node* temp = head;
        while (temp) 
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void pop() 
    {
        cout << "R -> ";
        Node* temp = tail;
        while (temp) 
        {
            cout << temp->val << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() 
{
    myQueue mq;
    int Q;
    cin >> Q;
    for (int i=0; i<Q; i++) 
    {
        int x,v;
        cin >> x >> v;
        if (!mq.insert(x,v)) 
        {
            cout << "Invalid" << endl;
        } 
        else
        {
            mq.push();
            mq.pop();
        }
    }
    return 0;
}
