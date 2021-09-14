#include <stdio.h>


int lire_fichier( char *file, char *tab) {
    FILE * fichier;
    fichier = fopen(file,"r");
    if (fichier == NULL){
        return -1;
    } else {
        char c;
        int i=0;
        int count = 0;
        fscanf(fichier, "%c", &c);
        tab[0]=c;
        count++;
        while (!feof(fichier))
        {
            count++;
            fscanf(fichier, "%c", &c);
            i++;   
            tab[i]=c;
        }
    }
    fclose(fichier);
    return 1;
}

int ecrire_fichier(char *file, char *tab, int taille){
    FILE * fichier;
    fichier = fopen(file,"w");
    if (fichier == NULL){
        return 1;
    } else {
        int i;
        for (i = 0; i < taille; i++) {
            fprintf(fichier, "%d\n", tab[i]);
        }
    }
    fclose(fichier);
    return 0;
}


char decalage (char lettreLue, int decal){
    char lettreSuivanten;
    char c;
    if ((lettreLue >= '0' && lettreLue <= '9') || (lettreLue == ' ') 
        || (lettreLue == '.') || (lettreLue == '\n') || (lettreLue == '?') || (lettreLue == '!')){
        lettreSuivanten= lettreLue;
    } else if (lettreLue >= 'a' && lettreLue <= 'z') {
        c= lettreLue - 'a';
        c = c+decal;
        c= c%26;
        lettreSuivanten = c+'a';
    } else if (lettreLue >= 'A' && lettreLue <= 'Z') {
        lettreSuivanten = (((lettreLue - 'A') + decal) % 26) + 'A';
    }
    
    return lettreSuivanten;
}


int main (int argc, char **argv){
    int taille = 200;
    char tab[taille];
    char newtab[taille];
    lire_fichier(argv[1], tab);
    for (int i = 0; i < taille;i++){
        
    }
}