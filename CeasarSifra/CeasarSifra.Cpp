#include <iostream>
#include <string>

using namespace std;

string encryptCaesar(string plaintext, int shift) {
    string ciphertext = "";
    for (char& c : plaintext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = base + (c - base + shift) % 26;
        }
        ciphertext += c;
    }
    return ciphertext;
}

string decryptCaesar(string ciphertext, int shift) {
    return encryptCaesar(ciphertext, -shift);
}

int main() {
    string plaintext;
    int shift;

    // Vloz text na sifru
    cout << "Vloz slovo na sifru: ";
    getline(cin, plaintext);

    // Vloz hodnotu sift
    cout << "Vloz hodnotu sift (integer): ";
    cin >> shift;

    // zasifrovanie
    string encryptedText = encryptCaesar(plaintext, shift);

    // rozsifrovanie
    string decryptedText = decryptCaesar(encryptedText, shift);

    // vyysledok
    cout << "Original text: " << plaintext << endl;
    cout << "Encrypted text: " << encryptedText << endl;
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}