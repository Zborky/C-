#include <iostream>
#include <string>

using namespace std;

/**
 * Encrypts a plaintext string using the Caesar cipher with a given shift.
 *
 * Parameters:
 * - plaintext: The plaintext string to be encrypted.
 * - shift: The number of positions to shift each letter in the alphabet.
 *
 * Returns:
 * - The encrypted ciphertext string.
 */
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

/**
 * Decrypts a ciphertext string using the Caesar cipher with a given shift.
 *
 * Parameters:
 * - ciphertext: The ciphertext string to be decrypted.
 * - shift: The number of positions to shift each letter in the alphabet.
 *
 * Returns:
 * - The decrypted plaintext string.
 */
string decryptCaesar(string ciphertext, int shift) {
    return encryptCaesar(ciphertext, -shift);
}

int main() {
    string plaintext;
    int shift;

    // Get the plaintext from the user
    cout << "Enter the text to encrypt: ";
    getline(cin, plaintext);

    // Get the shift value from the user
    cout << "Enter the shift value (integer): ";
    cin >> shift;

    // Encrypt the plaintext
    string encryptedText = encryptCaesar(plaintext, shift);

    // Decrypt the ciphertext
    string decryptedText = decryptCaesar(encryptedText, shift);

    // Print the results
    cout << "Original text: " << plaintext << endl;
    cout << "Encrypted text: " << encryptedText << endl;
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
