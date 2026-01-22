#include <stdio.h>
#include <stdbool.h>
#define NUM_PLATFORMS 3
#define MAX_FARM_SIZE 1000

bool shouldSwapCapybaras(int pop1, int plat1, int pop2, int plat2);
void swapCapybaras(int popularity[], int platform[], int i, int j);
bool is_special_sorted(int pop[], int plat[], int n);
void viralCapySort(int popularity[], int platform[], int n);

//use the special terms for swap
bool shouldSwapCapybaras(int pop1, int plat1, int pop2, int plat2) {

    /*if the platform are the same, check popularity criteria,
     *becuase we iter left to right and the sorted popularity should be from
     *high to low check accordingly*/
    if (plat1 == plat2) {
        if (pop2 > pop1) {
            return true;
        }
    }
    //no need to check, swap!
    if (plat1 > plat2) {
        return true;
    }
    return false;
}

//special swap. swap elements in two arrays
void swapCapybaras(int popularity[], int platform[], int i, int j) {
    int temp;
    temp = popularity[i];
    popularity[i] = popularity[j];
    popularity[j] = temp;
    temp = platform[i];
    platform[i] = platform[j];
    platform[j] = temp;
}

/*check if the arrays are sorted according to the requirements, which are
 *lower platform means more popularity, then sort locally via for each platform
 */
bool is_special_sorted(int pop[], int plat[], int n) {
    if (n <= 1) {
        return true;
    }
    for (int i = 0; i < n - 1; i++) {
        if (plat[i] > plat[i + 1]) {
            return false;
        }
        if (plat[i] == plat[i + 1]) {
            if (pop[i] < pop[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

/*iterate popularity, use auxiliary function to check if the arrays are sorted
 *correctly */
void viralCapySort(int popularity[], int platform[], int n) {

    while (!is_special_sorted(popularity, platform, n)) {
        //use bubble sort to swap element via the special terms
        for (int i = 0; i < n - 1; i++) {
            //use the given auxiliary functions
            if (shouldSwapCapybaras(popularity[i], platform[i],
                popularity[i + 1],  platform[i + 1])) {

                swapCapybaras(popularity, platform, i, i + 1);
            }
        }
    }

}

int main() {
    int n, popularity[MAX_FARM_SIZE], platform[MAX_FARM_SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &popularity[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &platform[i]);
    }
    viralCapySort(popularity, platform, n);
    for (int i = 0; i < n; i++){
        printf("%d", popularity[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d", platform[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}//
// Created by roee7 on 22/01/2026.
//