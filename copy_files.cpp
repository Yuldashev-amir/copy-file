// copy_files.cpp Программа копирует один файл в другой
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const int static Buffer = 1024;

int main(int argc, char * argv[])
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    using std::fstream;
    using std::ios_base;

    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " filename[e]\n";
        std::cerr << "Need 2 directories: " << "input_file output_file\n";
        exit(EXIT_FAILURE);
    }

    string InFile = argv[1];
    string OutFile = argv[2];

    fstream inFile(InFile, ios_base::in | ios_base::out | ios_base::binary);
    fstream outFile(OutFile, ios_base::in | ios_base::out | ios_base::binary);

    if (!inFile.is_open())
    {
        std::cerr << "Error: Failed to open input file: ";
        exit(EXIT_FAILURE);
    }

    if (!outFile.is_open())
    {
        std::cerr << "Error: Failed to open output file: ";
        exit(EXIT_FAILURE);
    }

    char buf[Buffer];
    size_t totalBytesCopied = 0;


    while (inFile.read(buf, sizeof buf) || inFile.gcount() > 0)
    {
        outFile.write(buf, inFile.gcount());
        if (!outFile)
        {
            std::cerr << "Error input in file: " << OutFile << endl;
            exit(EXIT_FAILURE);
        }
        totalBytesCopied += inFile.gcount();
    }

    cout << "File successfully copied! Total bytes: " << totalBytesCopied << endl;


    inFile.close();
    outFile.close();

    return 0;
}
