#include <stdio.h>
#include <stdlib.h>


struct rekord{
    char nazwisko[20];
    int ocena;
};
typedef struct rekord Rekord;

Rekord* alokacja(int ilosc){
    Rekord* a;
    a = (Rekord*)malloc(ilosc * sizeof(Rekord));
    return a;
};

void jeden_rekord(Rekord* start, int x){
    printf("Podaj %d nazwisko: ", x);
    scanf("%s", start[x].nazwisko);
    printf("Podaj ocene: ");
    scanf("%d", &(start[x].ocena));
}

void cala_tablica(Rekord* calosc, int ilosc){
    for(int i=0; i< ilosc; i++){
        jeden_rekord(calosc, i);
    }
}

void wypisywanie_pojedynczego(Rekord* start, int x){
    printf("%s, %d\n", start[x].nazwisko, start[x].ocena);
}

void wypisywanie_calosci(Rekord* calosc, int ilosc){
    for(int i = 0;i<ilosc; i++){
        wypisywanie_pojedynczego(calosc, i);
    }
}

void dealokacja(Rekord* calosc){
    if (calosc == NULL){
        return;
    }
    free(calosc);
}

int main(){
    int ilosc;
    do{
        printf("Podaj liczbę rekordów: ");
        scanf("%d", &ilosc);
    }while(ilosc <=0);

    Rekord* calosc = alokacja(ilosc);

    cala_tablica(calosc, ilosc);

    wypisywanie_calosci(calosc, ilosc);

    dealokacja(calosc);

    return 0;
}