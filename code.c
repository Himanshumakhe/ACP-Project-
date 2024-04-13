#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100
#define MAX_ASSETS 100
// Define structures for user and asset
typedef struct {
 int id;
 char username[50];
 char password[50];
} User;
typedef struct {
 int id;
 char name[50];
 char description[100];
 float value;
} Asset;
// Global arrays to store users and assets
User users[MAX_USERS];
Asset assets[MAX_ASSETS];
int numUsers = 0;
int numAssets = 0;
// Function prototypes
void addUser();
void addAsset();
void displayAssets();
void displayUsers();
int main() {
 int choice;
 do {
 printf("\nCyber Data Management System\n");
 printf("1. Add User\n");
 printf("2. Add Asset\n");
 printf("3. Display Users\n");
 printf("4. Display Assets\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch(choice) {
 case 1:
 addUser();
 break;
 case 2:
 addAsset();
 break;
 case 3:
 displayUsers();
 break;
 case 4:
 displayAssets();
 break;
 case 5:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice. Please enter a number between 1 and 5.\n");
 }
 } while(choice != 5);
 return 0;
}
void addUser() {
 if (numUsers >= MAX_USERS) {
 printf("User database full. Cannot add more users.\n");
 return;
 }
 User newUser;
 printf("Enter user ID: ");
 scanf("%d", &newUser.id);
 printf("Enter username: ");
 scanf("%s", newUser.username);
 printf("Enter password: ");
 scanf("%s", newUser.password);
 users[numUsers++] = newUser;
 printf("User added successfully.\n");
}
void addAsset() {
 if (numAssets >= MAX_ASSETS) {
 printf("Asset database full. Cannot add more assets.\n");
 return;
 }
 Asset newAsset;
 printf("Enter asset ID: ");
 scanf("%d", &newAsset.id);
 printf("Enter asset name: ");
 scanf("%s", newAsset.name);
 printf("Enter asset description: ");
 scanf("%s", newAsset.description);
 printf("Enter asset value: ");
 scanf("%f", &newAsset.value);
 assets[numAssets++] = newAsset;
 printf("Asset added successfully.\n");
}
void displayUsers() {
 printf("\nList of Users:\n");
 printf("ID\tUsername\tPassword\n");
 for (int i = 0; i < numUsers; i++) {
 printf("%d\t%s\t\t%s\n", users[i].id, users[i].username, users[i].password);
 }
}void displayAssets() {
 printf("\nList of Assets:\n");
 printf("ID\tName\tDescription\tValue\n");
 for (int i = 0; i < numAssets; i++) {
 printf("%d\t%s\t%s\t%.2f\n", assets[i].id, assets[i].name, assets[i].description,
assets[i].value);
 }
}
