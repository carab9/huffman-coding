#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "PriorityQueue.h"

Node* PriorityQueue::top()
{

    if (vdata.size() > 0)
        return vdata[0].get();
    return (*vdata.end()).get();

}

void PriorityQueue::push(Node* n)
{
    vdata.push_back(unique_ptr<Node>(n));
    sort(vdata.begin(), vdata.end(),
        [](const unique_ptr<Node>& a, const unique_ptr<Node>& b)
        {
            return a->freq() < b->freq();
        });
}

void PriorityQueue::pop()
{
    if (vdata.size() > 0) {
        vdata[0].release();
        vdata.erase(vdata.begin());
    }
}

void PriorityQueue::print()
{
    for_each(vdata.begin(), vdata.end(),
        [](const unique_ptr<Node>& n)
        {
            cout << n->symbol() << '\t' << n->freq() << endl;
        });
}
