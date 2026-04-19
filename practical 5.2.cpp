#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("data.txt");

    if (!file) {
        cout << "File open nahi hui!" << endl;
        return 0;
    }

    string line;
    int lines = 0, words = 0, chars = 0;

    while (getline(file, line)) {
        lines++;

        for (int i = 0; i < line.length(); i++) {
            chars++;

            if (i == 0 && line[i] != ' ')
                words++;
            else if (line[i] != ' ' && line[i - 1] == ' ')
                words++;
        }

        chars++;
    }

    file.close();

    cout << "Lines: " << lines << endl;
    cout << "Words: " << words << endl;
    cout << "Characters: " << chars << endl;

    return 0;
}
