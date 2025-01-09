#ifndef  INVENTORY_H
#define  INVENTORY_H
#include<stdbool.h>

#define  MAX_NAME_LENGTH 50

// Structure to hold item details
typedef struct{
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
}   Item;

// Inventory Structure to handle dynamic array and count

typedef struct{
    Item *item;
    int capacity;
    int count;
}   Inventory;


// function prototypes
void initInventory(Inventory *inventory);
bool addItem(Inventory *inventory, int id,char name[], int quantity, float price);
int searchItem(const Inventory *inventory, int id);
void updateItem(Inventory *inventory, int index, char name[], int quantity, float price);
void deleteItem(Inventory *inventory, int index);
float calculateTotalValue(const Inventory *inventory);
void freeInventory(Inventory *inventory);
void resizeInventory(Inventory *inventory);

#endif