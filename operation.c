#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "inventory.h"

#define INITIAL_CAPACITY 10

void initInventory(Inventory *inventory){
    inventory ->capacity = INITIAL_CAPACITY;
    inventory->count=0;
    inventory->item = (Item *)malloc(inventory -> capacity * sizeof(Item));
}

bool addItem(Inventory *inventory, int id, char name[], int quantity, float price){
    if(inventory->count >= inventory->capacity){
        return false;
    }
    Item newItem;
    newItem.id = id;
    strcpy(newItem.name,name);
    newItem.quantity = quantity;
    newItem.price = price;

    inventory->item[inventory->count] = newItem;
    inventory->count++;
    return true;
}

void resizeInventory(Inventory *inventory){
    inventory->capacity *= 2;
    inventory->item = (Item *)realloc(inventory->item,sizeof(Item) * inventory->capacity);
    if(inventory->item==NULL){
        printf("Memory allocation failed during resize.\n");
        exit(1);
    }
}

int searchItem(const Inventory *inventory, int id){
    for(int i=0;i<inventory->count;i++){
        if(inventory->item[i].id == id){
            return i;
        }
    }
    return -1;
}

void updateItem(Inventory *inventory, int index, char name[], int quantity, float price){
    if(index >=0 && index < inventory->count){
        strncpy(inventory->item[index].name,name,MAX_NAME_LENGTH-1);
        inventory->item[index].name[MAX_NAME_LENGTH-1]= '\0';
        inventory->item[index].quantity = quantity;
        inventory->item[index].price = price;

    }
}

void deleteItem(Inventory *inventory, int index){
    if(index > 0 && index < inventory->count){
        for(int i= index; i < inventory->count - 1 ; i++){
            inventory->item[i] = inventory->item[i+1];
        }
        inventory->count--;
    }
}

float calculateTotalValue(const Inventory *inventory){
    float total = 0.0;
    for(int i=0;i<inventory->count;i++){
        total += inventory->item[i].quantity * inventory->item[i].price;
    }
    return total;
}

void freeInventory(Inventory *inventory){
    free(inventory->item);
    inventory->item = NULL;
    inventory->count = 0;
    inventory->capacity = 0;
}