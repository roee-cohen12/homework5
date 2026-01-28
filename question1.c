#include <stdio.h>
#include <stdbool.h>
#define NUM_PLATFORMS 3
#define MAX_FARM_SIZE 1000

bool is_sorted(int arr[], int n);
bool is_sorted_in_reverse(int arr[], int n);

bool shouldSwapCapybaras(int pop1, int plat1, int pop2, int plat2) {
    if (plat1 == plat2) {
        if (pop2 > pop1) {
            return true;
        }
    }
    if (plat1 > plat2) {
        return true;
    }
    return false;
}

void swapCapybaras(int popularity[], int platform[], int i, int j) {
    int temp;
    temp = popularity[i];
    popularity[i] = popularity[j];
    popularity[j] = temp;
    temp = platform[i];
    platform[i] = platform[j];
    platform[j] = temp;
}

void swap(int* index1, int* index2) {
    int temp = *index1;
    *index1 = *index2;
    *index2 = temp;
}

int max_index_arr(int arr[], int n) {
    int index = 0;
    int max = arr[0];
    for (int i = 1; i <= n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

void max_sort_arr_in_reverse(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int max_i = max_index_arr(&arr[i], n - i);
        swap(&arr[i], &arr[max_i + i]);
    }
}

void bubble_sort_in_reverse(int arr[], int n) {
    while (!is_sorted_in_reverse(arr, n)) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
            }
        }
    }
}

bool is_sorted(int arr[], int n) {
    if (n <= 1) {
        return true;
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool is_sorted_in_reverse(int arr[], int n) {
    if (n <= 1) {
        return true;
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }
    return true;
}

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

void print_arr(int arr[], int n) {
    printf("\n--------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n--------------------\n");
}

void viralCapySort(int popularity[], int platform[], int n) {

    while (!is_special_sorted(popularity, platform, n)) {
        for (int i = 0; i < n - 1; i++) {
            if (shouldSwapCapybaras(popularity[i], platform[i], popularity[i + 1],  platform[i + 1])) {
                swapCapybaras(popularity, platform, i, i + 1);
            }
        }
        print_arr(popularity, n);
        print_arr(platform, n);
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
    //print_arr(popularity, n);
    //bubble_sort_in_reverse(popularity, n);
    for (int i = 0; i < n; i++){
        printf("%d", popularity[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d", platform[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}