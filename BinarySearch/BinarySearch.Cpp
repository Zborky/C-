#include<iostream>
#include<vector>

using namespace std;

/**
 * Funkcia binarySearch nájde zadaný prvok v zoradenom vektore pomocou algoritmu binárneho vyhľadávania.
 * 
 * Parametre:
 * - arr: Zoradený vektor celých čísel, v ktorom sa bude vyhľadávať.
 * - left: Ľavý index aktuálnej časti poľa, kde sa bude hľadať.
 * - right: Pravý index aktuálnej časti poľa, kde sa bude hľadať.
 * - x: Hľadaný prvok.
 * 
 * Návratová hodnota:
 * - Index hľadaného prvku v poli, alebo -1, ak sa prvok v poli nenachádza.
 */

int binarySearch(const vector<int>& arr,int left,int right,int x ){
    while(left <= right){
        int mid = left + (right + left) / 2;

        // Skontroluje, či je stredný prvok rovný hľadanému prvku
        if(arr[mid] == x){
            return mid;

        }
        // Ak je stredný prvok menší ako hľadaný prvok, hľadaj v pravej polovici
        if(arr[mid] < x){
            left = mid + 1;

        }else{
            right = mid - 1;
        }
    }
     //Hladany prvok sa v poli nenachadza 
     return -1;

}

int main(){
    vector<int> arr = {10,30,40,60,80};
    int x = 70;
    int result = binarySearch(arr,0,arr.size() - 1,x);

        if(result != -1){
            cout<<"Prvok " << x << "sa nachadza na indexe" << result << "." << endl;

        }else{
            cout << "Prvok " << x << "Sa v poli nenachadza" << endl; 

        }
    return 0;
}