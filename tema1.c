/*
Grupa: 161
Problema: 1
Nume: Rusănescu Gabriel
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <gmp.h>

void pingala(mpz_t rezultat, mpz_t baza, unsigned long int exp) {
    if (exp==0) {
        mpz_set_ui(rezultat, 1);
        return;
    }
    
    if (exp==1) {
        mpz_set(rezultat, baza);
        return;
    }

    mpz_t aux;
    mpz_init(aux);

    pingala(aux, baza, exp / 2);
    mpz_mul(rezultat, aux, aux);

    if (exp%2!=0) {
        mpz_mul(rezultat, rezultat, baza);
    }

    mpz_clear(aux);
}

int main(){
    FILE *fin=fopen("date.in", "r");
    if(!fin){
        perror("Eroare la deschiderea fisierului date.in");
        return 1;
    }

    char baza_str[1024];
    unsigned long int exp;

    if(fscanf(fin, "%s %lu", baza_str, &exp)!=2) {
        fclose(fin);
        return 1;
    }
    fclose(fin);

    mpz_t a, res;
    mpz_init_set_str(a, baza_str, 10);
    mpz_init(res);

    pingala(res, a, exp);
    gmp_printf("Rezultat: %Zd\n", res);

    mpz_t test_res;
    mpz_init(test_res);

    //1: 2^10 = 1024
    mpz_set_ui(a, 2);
    pingala(test_res, a, 10);
    assert(mpz_cmp_ui(test_res, 1024)==0);

    //2: 5^3 = 125
    mpz_set_ui(a, 5);
    pingala(test_res, a, 3);
    assert(mpz_cmp_ui(test_res, 125)==0);

    //3: 10^5 = 100000
    mpz_set_ui(a, 10);
    pingala(test_res, a, 5);
    assert(mpz_cmp_ui(test_res, 100000)==0);

    printf("Toate testele de verificare assert au trecut cu succes!\n");

    mpz_clear(a);
    mpz_clear(res);
    mpz_clear(test_res);
    return 0;
}