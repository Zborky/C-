#include<iostream>

using namespace std;

/*
 * Tento program implementuje algoritmus triedenia zlúčením na usporiadanie poľa celých čísel.
 * Zlúčené triedenie je algoritmus "rozdeli a panuj", ktorý rozdeľuje pole na dve polovice,
 * rekurzívne triedi každú polovicu a potom zlúči dve usporiadané polovice do jedného usporiadaného poľa.
 */

class MergeSort{
    private:
    // Pomocná funkcia, ktorá rekurzívne triedi pole
    void mergeSort(int array[], int left, int right){
        if(left < right){
            // Nájdite stredný bod na rozdelenie poľa na dve polovice
            int mid = left + (right - left) / 2;

            // Volajte mergeSort na prvú polovicu
            mergeSort(array, left, mid);

            // Volajte mergeSort na druhú polovicu
            mergeSort(array, mid + 1, right);

            // Zlúčte dve polovice usporiadané v predchádzajúcich krokoch
            merge(array, mid, left, right);
        }
    }

    public:
    // Táto funkcia inicializuje proces triedenia zlúčením
    void sort(int array[], int n){
        mergeSort(array, 0, n - 1);
    }

    // Táto funkcia zlúči dve polovice poľa
    void merge(int array[], int mid, int left, int right){
        int n1 = mid - left + 1;  // Veľkosť prvej polovice
        int n2 = right - mid;     // Veľkosť druhej polovice

        // Dočasné polia na uloženie dvoch polovíc
        int L[n1], R[n2];

        // Skopírujte údaje do dočasných polí L[] a R[]
        for(int i = 0; i < n1; i++){
            L[i] = array[left + i];
        }
        for(int i = 0; i < n2; i++){
            R[i] = array[mid + 1 + i];
        }

        // Počiatočné indexy pre dve podpolia a zlúčené pole
        int i = 0, j = 0, k = left;

        // Zlúčte dočasné polia späť do array[left..right]
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                array[k] = L[i];
                i++;
            } else {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        // Skopírujte zostávajúce prvky L[], ak nejaké sú
        while(i < n1){
            array[k] = L[i];
            i++;
            k++;
        }

        // Skopírujte zostávajúce prvky R[], ak nejaké sú
        while(j < n2){
            array[k] = R[j];
            j++;
            k++;
        }
    }
};

int main(){
    int array[] = {5, 2, 4, 1, 3};
    int n = sizeof(array) / sizeof(array[0]);

    MergeSort sorter;
    sorter.sort(array, n);

    // Vytlačte usporiadané pole
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    return 0;
}

