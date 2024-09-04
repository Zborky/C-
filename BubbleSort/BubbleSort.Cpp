#include <iostream>
#include <vector>

using namespace std;

/**
 * Funkcia bubbleSort zoradí zadaný vektor pomocou algoritmu Bubble Sort.
 * 
 * Bubble Sort je jednoduchý triediaci algoritmus, ktorý opakovane prechádza
 * zoznamom, porovnáva susedné prvky a vymieňa ich, ak sú v nesprávnom poradí.
 * Tento proces pokračuje, kým zoznam nie je úplne zoradený.
 * 
 * Parametre:
 * - arr: Vektor celých čísel, ktorý bude zoradený.
 * 
 * Princíp algoritmu:
 * 1. Pre každý prvok vektora (okrem posledného):
 *    a. Pre každý prvok vektora od začiatku až po n-i-1:
 *       i. Porovnaj aktuálny prvok s nasledujúcim prvkom.
 *       ii. Ak je aktuálny prvok väčší ako nasledujúci, vymení ich.
 * 2. Opakuj krok 1, kým sa všetky prvky neprejdu a nevymenia na správne miesta.
 * 
 * Časová zložitosť:
 * - Najhoršia a priemerná: O(n^2)
 * - Najlepšia (keď je pole už zoradené): O(n)
 * 
 * Priestorová zložitosť:
 * - O(1) (in-place algoritmus, nevyžaduje dodatočnú pamäť okrem vstupného poľa)
 */
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) { // Prechádza pole n-1 krát
        for (int j = 0; j < n-i-1; j++) {  // Prechádza nesprávne zoradené časti poľa
            if (arr[j] > arr[j+1]) { // Ak je prvok väčší ako nasledujúci, vymení ich
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {55, 66, 78, 34, 89, 90, 9};
    bubbleSort(arr);
    cout << "Zoradene pole: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}