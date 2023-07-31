/**
 *  author : coderstack
 **/

#include "bits/stdc++.h"

using namespace std;

vector<int> order;

struct node
{
    int i, data;
    node *next;
    node(int i, int data)
    {
        this->i = i;
        this->data = data;
        next = NULL;
    }
};

node *insertProcess(node *head, int i)
{
    int d;
    cin >> d;

    node *p = new node(i, d);
    if (!head)
    {
        head = p;
        head->next = head;
    }
    else
    {
        node *t = head;
        while (t->next != head)
            t = t->next;

        t->next = p;
        p->next = head;
    }

    return head;
}

node *deleteProcess(node *n)
{
    if (n->next != n && n->data == 0)
    {
        node *t = n->next;
        n->data = t->data;
        n->i = t->i;
        n->next = t->next;
        delete t;

    }

    return n;
}

node *computeTask(node *n)
{
    if (n->data > 10)
    {
        n->data -= 10;
    }
    else
    {
        n->data = 0;
        order.emplace_back(n->i);
        n = deleteProcess(n);
    }

    return n;
}

void solve(node *head)
{
    int time = 0;
    node *t = head;
    while (t != NULL)
    {
        if (t->data == 0)
            break;

        time += 10;
        int id = t->i;
        t = computeTask(t);
        if(id == t->i)
            t = t->next; 
    }

    cout << "Time taken to finish all the above processes : " << time << '\n';
    cout << "Order in which tasks were executed :\n";

    vector<int> :: iterator it;
    for(it = order.begin(); it != order.end(); it++)
        cout << *it << " ";
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cout << "Enter number of processes\n";
    int n, i = 1;
    cin >> n;

    cout << "Enter time of each process\n";
    node *head = NULL;
    while (n--)
    {
        head = insertProcess(head, i);
        i += 1;
    }

    solve(head);

    return 0;
}