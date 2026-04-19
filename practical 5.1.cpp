#include <iostream>
#include <string>
using namespace std;

int main() {
    string paragraph;
    cout << "Enter a paragraph:\n";
    getline(cin, paragraph);

    for (int i = 0; i < paragraph.length(); i++) {
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
            paragraph[i] = paragraph[i] + 32;
        }
    }

    string words[100];
    int freq[100];
    int count = 0;

    string word = "";


    for (int i = 0; i <= paragraph.length(); i++) {
        if (paragraph[i] == ' ' || paragraph[i] == '\0') {
            if (word != "") {
                int found = -1;


                for (int j = 0; j < count; j++) {
                    if (words[j] == word) {
                        found = j;
                        break;
                    }
                }

                if (found != -1) {
                    freq[found]++;
                } else {
                    words[count] = word;
                    freq[count] = 1;
                    count++;
                }
                word = "";
            }
        } else {
            word += paragraph[i];
        }
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < count; i++) {
        cout << words[i] << " : " << freq[i] << endl;
    }

    return 0;
}
