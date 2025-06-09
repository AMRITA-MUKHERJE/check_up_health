#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define FILE_NAME "patient_data.txt"

typedef struct Patient {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char disease[MAX_NAME_LENGTH];
    struct Patient* next;
} Patient;

Patient* head = NULL;


void saveToFile() {
    FILE* file = fopen("patient_data.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    Patient* temp = head;
    while (temp != NULL) {
        fprintf(file, "%d %s %d %s\n", temp->id, temp->name, temp->age);
        temp = temp->next;
    }

    fclose(file);
    printf("Patient records saved to file successfully.\n");
}
Patient* createPatient(int id, char* name, int age) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->age = age;
    newPatient->next = NULL;
    return newPatient;
}

void addPatient(int id, char* name, int age) {
    Patient* newPatient = createPatient(id, name, age);
    newPatient->next = head;
    head = newPatient;
    saveToFile();
    printf("Patient added successfully.\n");

}

void viewPatients() {
    Patient* temp = head;
    if (temp == NULL) {
        printf("No patient records available.\n");
        return;
    }
    printf("ID\tName\t\tAge\t\n");
    printf("----------------------------------------\n");
    while (temp != NULL) {
        printf("%d\t%s\t\t%d\t\n", temp->id, temp->name, temp->age);
        temp = temp->next;
    }
}

void deletePatient(int id) {
    Patient* temp = head;
    Patient* prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Patient record deleted successfully.\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Patient record not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Patient record deleted successfully.\n");
}



void loadFromFile() {
    FILE* file = fopen("patient_data.txt","a");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    int id, age;
    char name[MAX_NAME_LENGTH], disease[MAX_NAME_LENGTH];
    while (fscanf(file, "%d %s %d %s", &id, name, &age, disease) != EOF) {
        addPatient(id, name, age);
    }

    fclose(file);
    printf("Patient records loaded from file successfully.\n");
}

int main() {
    int choice, id, age;
    char name[MAX_NAME_LENGTH], disease[MAX_NAME_LENGTH];

    FILE *file = fopen("patient_data.txt", "a");

   
    printf("\nHealthcare Management System\n");

    printf(" Patient Detalis\n");
        
    printf("Enter Patient ID: ");
    scanf("%d", &id);
    printf("Enter Patient Name: ");
    scanf("%s", name);
    printf("Enter Patient Age: ");
    scanf("%d", &age);
    addPatient(id, name, age);
    saveToFile();
    viewPatients();

    printf("Check your symptoms\n");
    printf("\n----------------------------------------\n");
    printf("1.Runny or stuffy nose\nSore throat\nCough\nCongestion\nSlight body aches or a mild headache\nSneezing\nLow-grade fever\nfevernFatigue (tiredness)\nFever or feeling feverish\n");
    printf("\n----------------------------------------\n");
   // printf("2.Influenza (Flu)");
    printf("2.Symptoms:\nFever or feeling feverish/chills\nCough\nSore throat\nRunny or stuffy nose\nMuscle or body aches\nHeadaches\nFatigue (tiredness)");
    printf("\n----------------------------------------\n");

   // printf("3.Allergies");
    printf("3.Sneezing\nItchy, watery eyes\nRunny or stuffy nose\nItchy throat or ears\nCoughing\nSinus pressure\nFatigue");
    printf("\n----------------------------------------\n");

   // printf("4.Diabetes (Type 1 and Type 2)");
    printf("4.Increased thirst\nFrequent urination\nExtreme hunger\nUnexplained weight loss\nPresence of ketones in the urine (ketones are a byproduct of the breakdown of muscle and fat that happens when there's not enough available insulin)\nFatigue\nBlurred vision\nSlow-healing sores\nFrequent infections, such as gum or skin infections and vaginal infections");
 
    do{
        printf("\n----------------------------------------\n");
        printf("\nEnter number of your symptom");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("You have COMMON COLD\n");
                printf("\nCure");
                printf("\nvitamin C, zinc supplements, and echinacea. A neti pot can help flush out mucus.");
                printf("\n To exit enter 6");
                break;
            case 2:
                printf("You have Influenza (Flu)");
                printf("\n To exit enter 6");
                break;
            case 3:
                printf("You have Allergies");
                printf("\n To exit enter 6");
                break;
            case 4:
                printf("You have Diabetes (Type 1 and Type 2)");
                printf("\n To exit enter 6");
                break;
            default: printf("\n exiting....\n");
        }


    }while(choice!=6);
}
