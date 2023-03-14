#define _CRT_SECURE_NO_WARNINGS
#include"ShoppingList.h"
#include<stdio.h>
#include<stdlib.h> // For malloc() and free()

//writing a fuction which will add new item to the list if there is enough space. 
void addItem(struct ShoppingList *list)
{
     if (list->length == 5) {

        printf("cant add more item. list is full.\n");
        return;
    }
     char name[10];
     char unit[10];
    float amount;

    printf("Please enter a name: ");
    scanf("%s", &name);

    do
    {
        printf("Please enter amount: ");
        scanf("%f", &amount);
        /* code */
    } while (amount <= 0);
    printf("Please enter unit: ");
    scanf("%s", &unit);

    
    //create a new item struct 
    strcpy(list->itemList[list->length].productName,name);

    //amount as a parameter
    list->itemList[list->length].amount = amount;

   //copies unit to the unit field
    strcpy(list->itemList[list->length].unit,unit);

    ////to show that the list got a new item
    list->length++;
    
}

void printList(struct ShoppingList *list)
{
    //checking if the list is empty
    if ( list->length == 0)
{
    printf("list is empty\n");
}
    //going through all item in list and:
    for (int i = 0; i < list->length; i++){
        printf("%d,%s\t%.2f\t%s\n",
               i, //print the index
               list->itemList[i].productName,  //print the name
               list->itemList[i].amount,       //print amount
               list->itemList[i].unit);        //print unit
    }


}

//using a pointer to allow user change the amount of specific item in our shoppingList 
void editItem(struct ShoppingList *list)
{
    int index;
    float amount;
    
    do {
        printf("Please enter item index to change: ");  //we should know about the index of the item 
        scanf("%d", &index);
    } while (index < 0 || index > list->length - 1);  //cheking if the index is correct
    do {
        printf("Please enter new amount: ");   //modifying amout 
        scanf("%f", &amount);
    } while (amount <= 0);    //amount larger then o?
    
    list->itemList[index].amount = amount; //yes! do this

}

void removeItem(struct ShoppingList *list)
{
  int index = 0;
  printf("Please enter item index to remove: ");  //identify index
    scanf("%d", &index);

if (index < 0 || index >= list->length) { 
    printf("wrong index!\n");
    return;
}

for (int i = index + 1; i < list->length; i++) {  //if all requirment is correct do this:
    list->itemList[i - 1] = list->itemList[i];
}

list->length--;
}



void saveList(struct ShoppingList *list)
{
    //for upcomming lab

}


void loadList(struct ShoppingList* list)
{
	 //for upcomming lab
}
