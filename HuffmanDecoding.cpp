// HuffmanDecoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DataBase.h"
#include "Decrypt.h"
#include "UI.h"
using namespace std;

int main()
{
    DataBase db;
    db.build("Compress.bin");

    Decrypt decrypt;
    decrypt.build_priority_queue("AsciiFrequenciesV3.txt");
    decrypt.run(db.get_DB());

    UI ui;
    ui.display_results(decrypt.get_results());

    return 0;
}
