#include <stdio.h>
#include "library.h"

int main() {
    int choice;
    do {
        printf("\n1. Ajouter un livre\n2. Afficher les livres\n3. Rechercher un livre\n4. Trier les livres par titre\n5. Sauvegarder dans un CSV\n0. Quitter\nVotre choix : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: sortBooksByTitle(); break;
            case 5: saveToCSV(); break;
            case 0: printf("Au revoir.\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choice != 0);
    return 0;
}
