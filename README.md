# huffman-coding
This project implements Huffman encoding and decoding algorithms. It reads in a pre-processed frequency file, AsciiFrequenciesV3.txt, which contains the frequencies of corresponding characters. It then builds a Huffman tree from a PriorityQueue. After that, the program reads in a compressed binary file, Compress.bin, and uses the Huffman tree to decrypt the information by using C++ bitset operation. The decrypted message is printed to stdout.

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_code1.png?raw=true)

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_code2.png?raw=true)

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_code3.png?raw=true)

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_code4.png?raw=true)

## Requirements

C++ and C++ libraries: iostream, fstream, vector, tuple, algorithm, iterator, regex, bitset

## Technical Skills

Huffman encoding and decoding algorithms using polymorphism (in building polymorphic hierarchy of the Huffman tree), priority queue, regular expressions (to parse freqency file), smart pointers, several of
STL containers and C++ bitset, iterator, and algorithm. 

## Results

The decrypted text printed in stdout.

![image](https://github.com/carab9/huffman-coding/blob/main/huffman_decrypted.png?raw=true)
