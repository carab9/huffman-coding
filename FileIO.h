#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
using namespace std;

class FileIO {
public:
    FileIO() {}

    unique_ptr<vector<unsigned char>> read_bin_file(const char* filename);

    unique_ptr<vector<tuple<string, float>>> read_parse_txt(const char* filename);
};

#endif // FILEIO_H