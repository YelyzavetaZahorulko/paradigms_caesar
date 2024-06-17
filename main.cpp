#include <iostream>
#include <cstring>

char* encrypt(const char* rawText, int key) {
    int length = strlen(rawText);

    char* encryptedText = new char[length + 1];

    for (int i = 0; i < length; ++i) {
        char ch = rawText[i];

        if (ch >= 'A' && ch <= 'Z') {
            encryptedText[i] = 'A' + (ch - 'A' + key) % 26;
        }
        else if (ch >= 'a' && ch <= 'z') {
            encryptedText[i] = 'a' + (ch - 'a' + key) % 26;
        }
        else {
            encryptedText[i] = ch;
        }
    }
    encryptedText[length] = '\0';

    return encryptedText;
}


int main() {
    std::string inputText;
    std::cout << "Enter the text to be encrypted: ";
    std::getline(std::cin, inputText);

    int key;
    std::cout << "Enter the encryption key (integer value): ";
    std::cin >> key;

    const char* rawText = inputText.c_str();

    char* encrypted = encrypt(rawText, key);

    std::cout << "Original: " << rawText << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;

    delete[] encrypted;

    return 0;
}

