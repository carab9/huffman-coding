#ifndef DECRYPT_H
#define DECRYPT_H

#include <vector>
#include "PriorityQueue.h"
using namespace std;

class Decrypt {
private:
    vector<char> data;
    PriorityQueue pqueue;

public:
    Decrypt();

    void build_priority_queue(const char* freq_file);

    void run(const vector<unsigned char>& db);

    const vector<char>& get_results() const {
        return data;
    }

};

#endif // DECRYPT_H