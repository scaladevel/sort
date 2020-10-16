#include <stdio.h>


void merge(int *Arr, int start, int mid, int end);
void sort(int *array, int inicio, int final);
void imprimevetor(int *vetor, int inicio, int fim);

int main(void){

    int vetor[10] = {8, 4, 3, 2, 9, 5, 123, 1, 9, 7};

    imprimevetor(vetor,0,10);

    sort(vetor, 0, 9);

    imprimevetor(vetor,0,10);

    return 0;
}

void imprimevetor(int *vetor, int inicio, int fim){

    for (int i=inicio;i<fim; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void merge(int *Arr, int start, int mid, int end){

    int tamv1 = mid - start + 1;
    int tamv2 = end - mid;

    int vetL[tamv1];
    int vetR[tamv2];

    for (int i=0; i<tamv1; i++){
        vetL[i] = Arr[start + i];
    }

    for (int j=0; j<tamv2; j++){
        vetR[j] = Arr[mid+1+j];
    }

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < tamv1 && j < tamv2) {
        if (vetL[i] <= vetR[j]) {
            Arr[k] = vetL[i];
            i++;
        } else {
            Arr[k] = vetR[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either vetL or vetR,
    // pick up the remaining elements and put in Array[p..r]
    while (i < tamv1) {
        Arr[k] = vetL[i];
        i++;
        k++;
    }

    while (j < tamv2) {
        Arr[k] = vetR[j];
        j++;
        k++;
    }

}



void sort(int *array, int inicio, int final){

    //printf("Antes do If inicio: %d , final: %d\n ", inicio, final);
    if(inicio<final){
       // printf("inicio: %d , final: %d\n ", inicio, final);
        int meio = (final + inicio)/2;
        sort(array, inicio, meio);
        sort(array, meio+1, final);
        merge(array, inicio, meio, final);
    }

}
