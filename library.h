#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_STRING 100

typedef struct {
    int id;
    char title[MAX_STRING];
    char author[MAX_STRING];
    char description[MAX_STRING];
    char user[MAX_STRING];
    float price;
    char category[MAX_STRING];
    int available; // 1: disponible, 0: non disponible
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Bibliothèque pleine.\n");
        return;
    }
    Book book;
    book.id = bookCount + 1;
    printf("Titre : ");
    scanf(" %[^\n]", book.title);
    printf("Auteur : ");
    scanf(" %[^\n]", book.author);
    printf("Description : ");
    scanf(" %[^\n]", book.description);
    printf("Nom d'utilisateur : ");
    scanf(" %[^\n]", book.user);
    printf("Prix : ");
    scanf("%f", &book.price);
    printf("Catégorie : ");
    scanf(" %[^\n]", book.category);
    book.available = 1;
    books[bookCount++] = book;
    printf("Livre ajouté avec succès.\n");
}

void displayBooks() {
    for (int i = 0; i < bookCount; i++) {
        printf("\nID : %d\nTitre : %s\nAuteur : %s\nDescription : %s\nUtilisateur : %s\nPrix : %.2f\nCatégorie : %s\nDisponibilité : %s\n",
               books[i].id, books[i].title, books[i].author, books[i].description, books[i].user, books[i].price, books[i].category,
               books[i].available ? "Disponible" : "Non disponible");
    }
}

void searchBook() {
    char keyword[MAX_STRING];
    printf("Rechercher par titre ou auteur : ");
    scanf(" %[^\n]", keyword);
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, keyword) || strstr(books[i].author, keyword)) {
            printf("\nID : %d\nTitre : %s\nAuteur : %s\n",
                   books[i].id, books[i].title, books[i].author);
        }
    }
}

void sortBooksByTitle() {
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if (strcmp(books[i].title, books[j].title) > 0) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Livres triés par titre.\n");
}

void saveToCSV() {
    FILE *file = fopen("books.csv", "w");
    if (!file) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%.2f,%s,%d\n", books[i].id, books[i].title, books[i].author,
                books[i].description, books[i].user, books[i].price, books[i].category, books[i].available);
    }
    fclose(file);
    printf("Données sauvegardées dans books.csv.\n");
}

#endif // LIBRARY_H_INCLUDED

