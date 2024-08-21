#include <fstream>        // Provides functionalities for file input and output operations.
#include <iostream>
#include <string>

using namespace std;

void compressFile(const string &inputFile, const string &outputFile) {
	
  ifstream in(inputFile);        // Opens the input file for reading from input file.
  ofstream out(outputFile);      //Opens the output file for writing into thr output file.

  if (!in.is_open() || !out.is_open()) {
    cerr << "Error opening file(s)!" << endl;      // It will tell us wheather both input and output files are open or not.
    return;
  }

  char present_char, old_char;
  int count = 1;

  in.get(old_char);            // It will retrieve 1st character from the input file.
  while (in.get(present_char)) {              // loop, use to get other characters present n the input file.
    if (present_char == old_char) {
      ++count;
    } else {
      out.put(old_char);
      out << count;
      old_char = present_char;
      count = 1;
    }
  }

  out.put(old_char);                // Use to write first character in the output file.
  out << count;

  in.close();
  out.close();
}

void decompressFile(const string &inputFile, const string &outputFile) {
  ifstream in(inputFile);
  ofstream out(outputFile);

  if (!in.is_open() || !out.is_open()) {
    cerr << "Error opening file(s)!" << endl;
    return;
  }

  char present_char;
  int count;

  while (in.get(present_char) && in >> count) {
    for (int i = 0; i < count; ++i) {
      out.put(present_char);
    }
  }

  in.close();
  out.close();
}

int main() {
  string inputFile = "input.txt";
  string compressedFile = "compressed.txt";
  string decompressedFile = "decompressed.txt";

  compressFile(inputFile, compressedFile);
  cout << "File compressed successfully." << endl;

  decompressFile(compressedFile, decompressedFile);
  cout << "File decompressed successfully." << endl;

  return 0;
}
