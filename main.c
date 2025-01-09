#include <stdio.h>
#include <stdbool.h>
#include "inventory.h"
// #include "operation.c"

// struct items
// {
//     int id;
//     char name[201];
//     int quantity;
//     float price;
// };

void printOperations()
{
    printf("1.Add Item\n");
    printf("2.View Inventory\n");
    printf("3.Search Item by ID\n");
    printf("4.Update Item by ID\n");
    printf("5.Delete Item by ID\n");
    printf("6.Calculate Total Inventory Value\n");
    printf("7.Exit\n");
    printf("-----------------------------------------------------------------------\n");
}


int main()
{
    int choice, id, quantity, index;
    float price;
    char name[MAX_NAME_LENGTH];

    Inventory inventory;
    initInventory(&inventory);

    printf("------------------ Inventory management System ------------------------\n");

    do
    {
        printOperations();
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter item ID: ");
                scanf("%d",&id);
                getchar();
                printf("Enter Name: ");
                scanf("%[^\n]s",name);
                printf("Enter quantity: ");
                scanf("%d",&quantity);
                printf("Enter price: ");
                scanf("%f",&price);

                bool isAdded = addItem(&inventory,id,name,quantity,price);
                isAdded ? printf("Item added successfully!\n") : printf("Inventory is Full. Item cannot be added!");
                printf("-----------------------------------------------------------------------\n");
                break;
            case 2:
                if(inventory.count == 0){
                    printf("Inventory is empty!\n");
                }
                else{
                    printf("------------------ Inventory ------------------------\n");
                    printf("| %-6s | %-20s | %-10s | %-10s |\n", "ID","NAME","QUANTITY","PRICE");
                    for(int i=0;i<inventory.count;i++){
                        printf("| %-6d | %-20s | %-10d | %-10.2f |\n",
                            inventory.item[i].id,
                            inventory.item[i].name,
                            inventory.item[i].quantity,
                            inventory.item[i].price
                        );
                    }
                    printf("------------------------------------------------------\n");
                }
                break;
            case 3:
                printf("Enter item ID to search: ");
                scanf("%d",&id);
                index = searchItem(&inventory, id);
                if(index != -1){
                    printf("Item Found - ID : %d, Name %s, Quantity : %d, price: %.2f\n",
                    inventory.item[index].id,
                    inventory.item[index].name,
                    inventory.item[index].quantity,
                    inventory.item[index].price
                    );
                }
                else{
                     printf("Item with ID %d not found.\n", id);
                }
                break;
            case 4:
                printf("Enter Item ID to update: ");
                scanf("%d",&id);
                index = searchItem(&inventory,id);
                if(index != -1){
                    printf("Name: ");
                    scanf("%[^\n]s",name);
                    printf("Quantity: ");
                    scanf("%d",&quantity),
                    printf("price: ");
                    scanf("%f",&price);
                    updateItem(&inventory,index,name,quantity,price);
                    printf("Item updated Successfully!\n");
                }
                else{
                    printf("Item with ID %d not found.\n", id);
                }
                break;
            case 5:
                printf("Enter item to delete: ");
                scanf("%d",&id);
                index = searchItem(&inventory,id);
                if(index != -1){
                    deleteItem(&inventory, index);
                    printf("Item with index %d deleted Successfully!\n",id);
                }
                else{
                    printf("Item with index %d not found!",id);
                }
                break;
            case 6:
                printf("Total value of inventory: %.2f\n", calculateTotalValue(&inventory));
                break;
            case 7:
                printf("Exiting the program. Goodbye!");
                break;
            default:
                printf("Please enter the valid choice!");
                break;
        }
    } while (choice != 7);
    

    return 0;
}
    // while (1)
    // {
    //     int choice;
    //     printf("1.Add Item\n");
    //     printf("2.View Inventory\n");
    //     printf("3.Search Item by ID\n");
    //     printf("4.Update Item by ID\n");
    //     printf("5.Delete Item by ID\n");
    //     printf("6.Calculate Total Inventory Value\n");
    //     printf("7.Exit\n");
    //     scanf("%d", &choice);
    //     switch (choice)
    //     {
    //     case 1:
    //         printf("Add item here\n");
    //         break;
    //     case 2:
    //         printf("View Inventory\n");
    //         break;
    //     case 3:
    //         printf("Search Item\n");
    //         break;
    //     case 4:
    //         printf("Update Item\n");
    //         break;
    //     case 5:
    //         printf("Delete Item\n");
    //         break;
    //     case 6:
    //         printf("Calculate Inventory\n");
    //         break;
    //     case 7:
    //         printf("Thank you! Visit again :)");
    //         return 0;
    //     default:
    //         printf("Invalid Input!\n");
    //     }
    // }