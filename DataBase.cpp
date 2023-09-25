#include <iostream>
#include <vector>
#include "FileIO.h"
#include "DataBase.h"
using namespace std;

void DataBase::build(const char* data_file) {
    FileIO file;
    auto v = file.read_bin_file(data_file);
    if (v) {
        db = *v;
    }
}