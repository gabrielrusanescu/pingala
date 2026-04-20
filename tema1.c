/*
Grupa: 161
Problema: 1
Nume: Rusănescu Gabriel
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <gmp.h>

void pingala(mpz_t rezultat, mpz_t baza, unsigned long int exp){
    if(exp==0){
        mpz_set_ui(rezultat, 1);
        return;
    }
    if(exp==1){
        mpz_set(rezultat, baza);
        return;
    }
    mpz_t aux;
    mpz_init(aux);
    pingala(aux, baza, exp/2);
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
    long pozstart=ftell(fin);
    int charcnt=0;
    int ch;
    while((ch=fgetc(fin))!=EOF && ch!=' ' && ch!='\n' && ch!='\r'){
        charcnt++;
    }
    char *bazastr=(char *)malloc((charcnt+1)*sizeof(char));
    if(!bazastr){
        perror("Eroare de alocare memorie pentru bazastr");
        fclose(fin);
        return 1;
    }
    fseek(fin, pozstart, SEEK_SET);
    unsigned long int exp;
    fscanf(fin, "%s %lu", bazastr, &exp);
    fclose(fin);
    mpz_t a, res;
    mpz_init_set_str(a, bazastr, 10);
    mpz_init(res);
    free(bazastr);
    pingala(res, a, exp);
    gmp_printf("Rezultat: %Zd\n", res);
    
    mpz_t teste;
    mpz_init(teste);
    //Test1: 2^10=1024
    mpz_set_ui(a, 2);
    pingala(teste, a, 10);
    assert(mpz_cmp_ui(teste, 1024)==0);

    //Test2: 5^3=125
    mpz_set_ui(a, 5);
    pingala(teste, a, 3);
    assert(mpz_cmp_ui(teste, 125)==0);

    //Test3: 10^5=100000
    mpz_set_ui(a, 10);
    pingala(teste, a, 5);
    assert(mpz_cmp_ui(teste, 100000)==0);

    printf("Toate cele 3 teste assert au trecut cu succes!\n");
    mpz_clear(a);
    mpz_clear(res);
    mpz_clear(teste);
    return 0;
}
