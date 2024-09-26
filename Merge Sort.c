#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Generate random dataset
void gen_arr(int* arr,int n) {
    for (int j = 0; j < n; ++j) {
        arr[j] = rand() % 10000;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i=0,j=0,k=0;

    while(i<m && j<n)
    {
        if(nums1[i]<nums2[j])
        {
            nums1[k++] = nums1[i++];
        }
        else
        {
            nums1[k++] = nums2[j++];
        }
    }

    while(i<m)
    {
        nums1[k++]=nums1[i++];
    }
    while(j<n)
    {
        nums1[k++]=nums2[j++];
    }
}*/
int main() {
    srand(time(0));

    int n;
    clock_t start,end;
    double time_taken;
        int *arr = (int *)malloc(n * sizeof(int));

        printf("Dataset size: %d\n", n);

               // Merge Sort
        gen_arr(arr,n);

         for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
         printf("\n");
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Merge Sort: %f seconds\n", time_taken);


             for(int i=0;i<n;i++)
                printf("%d ",arr[i]);
         printf("\n");
        free(arr);
    }

    return 0;
}
