#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <iterator>
#include <regex>
#include "FileIO.h"
using namespace std;

unique_ptr<vector<unsigned char>> FileIO::read_bin_file(const char* filename) {
    auto data = make_unique<vector<unsigned char>>();
    string line;

    ifstream file;
    file.open(filename, ios::out | ios::binary);

    if (file.is_open()) {
        // Stop eating new lines in binary mode
        file.unsetf(ios::skipws);

        // get its size:
        streampos fileSize;

        file.seekg(0, ios::end);
        fileSize = file.tellg();
        file.seekg(0, ios::beg);

        // reserve capacity
        data->reserve(fileSize);

        data->insert(data->begin(),
            istream_iterator<char>(file),
            istream_iterator<char>());
        file.close();
    }

    /*
    for (int i = 0; i < data->size(); i++) {
        cout << data->at(i);
    }
    cout << endl;
    */

    return data;
}

unique_ptr<vector<tuple<string, float>>> FileIO::read_parse_txt(const char* filename) {
    auto data = make_unique<vector<tuple<string, float>>>();

    ifstream file;
    file.open(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            //cout << line << endl;
            regex pattern("\'(.+)\',([0-9]+.[0-9]+)");
            smatch match;

            if (regex_search(line, match, pattern)) {
                if (match.size() == 3) {
                    //cout << "match: " << match[0] << '\n';
                    //cout << "match: " << match[1] << '\n';
                    //cout << "match: " << match[2] << '\n';

                    string chr = match[1];
                    if (chr.size() == 2) {
                        if (chr[0] == '\\') {
                            chr = chr[1];
                        }
                    }

                    data->push_back(make_tuple(chr, stof(match[2])));
                }
            }

        }
        file.close();
    }

    /*
    for (int i = 0; i < data->size(); i++) {
        cout << get<0>(data->at(i)) << " " << get<1>(data->at(i)) << endl;
    }
    */

    return data;
}
