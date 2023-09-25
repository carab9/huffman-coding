#include <iostream>
#include <vector>
#include <tuple>
#include <bitset>
#include "FileIO.h"
#include "Decrypt.h"
using namespace std;

Decrypt::Decrypt() {}

void Decrypt::build_priority_queue(const char* freq_file) {
    FileIO file;

    auto v = file.read_parse_txt("AsciiFrequenciesV3.txt");
    if (v) {
        for (int i = 0; i < v->size(); i++) {
            pqueue.push(new Leaf(get<0>(v->at(i)), get<1>(v->at(i))));
        }
    }

    /*
    pqueue.push(new Leaf(" ", 1));
    pqueue.push(new Leaf("E", 1));
    pqueue.push(new Leaf("M", 1));
    pqueue.push(new Leaf("V", 1));
    pqueue.push(new Leaf("P", 2));
    pqueue.push(new Leaf("R", 2));
    pqueue.push(new Leaf("S", 4));
    pqueue.push(new Leaf("I", 5));
    */

    //pqueue.print();

    while (pqueue.size() > 1) {

        Node* n0 = pqueue.top();
        pqueue.pop();
        Node* n1 = pqueue.top();
        pqueue.pop();
        pqueue.push(new Branch(n0, n1));
    }

    //pqueue.print();

}

void Decrypt::run(const vector<unsigned char>& db) {
    if (pqueue.size() > 0) {
        Node* ptr = pqueue.top();
        for (int i = 0; i < db.size(); i++) {
            bitset<8> bits(db[i]);

            for (int j = bits.size() - 1; j >= 0; j -= 1) {
                if (typeid(*ptr) == typeid(Branch)) {
                    if (bits.test(j) == 0) {
                        ptr = dynamic_cast<Branch*>(ptr)->left();
                    }
                    else if (bits.test(j) == 1) {
                        ptr = dynamic_cast<Branch*>(ptr)->right();
                    }
                }

                if (typeid(*ptr) == typeid(Leaf)) {
                    data.push_back(dynamic_cast<Leaf*>(ptr)->symbol()[0]);
                    ptr = pqueue.top();
                }

            }
        }
    }
}
