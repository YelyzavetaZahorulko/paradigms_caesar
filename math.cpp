#include <cstdio>
#include <iostream>
#include <dlfcn.h>

typedef char* (*encrypt_func)(const char*, int);
typedef char* (*decrypt_func)(const char*, int);

int main() {
    // Load the dynamic library
    void* handle = dlopen("./libcrypt.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    encrypt_func encrypt = (encrypt_func)dlsym(handle, "encrypt");
    if (!encrypt) {
        std::cerr << "Error: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    decrypt_func decrypt = (decrypt_func)dlsym(handle, "decrypt");
    if (!decrypt) {
        std::cerr << "Error: " << dlerror() << std::endl;
        dlclose(handle);
        return 1;
    }

    std::string inputText;
    std::cout << "Enter the text to be encrypted: ";
    std::getline(std::cin, inputText);

    int key;
    std::cout << "Enter the encryption key (integer value): ";
    std::cin >> key;

    char choice;
    std::cout << "Do you want to (e)ncrypt or (d)ecrypt the text? ";
    std::cin >> choice;

    const char* rawText = inputText.c_str();
    char* result = nullptr;

    if (choice == 'e' || choice == 'E') {
        result = encrypt(rawText, key);
        std::cout << "Encrypted text: " << result << std::endl;
    } else if (choice == 'd' || choice == 'D') {
        result = decrypt(rawText, key);
        std::cout << "Decrypted text: " << result << std::endl;
    } else {
        std::cerr << "Invalid choice." << std::endl;
    }

    if (result) {
        delete[] result;
    }

    dlclose(handle);
    return 0;
}
