# huffman-coding
This project implements Huffman encoding and decoding algorithms. It reads a pre-processed frequency file, AsciiFrequenciesV3.txt. The frequency file contains the frequencies of corresponding characters. It then builds a Huffman tree by using a PriorityQueue that stores the characters (or combined characters) and their frequencies in the ascending order of the frequencies. After that, the program reads in a compressed binary file, Compress.bin, and uses the Huffman tree to decrypt the information using C++ bitset operation. The decrypted message is printed to stdout.

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_code1.png?raw=true)

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_code2.png?raw=true)

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_code3.png?raw=true)

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_code4.png?raw=true)

## Architecture
The main program uses a FileIO class object to read a compressed binary file and store the data in a DataBase class object. Then it uses a Decrypt class object to read a pre-processed frequency file to build a Huffman tree from by using a PriorityQueue class object and then uses the Huffman tree to decrypt the compressed binary data and uses a UI class object to print the decrypted message to stdout.

## Requirements

C++ and C++ libraries: iostream, fstream, vector, tuple, algorithm, iterator, regex, bitset

## Technical Skills

Huffman encoding and decoding algorithms using polymorphism (in building polymorphic hierarchy of the Huffman tree), priority queue, regular expressions (to parse freqency file), smart pointers, several of
STL containers and C++ bitset (for bit level data operation), iterator, and STL algorithms. 

## Results

The decrypted text printed in stdout.

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_decrypted.png?raw=true)
