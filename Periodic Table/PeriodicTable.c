/*
*======================================================================
*
*       FILENAME: PeriodicTable.c
*
*
*
*       DESCRIPTION: This project allows the user to add any new element with its name, symbol
                    ,atomic number,atomic weight and also allows the user to view any element by
                    name,symbol,atomic number or weight.
*
*
*       VERSION: Code::Blocks 13.2
*
*       CREATED: 24/04/2018
*
*       COMPILER: gcc
*
*
*       AUTHOR: Mohammed Kadiri
*
*     ===========================================================
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

struct element
{
    char name[20];
    char symbol[10];
    int atomic_no;
    float atomic_mass;
    float electronegativity;
    float density;
    float melting_point;
    float boiling_point;
    float ioniztion_energy;
    int year_of_discovery;
    char inventor_surname[20];
}p;

//Function prototype to display the menu
void menu();
//Function prototype to add the menu
void add();
//Function prototype to explore the elements
void explore();
//Function to display an element structure
void display();

int main(int argc, char *argv[])
{
    menu();

    return 0;
}


void menu()
{
    char select;

    //Display options for the user to select
    printf("\t\t\t\tPeriodic Table");
    printf("\n\t\t\t*****************************");
    printf("\n\n\n\n\n\nSelect an option: \n\n");
    puts("1> Add new Element Information");
    puts("2> Explore");
    puts("3> Quit");
    scanf("%c",&select);

    //Select an option
    switch(select)
    {
        case '1': add();
                break;
        case '2': explore();
                break;
        case '3': printf("Goodbye\n");
                break;
        default:
            puts("Invalid input");
    }
}

void add()
{
    //Declare a file pointer
    FILE *fp;

    //Display and get each structure member from the user
    printf("\t\t\t\tPeriodic Table");
    printf("\n\t\t\t*****************************");
    printf("\n\n\n\n\n\nSelect an option: \n\n");
    puts("Add element name: ");
    scanf("%s",&p.name);
    puts("Add element symbol: ");
    scanf("%s",&p.symbol);
    puts("Add element atomic number: ");
    scanf("%d",&p.atomic_no);
    puts("Add element atomic mass: ");
    scanf("%f",&p.atomic_mass);
    puts("Add electronegativity value: ");
    scanf("%f",&p.electronegativity);
    puts("Add density: ");
    scanf("%f",&p.density);
    puts("Add melting point: ");
    scanf("%f",&p.melting_point);
    puts("Add boiling point: ");
    scanf("%f",&p.boiling_point);
    puts("Add ionization energy: ");
    scanf("%f",&p.ioniztion_energy);
    puts("Add year of discovery: ");
    scanf("%d",&p.year_of_discovery);
    puts("Add inventor surname: ");
    scanf("%s",&p.inventor_surname);

    //Open the binary file for appending and return null if failed to append
    if((fp = fopen("data.bin","a")) == NULL)
        puts("Error opening file");
    else
    {
        //Write to the binary file the structure and its members which were intialized by the user
        fwrite(&p,sizeof(p),1,fp);
        fclose(fp); //Close the file pointer
    }


}

//Function used to explore the structures based on their members
void explore()
{

    //Declare and intialize variables
    int option = 0;
    FILE *fp;
    char user_word[10];
    int user_number;
    float temp;

    //Open the binary file for reading
    if((fp=fopen("data.bin","rb")) ==  NULL)
        puts("Error opening file");
    else
    {
        puts("1> Search by name: ");
        puts("2> Search by symbol: ");
        puts("3> Search by atomic number: ");
        puts("4> Search by atomic weight: ");
        puts("5> Search by Electronegativity value: ");
        puts("6> Search by Density value: ");
        puts("7> Search by melting point: ");
        puts("8> Search by boiling point: ");
        puts("9> Search by ionization of energy: ");
        puts("10> Search by year of discovery: ");
        puts("11> Search by inventor surname: ");
        scanf("%d",&option);

        //The user selects an option and then based on their values their data is displayed
        switch(option)
        {

            case 1:
                    puts("Enter the name of the element to be searched: ");
                    scanf("%s",&user_word);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(strcmp(user_word,p.name) == 0)
                            display();
                        else
                            puts("Sorry this element cannot be found");
                    }
                    break;
            case 2:
                    puts("Enter the name of the symbol to be searched: ");
                    scanf("%s",&user_word);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(strcmp(user_word,p.symbol) == 0)
                         display();
                        else
                            puts("Sorry this element symbol can not be found");
                    }
                    break;
            case 3:
                    puts("Enter the atomic number to be searched: ");
                    scanf("%d",&user_number);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(user_number == p.atomic_no)
                         display();
                        else
                            puts("Sorry this element atomic number was not found");
                    }
                    break;
            case 4:
                    puts("Enter the atomic weight to be searched: ");
                    scanf("%f",&temp);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(temp == p.atomic_mass)
                         display();
                        else
                            puts("Sorry this atomic weight value cannot be found");
                    }
                    break;
            case 5:
                    puts("Enter the Electronegativity value to be searched: ");
                    scanf("%f",&temp);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(temp == p.electronegativity)
                         display();
                        else
                            puts("Sorry this electronegativity value cannot be found");
                    }
                    break;
            case 6:
                    puts("Enter the density value to be searched: ");
                    scanf("%f",&temp);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(temp == p.density)
                         display();
                        else
                            puts("Sorry this density value cannot be found");
                    }
                    break;
            case 7:
                    puts("Enter the melting point to be searched: ");
                    scanf("%f",&temp);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(temp == p.melting_point)
                         display();
                        else
                            puts("Sorry this melting point value cannot be found");
                    }
                    break;
            case 8:
                    puts("Enter the boiling point to be searched: ");
                    scanf("%f",&temp);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(temp == p.boiling_point)
                         display();
                        else
                            puts("Sorry this boiling point value cannot be found");
                    }
                    break;
            case 9:
                    puts("Enter the ionization value to be searched: ");
                    scanf("%f",&temp);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(temp == p.ioniztion_energy)
                         display();
                        else
                            puts("Sorry this ionization energy value cannot be found");
                    }
                    break;
            case 10:
                    puts("Enter the year of discovery to be searched: ");
                    scanf("%d",&user_number);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(user_number == p.year_of_discovery)
                         display();
                        else
                            puts("Sorry this year of discovery cannot be found");
                    }
                    break;
            case 11:
                    puts("Enter the surname of the inventor to be searched: ");
                    scanf("%s",&user_word);
                    while(fread(&p,sizeof(p),1,fp) == 1)
                    {
                        if(strcmp(user_word,p.inventor_surname) == 0)
                         display();
                        else
                            puts("Sorry this inventor surname cannnot be found");
                    }
                    break;
            default:
                puts("Invalid option");
        }
        fclose(fp); //Close the file pointer
    }

}

//Function used to display the values of a specific structure
void display()
{
       printf("\nName: %s\nSymbol: %s\nAtomic_no: %d\nAtomic_mass: %f\nElectronegativity: %f"
            "\nDensity: %f\nMelting Point: %f\nBoiling Point: %f\nIonization Energy: %f\nDiscovery: %d\nInventor: %s"
            ,p.name,p.symbol,p.atomic_no,p.atomic_mass,p.electronegativity,p.density,
            p.melting_point,p.boiling_point,p.ioniztion_energy,p.year_of_discovery,p.inventor_surname);
}

