#include <iostream>
#include <cstring>

extern "C" {
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

    char* decrypt(char* encryptedText, int key) {
        int length = std::strlen(encryptedText);
        char* decryptedText = new char[length + 1];

        for (int i = 0; i < length; ++i) {
            char ch = encryptedText[i];

            if (ch >= 'a' && ch <= 'z') {
                decryptedText[i] = 'a' + (ch - 'a' - key + 26) % 26;
            } else if (ch >= 'A' && ch <= 'Z') {
                decryptedText[i] = 'A' + (ch - 'A' - key + 26) % 26;
            } else {
                decryptedText[i] = ch;
            }
        }

        decryptedText[length] = '\0';
        return decryptedText;
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
        char* decrypted = decrypt(encrypted, key);

        std::cout << "Original: " << rawText << std::endl;
        std::cout << "Encrypted: " << encrypted << std::endl;
        std::cout << "Decrypted: " << decrypted << std::endl;

        delete[] encrypted;
        delete[] decrypted;

        return 0;
    }
}
