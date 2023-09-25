#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node() {
        //cout << "Node constructor called" << endl;
    }

    virtual ~Node() {
        //cout << "Node destructor called" << endl;
    }

    virtual float freq() = 0;

    virtual string symbol() = 0;
};

class Branch : public Node {
private:
    unique_ptr<Node> _Left;
    unique_ptr<Node> _Right;

public:
    Branch(Node* n0, Node* n1) {
        //cout << "Branch constructor called" << endl;
        _Left = unique_ptr<Node>(n0);
        _Right = unique_ptr<Node>(n1);
    }

    float freq() {
        return _Left->freq() + _Right->freq();
    }

    string symbol() {
        return _Left->symbol() + _Right->symbol();
    }

    Node* left() {
        return _Left.get();
    }

    Node* right() {
        return _Right.get();
    }
};

class Leaf : public Node {
private:
    float _freq;
    string _symbol;

public:
    Leaf(const string& s, float f) {
        //cout << "Leaf constructor called" << endl;
        _freq = f;
        _symbol = s;
    }

    float freq() {
        return _freq;
    }

    string symbol() {
        return _symbol;
    }
};

class PriorityQueue
{
    vector<unique_ptr<Node>> vdata;

public:
    PriorityQueue() { }
    Node* top();

    int size() {
        return vdata.size();
    }

    bool empty() {
        return vdata.size() < 1;
    }

    void push(Node* n);

    void pop();

    void print();
};
