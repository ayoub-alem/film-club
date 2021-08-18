#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>




/******************************************************************************************************************************/
/*************************************************  Colored Fucnction SET    ****************************************************/
/******************************************************************************************************************************/










/******************************************************************************************************************************/
/*************************************************  STRUCTURES INCLUDED    ****************************************************/
/******************************************************************************************************************************/




//Ces Chaines De Caracteres Utilise Lorsque J'offre Au Admin A Choisir La Categorie Ou Le Type Du Film
// jE lE Presente Avec Le Meme ordre Dans Le Tableau De Chaine Lorsque IL Choisit Par Exemple 3 Car Le 1er Indice Du Tableau Est 0
// Je scan 3 Sur Un Variable Et J'ai Mis Categories[s-1] je Soustracte De S Un 1 Pour Que Je Sois Dans La Correcte Reponse
// Meme Pour Les Types !!!


char categories [][15]= {"Enfant","Adulte","Adolescent","Familier"};
char types [][50]= {"Comedie","Drame","Horreur","Action","Western","Documentaire","Science Fiction","Policier","Anime","Romance"};


/******************************************************************************************************************************/
/*************************************************  STRUCTURES INCLUDED    ****************************************************/
/******************************************************************************************************************************/

//Structure Adherent Avec P Variable

struct adherent
{
    int id ;
    char name[50];
    char tele[20];
    char adresse[100];
    char audience [20];
    char Adate [50];

} A;

// Structure Filme Avec F Variable

struct filme
{
    int code;
    char titre[50];
    int quantity;
    char type [50];
    char audience [20];

} F;


// Structure prets Avec P Variable

struct prets
{
    int id;
    int code;
    char pdate [50];

} P;



/******************************************************************************************************************************/
/************************************************  USEF FILE    ***************************************************************/
/******************************************************************************************************************************/



FILE *fp=NULL,*fpf=NULL,*fpp=NULL, *fpt=NULL;







/******************************************************************************************************************************/
/***********************************  FONCTION Pour Affecter L'heure Et La Date    ********************************************/
/******************************************************************************************************************************/





void timer(char *ch)
{

    time_t t;
    time(&t);
    strcpy(ch,ctime(&t));

}







/******************************************************************************************************************************/
/**********************************************  WELCOME FUNCTION    **********************************************************/
/******************************************************************************************************************************/




void welcome()
{


    int i;
    // To Set The Dimensions Of The Console Automatically
    system("mode CON: COLS=105 LINES=40");
    char title[]=("WELCOME TO VIDEO CLUB MANAGER") ;



    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    printf("\n\n                          ");

    for(i=0; i<50; i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                          ||         ");

    for(i=0; i<strlen(title); i++)
    {
        printf("%c",title[i]);
        Sleep(20);
    }

    printf("        ||\n                          ");

    for(i=0; i<50; i++)
    {
        printf("*");
        Sleep(25);
    }
    SetConsoleTextAttribute(hConsole, 14);
    printf("\n\n");
    printf("                                   .--.                   .---.\n");
    printf("                               .---|__|           .-.     |~~~|\n");
    printf("                            .--|===|--|           |_|     |~~~|--.\n");
    printf("                            ||||===|  |       .---!~|  .--|   |--|\n");
    printf("                            ||||   |  |       |===| |--|  |   |  |\n");
    printf("                            | ||   |  |       |   | |__|  |   |  |\n");
    printf("                            | ||   |  |       |===| |==|  |   |  |\n");
    printf("                            |  |   |__|       |   |_|__|  |~~~|__|\n");
    printf("                            |--|===|--|       |===|~|--|  |~~~|--|\n");
    printf("                            `--^---'--'       `---^-^--^--^---'--'\n\n\n");



}






/******************************************************************************************************************************/
/************************************************  LOGIN FUNCTION    **********************************************************/
/******************************************************************************************************************************/







void login()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9





    int i=0;

    char ch,password[25];
    char username[10];
    char stitle[]=("LOGIN INTERFACE");
    char user[]=("aaaa");
    char pass[]=("sbca");



    printf("\n                           ");

    for(i=0; i<15; i++)
    {
        printf("\xB2");
        Sleep(20);
    }

    printf(" ");

    for(i=0; i<strlen(stitle); i++)
    {
        printf("%c",stitle[i]);
        Sleep(20);
    }

    printf(" ");
    for(i=0; i<15; i++)
    {
        printf("\xB2");
        Sleep(20);
    }

// Login Interface

    printf("\n\n");
    fflush(stdin);
    SetConsoleTextAttribute(hConsole, 14);
    printf("\n                    <1> \xB2\xB2 Enter Username  :  ");

    fflush(stdin); // To Clear The Buffer !!

    gets(username);

    fflush(stdin); //To Clear The Buffer !!

    printf("\n\n                    <2> \xB2\xB2 Enter Password  :  ");

    fflush(stdin);
    i=0;

    while(ch!=13)  // ASCI Of ENTER IS 13
    {

        ch=getch();

        if((ch!=13) && (ch!=8))  //ASCI Of SPACE IS 8
        {

            putch('*');

            password[i] = ch;

            i++;

        }

    }

    password[i] = '\0'; // The End Of String


    if((strcmp(username,user)==0) &&  (strcmp(password,pass)==0))
    {
        SetConsoleTextAttribute(hConsole, 10);
        printf("\n\n\n           \xB2\xB2 Login Successfully !!");
        Sleep(2000);
        printf("\n\n           \xB2\xB2 Loading ");
        for(i=0; i<5; i++)
        {
            Sleep(1000);
            printf(". ");
        }

    }

    else
    {
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n\n\n            \xB2\xB2 Login FaiLed !!");
        printf("\n\n\n            \xB2\xB2 Press any key to try again.....");
        getch();
        Sleep(500);
        system("cls");
        login();
    }
    printf("\n\n");

}



/*********************************** FIN














/******************************************************************************************************************************/
/*************************************************  MENU FUNCTION    **********************************************************/
/******************************************************************************************************************************/


void fmenue ()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9





    int i,choice;

    system("mode CON: COLS=135 LINES=30");

    system("cls");
    char ttitle[]=("WELCOME TO VIDEO CLUB MANAGER") ;
    printf("\n\n                                   ");

    for(i=0; i<50; i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                                   ||         ");

    for(i=0; i<strlen(ttitle); i++)
    {
        printf("%c",ttitle[i]);
        Sleep(20);
    }

    printf("        ||\n                                   ");

    for(i=0; i<50; i++)
    {
        printf("*");
        Sleep(25);
    }

    printf("\n\n");
    SetConsoleTextAttribute(hConsole, 14);
    printf("                                    -------------------------------------------------\n\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("                   >> Adherents <<        |       >> FILMS <<                   |           >> LOANS <<\n\n\n");
    SetConsoleTextAttribute(hConsole, 14);
    printf("          <1> Ajouter Un Adherent         |  <5> Ajouter Un Film                |  <9> Emprunter Un Film\n\n");
    printf("          <2> Modifier Un Adherent        |  <6> Modifier Un Film               |  <10> Rendre Un Film\n\n");
    printf("          <3> Supprimer Un Adherent       |  <7> Supprimer Un Film              |  <11> La Liste Des Emprunteurs \n\n");
    printf("          <4> Affichier La Liste Par O.A  |  <8> Afficher La Liste Par Catego.  |  <12> La Liste Des Films Empruntes\n\n");
    printf("                                          |                                     |  <13> La Liste Des Films Pretes Par Un Adherent \n\n");
    printf("                                    ................................................\n\n");
    printf("                                                    <0> Exit\n");
    SetConsoleTextAttribute(hConsole, 11);
    printf("\n                             Choose An Option: ");

    printf("\n                             <> Enter your Choice : --> ");
    SetConsoleTextAttribute(hConsole, 14);
    fflush(stdin);
    scanf("%d",&choice);
    system("cls");

    switch (choice)
    {
    case 1 :
        AjouterA(); // Ajouter Un Film
        break;

    case 2 :
        mdfa(); // Modifier Un Film
        break;

    case 3 :
        Adelete(); // Supprimer Un Film
        break;

    case 4 :
        Affichea(); // Afficher Un Film
        break;

    case 5 :
        AjouterF(); // Ajouter Un Film
        break;

    case 6 :
        mdff(); // Modifier Un Film
        break;


    case 7 :
        fdelete(); // Supprimer Un Film
        break;

    case 8 :
        Affichef(); // Afficher La Liste Des Films Par Categorie
        break;

    case 9 :
        emprfilm(); // Emprunter Un Film
        break;

    case 10:
        rndrfilm(); // Rendre Un Film
        break;

    case 11:
        AfficheE(); //Liste Des Emprunteurs
        break;

    case 12:
        AfficheEF();// Liste Des Films Empruntes
        break;

    case 13 :

        AfficheFP(); // Liste Des Films Pretes
        break;

    case 0:
        exitfunction();
        break;

    default:
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n\n\n\n\t                    <*> \xB2\xB2\xB2 Wrong Choice   ");
        printf("\n\n\t                    <*> \xB2\xB2\xB2 Try Again ");
        for(i=0; i<5; i++)
        {
            Sleep(500);
            printf(". ");
        }
        fmenue();
        break;
    }


}


/*********************************** FIN














/******************************************************************************************************************************/
/*******************************************  Ajouter Un Nouveau Membre    ****************************************************/
/******************************************************************************************************************************/





void AjouterA()   //Ajouter Adherent
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9







    int s,i;
    system("cls");

    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT CATEGORIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    SetConsoleTextAttribute(hConsole, 14);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Enfant");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Adulte");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Adolescent");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Back to main menu");
    gotoxy(20,15);
    SetConsoleTextAttribute(hConsole, 11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,17);
    printf("<*> Enter your choice : ");
    SetConsoleTextAttribute(hConsole, 14);
    fflush(stdin);
    scanf("%d",&s);
    if(s==4)
        fmenue() ;
    system("cls");
    if(getdata(s)==1)
    {
        strcpy(A.audience,categories[s-1]);
        fclose(fp);
        fp=fopen("adherents.txt","a");
        fseek(fp,0,SEEK_END);
        fwrite(&A,sizeof(A),1,fp);
        fclose(fp);
        gotoxy(20,21);
        SetConsoleTextAttribute(hConsole, 10);
        printf("\xDB\xDB\xDB\xDB\xB2 -L'Ajout Du Membre Est Reussi !!");
        gotoxy(20,23);
        printf("\xDB\xDB\xDB\xDB\xB2 -Ajouter Un Autre Membre ? (Y / N) : ");
        if((getch()=='n') || (getch()=='N'))
            fmenue();
        else
            system("cls");
        AjouterA();
    }

}



/*********************************** FIN











/******************************************************************************************************************************/
/***********************************************  GETDATA OD NEW MEMBER    ****************************************************/
/******************************************************************************************************************************/






int getdata(int s)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9





    system("cls");
    int t;
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 INSERT DETAILS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    SetConsoleTextAttribute(hConsole, 14);
    printf("\xDB\xDB\xDB\xDB\xB2 <1>. Categorie : ");
    puts(categories[s-1]);
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 <2>. ID Du Membre : ");
    fflush(stdin);
    scanf("%d",&t);

    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        fclose(fp);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\a<*> \xB2\xB2 Notamment : Ce ID Existe Deja !!\a");
        getch();

        fmenue();
        return 0;
    }
    fclose(fp);
    A.id = t ;

    gotoxy(20,11);
    fflush(stdin);
    printf("\xDB\xDB\xDB\xDB\xB2 <3>. Nom Et Prenom : ");
    gets(A.name);
    fflush(stdin);
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 <4>. Numero De Tele : ");
    gets(A.tele);
    fflush(stdin);
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 <5>. Adresse : ");
    gets(A.adresse);
    fflush(stdin);
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 <6>. Date D'inscription : ");
    timer(A.Adate);
    puts(A.Adate);
    fflush(stdin);
    gotoxy(20,19);
    SetConsoleTextAttribute(hConsole, 11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,23);


    gotoxy(20,25);

    return 1;
}


/*********************************** FIN














/******************************************************************************************************************************/
/***********************************  Check Wether The ID ExiSts Or Not    ****************************************************/
/******************************************************************************************************************************/



int checkid(int t)
{
    fp=fopen("adherents.txt","r");
    rewind(fp); // move pointer at the begining of file
    while(fread(&A,sizeof(A),1,fp))
        if(A.id == t)
            return 0;
    return 1;
}




/*********************************** FIN











/******************************************************************************************************************************/
/*******************************************    GO TO FUNCTION        *********************************************************/
/******************************************************************************************************************************/




COORD coord = {0, 0}; // sets coordinates to 0,0
//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}






/*********************************** FIN










/******************************************************************************************************************************/
/***************************************       Modifier Un Adherent       *****************************************************/
/******************************************************************************************************************************/



void mdfa()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9






    int c=0;
    int d,e,s;
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(20,5);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modifier Un Adherent \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 14);
        printf("\xB2\xB2\xB2\xB2\xB2 <1>. Entrer Le ID Du Membre Que Vous Voulez Le Modifier : ");
        fflush(stdin);
        scanf("%d",&d);


        fpp=fopen("prets.txt","r");
        while(fread(&P,sizeof(P),1,fpp)==1)
        {

            if(P.id==d)
            {
                fclose(fpp);
                gotoxy(20,9);
                SetConsoleTextAttribute(hConsole, 12);
                printf("\xB2\xB2\xB2\xB2\xB2 <->. Erreur : Le Membre Que Vous Voulez Le Modifier Existe Dans La Liste Des Emprunteurs !! ");
                gotoxy(20,11);
                printf("      <->. A Cause Des Regles De Protection Du Programme il est Impossible De Modifier Emprunteur !! ");
                SetConsoleTextAttribute(hConsole, 14);
                gotoxy(20,13);
                returnfmenue();
            }


        }












        if(checkid(d)==0) // check if the ID Exist
        {
            fclose(fp);
            fp=fopen("adherents.txt","r"); // Open File To Read The Content
            fpt=fopen("test.txt","w");

            while(fread(&A,sizeof(A),1,fp)==1) // While We Still Read The FILE We Check if d!=A.id
            {

                if(A.id != d)
                {
                    fseek(fpt,0,SEEK_CUR);
                    fwrite(&A,sizeof(A),1,fpt);
                }
            }

            fclose(fpt);
            fclose(fp);
            remove("adherents.txt");
            rename("test.txt","adherents.txt"); //copy all item from temporary file to fp


            system("cls");

            gotoxy(20,5);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT NeW CATEGORIE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,7);
            SetConsoleTextAttribute(hConsole, 14);
            printf("\xDB\xDB\xDB\xDB 1. Enfant");
            gotoxy(20,9);
            printf("\xDB\xDB\xDB\xDB 2. Adulte");
            gotoxy(20,11);
            printf("\xDB\xDB\xDB\xDB 3. Adolescent");
            gotoxy(20,13);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,17);
            printf("<-> Enter your choice : ");
            SetConsoleTextAttribute(hConsole, 14);
            fflush(stdin);
            scanf("%d",&s);
            strcpy(A.audience,categories[s-1]);

            // \xB2 Or \xDB Just a Design


            system("cls");
            int t;
            gotoxy(20,5);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 INSERT DETAILS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,7);
            SetConsoleTextAttribute(hConsole, 14);
            printf("\xDB\xDB\xDB\xDB\xB2 <1>. Nouveau Categorie : ");
            puts(categories[s-1]);
            gotoxy(20,9);
            A.id=d;
            printf("\xDB\xDB\xDB\xDB\xB2 <1>. Le ID Actuel : %d ",A.id); ;
            gotoxy(20,11);
            fflush(stdin);
            printf("\xDB\xDB\xDB\xDB\xB2 <3>. Nouveau Nom Et Prenom : ");
            gets(A.name);
            fflush(stdin);
            gotoxy(20,13);
            printf("\xDB\xDB\xDB\xDB\xB2 <4>. Nouveau Numero De Tele : ");
            gets(A.tele);
            fflush(stdin);
            gotoxy(20,15);
            printf("\xDB\xDB\xDB\xDB\xB2 <5>. Nouveau Adresse : ");
            gets(A.adresse);
            fflush(stdin);
            gotoxy(20,17);
            printf("\xDB\xDB\xDB\xDB\xB2 <6>. Nouveau Date D'inscription : ");
            timer(A.Adate);
            puts(A.Adate);
            fflush(stdin);
            gotoxy(20,19);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

            gotoxy(20,21);
            SetConsoleTextAttribute(hConsole, 10);
            printf("\xB2\xB2\xB2\xB2\xB2 <*>. La Modification Est Reussi !!");
            fp=fopen("adherents.txt","a");
            fseek(fp,0,SEEK_CUR);
            fwrite(&A,sizeof(A),1,fp); //write the new modification
            fclose(fp);
            c=1;

        }
        if(c==0) //If We Didn't Found The ID Included By The ADMIN
        {
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(20,9);
            printf("\xB2\xB2\xB2\xB2\xB2 <1>. Membre N'existe Pas !!");
            gotoxy(20,11);
            printf("           -- Vous Devez S'assurer De Ce ID !!");

        }

        gotoxy(20,23);
        SetConsoleTextAttribute(hConsole, 10);
        printf("\xB2\xB2\xB2\xB2\xB2 <*>. Modifier Un Autre Membre ? (Y/N) : "); // SUGGESTION OF THE SAME ACTION
        fflush(stdin);
        another=getch() ;
    }

    gotoxy(20,25);
    SetConsoleTextAttribute(hConsole, 14);
    returnfmenue(); //return to fmenue

}




/*********************************** FIN










/******************************************************************************************************************************/
/**************************       Return To FMENUE FuncTion      **************************************************************/
/******************************************************************************************************************************/




void returnfmenue(void)
{

    {
        printf(" ---->  Press ENTER To Return To Main Menu ...");
    }
a:
    if(getch()==13) //allow only use of enter
        fmenue();
    else
        goto a;
}





/*********************************** FIN









/******************************************************************************************************************************/
/**************************************       Supprimer Un Adherent          **************************************************/
/******************************************************************************************************************************/

void Adelete()  // MEMBER DELETE IT'S A FUNCTION THAT DELETE ITEMS FROM FILE FP
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9




    char another = 'y';
    system("cls");
    int findmember = 0;
    int d;

    while(another == 'y')
    {
        int findmember = 0;
        system("cls");
        gotoxy(20,5);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Supprimer Un Adherent \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 14);
        printf("\xB2\xB2\xB2\xB2\xB2 <1>. Entrer Le ID Du Membre Que Vous Voulez Le Supprimer : ");
        fflush(stdin);
        scanf("%d",&d);

        fpp=fopen("prets.txt","r");
        while(fread(&P,sizeof(P),1,fpp)==1)
        {

            if(P.id==d)
            {
                fclose(fpp);
                gotoxy(20,9);
                SetConsoleTextAttribute(hConsole, 12);
                printf("\xB2\xB2\xB2\xB2\xB2 <->. Erreur : Le Membre Que Vous Voulez Le Supprimer Existe Dans La Liste Des Emprunteurs !! ");
                gotoxy(20,11);
                printf("      <->. A Cause Des Regles De Protection Du Programme il est Impossible De Supprimer Un Emprunteur !! ");
                SetConsoleTextAttribute(hConsole, 14);
                gotoxy(20,13);
                returnfmenue();
            }


        }







        fp=fopen("adherents.txt","r");
        rewind(fp);
        while(fread(&A,sizeof(A),1,fp)==1)
        {
            if(A.id==d)
            {
                SetConsoleTextAttribute(hConsole, 14);
                gotoxy(20,9);
                printf("\xB2\xB2\xB2\xB2\xB2 <2>. Les Infos Du Membre au Quel Appartient Ce ID  : ");
                gotoxy(20,11);
                printf("\xB2\xB2\xB2\xB2\xB2 <3>. Le Nom Et Prenom : %s",A.name);
                gotoxy(20,13);
                printf("\xB2\xB2\xB2\xB2\xB2 <4>. La Categorie : %s",A.audience);
                gotoxy(20,15);
                printf("\xB2\xB2\xB2\xB2\xB2 <5>. Numero De Telephone : %s",A.tele);
                gotoxy(20,17);
                printf("\xB2\xB2\xB2\xB2\xB2 <6>. L'adresse : %s",A.adresse);
                gotoxy(20,19);
                printf("\xB2\xB2\xB2\xB2\xB2 <7>. Date D'inscription : %s",A.Adate);
                fflush(stdin);
                findmember=1;
                break;
            }
        }
        fclose(fp);
        if(findmember == 0)
        {
            gotoxy(20,9);
            SetConsoleTextAttribute(hConsole, 12);
            printf("\xB2\xB2\xB2\xB2\xB2 <2>. -- Membre N'existe Pas !!");
            gotoxy(20,11);
            printf("           -- Vous Devez S'assurer De Ce ID !!");
            gotoxy(20,14);
            returnfmenue();
        }
        else if(findmember==1 )
        {
            gotoxy(20,23);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2 <*>. Voulez Vous Vraiment Supprimer Ce Membre ? (Y/N) : ");
            SetConsoleTextAttribute(hConsole, 14);
            if(getch()=='y')
            {
                fp=fopen("adherents.txt","r");
                rewind(fp);
                fpt=fopen("test.txt","w");  //temporary file for delete

                while(fread(&A,sizeof(A),1,fp)==1)
                {
                    if(A.id!=d)
                    {
                        fseek(fpt,0,SEEK_CUR);
                        fwrite(&A,sizeof(A),1,fpt); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(fpt);
                fclose(fp);
                remove("adherents.txt");
                rename("test.txt","adherents.txt"); //copy all item from temporary file to fp
                if(findmember==1)
                {
                    system("cls");
                    gotoxy(20,7);
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("\xB2\xB2\xB2\xB2\xB2 <*>. Membre Est Supprime !!");
                    gotoxy(20,9);
                    Sleep(1000);
                    printf("\xB2\xB2\xB2\xB2\xB2 <*>. Voulez Vous Supprimer Un Autre Membre ? (Y/N) : ");
                    another = getch();

                }
            }
            else
            {
                system("cls");
                gotoxy(20,9);
                SetConsoleTextAttribute(hConsole, 12);
                printf("\xB2\xB2\xB2\xB2\xB2 <*>. La Suppression Est Annulee !!");
                gotoxy(20,13);
                SetConsoleTextAttribute(hConsole, 14);
                returnfmenue();
            }
            fflush(stdin);
            another=getch();

        }
    }
    gotoxy(10,15);
    fmenue();

}




/*********************************** FIN











/******************************************************************************************************************************/
/**************************************    Afficher Lexicographiquement    ****************************************************/
/******************************************************************************************************************************/


void Affichea()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9




    int i=0,j,k=0;
    char T[250][250],temp[50];

    fp=fopen("adherents.txt","r");
    rewind(fp);
    while(fread(&A,sizeof(A),1,fp))
    {
        strcpy(T[i],A.name);
        i++;
        k++;
    }
    fclose(fp);


    if(k==0)
    {
        system("cls");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\xB2\xB2\xB2\xB2\xB2 <->. La Liste Des Adherents Est Vide !!");
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(20,10);
        returnfmenue();


    }




    for (i = 0; i < k; i++)
    {

        for (j = i + 1; j < k; j++)
        {
            if (strcmp(T[i], T[j]) > 0)
            {
                strcpy(temp, T[i]);
                strcpy(T[i], T[j]);
                strcpy(T[j], temp);
            }
        }
    }
    char title[]=("La Liste Des Membres Par Ordre Alphabetique") ;


    printf("\n\n                          ");

    for(i=0; i<57; i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                          ||     ");

    for(i=0; i<strlen(title); i++)
    {
        printf("%c",title[i]);
        Sleep(20);
    }

    printf("     ||\n                          ");

    for(i=0; i<57; i++)
    {
        printf("*");
        Sleep(25);
    }



    printf("\n\n\n\t   **************************************************\n");

    printf("\t   ||         Nom Et Prenom                        ||\n");

    printf("\t   **************************************************\n");



    for (i = 0; i < k; i++)
    {
        SetConsoleTextAttribute(hConsole, 14);
        printf("\t   *    <%d> - %s .\n",i+1,T[i]);


    }

    SetConsoleTextAttribute(hConsole, 11);
    printf( "\t   **************************************************\n\n");

    SetConsoleTextAttribute(hConsole, 14);
    returnfmenue();


}




/****************************************************** FIN G.A ****************************************************************\









/******************************************************************************************************************************/
/****************************************  GESTION DES FILMS FUNCTIONS   ******************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/****************************************  GESTION DES FILMS FUNCTIONS   ******************************************************/
/******************************************************************************************************************************/
/****************************************  GESTION DES FILMS FUNCTIONS   ******************************************************/
/******************************************************************************************************************************/
/****************************************  GESTION DES FILMS FUNCTIONS   ******************************************************/
/******************************************************************************************************************************/









/******************************************************************************************************************************/
/************************************************  Ajouter Un FILM   **********************************************************/
/******************************************************************************************************************************/








AjouterF()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9






    int s,i,ty;
    system("cls");

    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Choix Du Categorie \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    SetConsoleTextAttribute(hConsole, 14);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Enfant");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Adulte");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Adolescent");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. FamiLier");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Back to main menu");
    gotoxy(20,17);
    SetConsoleTextAttribute(hConsole, 11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,21);
    printf("<-> Enter your choice : ");
    SetConsoleTextAttribute(hConsole, 14);
    fflush(stdin);
    scanf("%d",&s);

    if(s==5)
        fmenue() ;

    system("cls");
    gotoxy(20,5);
    SetConsoleTextAttribute(hConsole, 11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Choix Du Type De Film \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    SetConsoleTextAttribute(hConsole, 14);
    printf("\xB2\xB2 <1>. Comedie");
    gotoxy(35,7);
    printf("       \xB2\xB2 <2>. Drame");
    gotoxy(20,9);
    printf("\xB2\xB2 <3>. Horreur");
    gotoxy(35,9);
    printf("       \xB2\xB2 <4>. Action");
    gotoxy(20,11);
    printf("\xB2\xB2 <5>. Western");
    gotoxy(35,11);
    printf("       \xB2\xB2 <6>. Documentaire");
    gotoxy(20,13);
    printf("\xB2\xB2 <7>. Science.F");
    gotoxy(35,13);
    printf("       \xB2\xB2 <8>. Policier");
    gotoxy(20,15);
    printf("\xB2\xB2 <9>. Anime");
    gotoxy(35,15);
    printf("       \xB2\xB2 <10>. Romance");
    gotoxy(20,17);
    SetConsoleTextAttribute(hConsole, 11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,21);
    printf("<-> Enter your choice : ");
    SetConsoleTextAttribute(hConsole, 14);
    fflush(stdin);
    scanf("%d",&ty);


    if(filmdata(s,ty)==1)
    {
        strcpy(F.audience,categories[s-1]);
        strcpy(F.type,types[ty-1]);
        fclose(fpf);
        fpf=fopen("films.txt","a");
        fseek(fpf,0,SEEK_END);
        fwrite(&F,sizeof(F),1,fpf);
        fclose(fpf);
        gotoxy(20,20);
        SetConsoleTextAttribute(hConsole, 10);
        printf(">>*<< -- L'ajout Du Film Est Reussi !!");
        gotoxy(20,22);
        printf("    >>*<< -- Ajouter Un Autre Film ? (Y / N) : ");
        if((getch()=='n') || (getch()=='N'))
            fmenue();
        else
            system("cls");

        AjouterF();
    }


}



/*********************************** FIN




/******************************************************************************************************************************/
/******************************************  Ajouter Les Details D'Un FILM   **************************************************/
/******************************************************************************************************************************/





int filmdata(int s,int ty)
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9






    system("cls");
    int t;
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Inserer Les Details Du Film \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    SetConsoleTextAttribute(hConsole, 14);
    printf("\xDB\xDB\xDB\xDB\xB2 <1>. Categorie     : %s",categories[s-1]);
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 <2>. Type          : %s ",types[ty-1]);
    gotoxy(20,11);
    fflush(stdin);
    printf("\xDB\xDB\xDB\xDB\xB2 <3>. Code De Filme : ");
    fflush(stdin);
    scanf("%d",&t);

    if(checkcode(t) == 0)
    {
        gotoxy(21,15);
        fclose(fpf);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\a<*> \xB2\xB2 Notamment : Ce Code Existe Deja !!\a");
        getch();

        fmenue();
        return 0;
    }
    fclose(fpf);
    F.code = t ;

    gotoxy(20,13);
    fflush(stdin);
    printf("\xDB\xDB\xDB\xDB\xB2 <4>. Titre De FiLm : ");
    gets(F.titre);
    gotoxy(20,15);
    fflush(stdin);
    printf("\xDB\xDB\xDB\xDB\xB2 <5>. Quantity      : ");
    fflush(stdin);
    scanf("%d",&F.quantity);
    fflush(stdin);
    gotoxy(20,17);
    SetConsoleTextAttribute(hConsole, 11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");



    return 1;
}





/*********************************** FIN






/******************************************************************************************************************************/
/******************************************  Check Code De FILM   *************************************************************/
/******************************************************************************************************************************/



int checkcode(int t)
{
    fpf=fopen("films.txt","r");
    rewind(fpf); // move pointer at the begining of file
    while(fread(&F,sizeof(F),1,fpf))
        if(F.code == t)
            return 0;
    return 1;

}





/*********************************** FIN








/******************************************************************************************************************************/
/**************************************************  Modifier Un FILM   *******************************************************/
/******************************************************************************************************************************/




void mdff()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9








    char ch ;
    int ty,c=0;
    int d,e,s;
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(20,5);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modifier Un Film \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 14);
        printf("\xB2\xB2\xB2\xB2\xB2 <1>. Entrer Le Code Du Film Que Vous Voulez Le Modifier : ");
        fflush(stdin);
        scanf("%d",&d);

        fpp=fopen("prets.txt","r");
        while(fread(&P,sizeof(P),1,fpp)==1)
        {

            if(P.code==d)
            {
                fclose(fpp);
                gotoxy(20,9);
                SetConsoleTextAttribute(hConsole, 12);
                printf("\xB2\xB2\xB2\xB2\xB2 <->. Erreur : Le Film Que Vous Voulez Le Modifier Existe Dans La Liste Des Films Empruntes !! ");
                gotoxy(20,11);
                printf("      <->. A Cause Des Regles De Protection Du Programme il est Impossible De Ou Modifier Un Film Emprunte !! ");
                SetConsoleTextAttribute(hConsole, 14);
                gotoxy(20,13);
                returnfmenue();
            }


        }


        if(checkcode(d)==0)
        {
            fclose(fpf);
            fpf=fopen("films.txt","r"); // Open File To Read The Content
            fpt=fopen("test.txt","w");
            rewind(fpf);
            while(fread(&F,sizeof(F),1,fpf)==1) // While We Still Read The FILE We Check if d==A.id
            {
                if(d != F.code)
                {
                    fseek(fpt,0,SEEK_CUR);
                    fwrite(&F,sizeof(F),1,fpt);
                }
            }
            fclose(fpt);
            fclose(fpf);
            remove("films.txt");
            rename("test.txt","films.txt"); //copy all item from temporary file to fp

            system("cls");

            gotoxy(20,5);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT NeW CATEGORIE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,7);
            SetConsoleTextAttribute(hConsole, 14);
            printf("\xDB\xDB\xDB\xDB 1. Enfant");
            gotoxy(20,9);
            printf("\xDB\xDB\xDB\xDB 2. Adulte");
            gotoxy(20,11);
            printf("\xDB\xDB\xDB\xDB 3. Adolescent");
            gotoxy(20,13);
            printf("\xDB\xDB\xDB\xDB 4. Familier");
            gotoxy(20,15);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,17);
            printf("<-> Enter your choice : ");
            SetConsoleTextAttribute(hConsole, 14);
            fflush(stdin);
            scanf("%d",&s);
            strcpy(F.audience,categories[s-1]);

            // \xB2 Or \xDB Just a Design

            system("cls");
            gotoxy(20,5);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Choix De Type Du Film \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,7);
            SetConsoleTextAttribute(hConsole, 14);
            printf("\xB2\xB2 <1>. Comedie");
            gotoxy(35,7);
            printf("       \xB2\xB2 <2>. Drame");
            gotoxy(20,9);
            printf("\xB2\xB2 <3>. Horreur");
            gotoxy(35,9);
            printf("       \xB2\xB2 <4>. Action");
            gotoxy(20,11);
            printf("\xB2\xB2 <5>. Western");
            gotoxy(35,11);
            printf("       \xB2\xB2 <6>. Documentaire");
            gotoxy(20,13);
            printf("\xB2\xB2 <7>. Science.F");
            gotoxy(35,13);
            printf("       \xB2\xB2 <8>. Policier");
            gotoxy(20,15);
            printf("\xB2\xB2 <9>. Anime");
            gotoxy(35,15);
            printf("       \xB2\xB2 <10>. Romance");
            gotoxy(20,17);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,21);
            printf("<-> Enter your choice : ");
            SetConsoleTextAttribute(hConsole, 14);
            fflush(stdin);
            scanf("%d",&ty);
            fflush(stdin);
            strcpy(F.type,types[ty-1]);


            system("cls");
            int t;
            gotoxy(20,5);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Inserer Les Details Du Film \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,7);
            SetConsoleTextAttribute(hConsole, 14);
            printf("\xDB\xDB\xDB\xDB\xB2 <1>. Nouvelle Categorie : %s",categories[s-1]);
            gotoxy(20,9);
            printf("\xDB\xDB\xDB\xDB\xB2 <1>. Le Nouveau Type : %s",F.type);
            gotoxy(20,11);
            fflush(stdin);
            F.code=d;
            printf("\xDB\xDB\xDB\xDB\xB2 <3>. Le Code Actuel Du Film : %d",F.code);
            gotoxy(20,13);
            fflush(stdin);
            printf("\xDB\xDB\xDB\xDB\xB2 <4>. Nouveau Titre : ");
            gets(F.titre);
            fflush(stdin);
            gotoxy(20,15);
            printf("\xDB\xDB\xDB\xDB\xB2 <5>. Nouvelle Quantite : ");
            scanf("%d",&F.quantity);
            fflush(stdin);
            gotoxy(20,17);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

            gotoxy(20,21);
            SetConsoleTextAttribute(hConsole, 10);
            printf("\xDB\xDB\xDB\xDB\xB2 <*>. La Modification Du Film Es Reussi !!");
            fpf=fopen("films.txt","a");
            fseek(fpf,0,SEEK_CUR);
            fwrite(&F,sizeof(F),1,fpf);
            fclose(fpf);
            c=1;


        }
        fclose(fpf);

        if(c==0) //If We Didn't Found The ID Included By The ADMIN
        {
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(20,9);
            printf("\xB2\xB2\xB2\xB2\xB2 <1>. Notamment : Le Film N'existe Pas !!");
        }

        gotoxy(20,23);
        SetConsoleTextAttribute(hConsole, 10);
        printf("\xB2\xB2\xB2\xB2\xB2 <*>. Modifier Un Autre Film ? (Y/N) : "); // SUGGESTION OF THE SAME ACTION
        fflush(stdin);
        another=getch() ;
    }
    gotoxy(20,25);
    SetConsoleTextAttribute(hConsole, 14);
    returnfmenue(); //return to fmenue

}





/*********************************** FIN









/******************************************************************************************************************************/
/**************************************************  Supprimer Un FILM   ******************************************************/
/******************************************************************************************************************************/



void fdelete()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9





    char another = 'y';
    system("cls");
    int findfilm = 0;
    int d;

    while(another == 'y')
    {
        int findfilm = 0;
        system("cls");
        gotoxy(20,5);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Supprimer Un Film \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 14);
        printf("\xB2\xB2\xB2\xB2\xB2 <1>. Entrer Le Code Du Film Que Vous Voulez Le Supprimer : ");
        fflush(stdin);
        scanf("%d",&d);


        fpp=fopen("prets.txt","r");
        while(fread(&P,sizeof(P),1,fpp)==1)
        {

            if(P.code==d)
            {
                fclose(fpp);
                gotoxy(20,9);
                SetConsoleTextAttribute(hConsole, 12);
                printf("\xB2\xB2\xB2\xB2\xB2 <->. Erreur : Le Film Que Vous Voulez Le Supprimer Existe Dans La Liste Des Films Empruntes !! ");
                gotoxy(20,11);
                printf("      <->. A Cause Des Regles De Protection Du Programme il est Impossible De Supprimer Un Film Emprunte !! ");
                SetConsoleTextAttribute(hConsole, 14);
                gotoxy(20,13);
                returnfmenue();
            }


        }








        fpf=fopen("films.txt","r");
        rewind(fpf);
        while(fread(&F,sizeof(F),1,fpf)==1)
        {
            if(F.code==d)
            {
                SetConsoleTextAttribute(hConsole, 14);
                gotoxy(20,9);
                printf("\xB2\xB2\xB2\xB2\xB2 <2>. Les Infos Du Film au Quel Appartient Ce Code : %d",d);
                gotoxy(20,11);
                printf("\xB2\xB2\xB2\xB2\xB2 <3>. Le Titre  : %s",F.titre);
                gotoxy(20,13);
                printf("\xB2\xB2\xB2\xB2\xB2 <4>. La Categorie : %s",F.audience);
                gotoxy(20,15);
                printf("\xB2\xB2\xB2\xB2\xB2 <5>. Le Type : %s",F.type);
                gotoxy(20,17);
                printf("\xB2\xB2\xB2\xB2\xB2 <6>. La Quantite : %d",F.quantity);
                fflush(stdin);
                findfilm=1;
                break;
            }
        }
        fclose(fpf);
        if(findfilm == 0)
        {
            SetConsoleTextAttribute(hConsole, 10);
            gotoxy(20,9);
            printf("\xB2\xB2\xB2\xB2\xB2 <2>. -- Film N'existe Pas !!");
            gotoxy(20,11);
            printf("           -- Vous Devez S'assurer De Ce Code !!");
            gotoxy(20,14);
            SetConsoleTextAttribute(hConsole, 14);
            returnfmenue();
        }
        else if(findfilm==1 )
        {
            gotoxy(20,21);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2 <*>. Voulez Vraiment Supprimer Ce Film ? (Y/N) : ");
            if(getch()=='y')
            {
                fpf=fopen("films.txt","r");
                rewind(fpf);
                fpt=fopen("test.txt","w");  //temporary file for delete

                while(fread(&F,sizeof(F),1,fpf)==1)
                {
                    if(F.code!=d)
                    {
                        fseek(fpt,0,SEEK_CUR);
                        fwrite(&F,sizeof(F),1,fpt); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(fpt);
                fclose(fpf);
                remove("films.txt");
                rename("test.txt","films.txt"); //copy all item from temporary file to fp
                if(findfilm==1)
                {
                    system("cls");
                    gotoxy(20,7);
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("\xB2\xB2\xB2\xB2\xB2 <*>. Film Est Supprime !!");
                    gotoxy(20,9);
                    Sleep(1000);
                    printf("\xB2\xB2\xB2\xB2\xB2 <*>. Voulez Vous Supprimer Un Autre Film ? (Y/N) : ");
                    another = getch();

                }
            }
            else
            {
                system("cls");
                gotoxy(20,9);
                SetConsoleTextAttribute(hConsole, 12);
                printf("\xB2\xB2\xB2\xB2\xB2 <*>. La Suppression Est Annulee !!");
                gotoxy(20,13);
                SetConsoleTextAttribute(hConsole, 14);
                returnfmenue();
            }
            fflush(stdin);
            another=getch()
                    ;
        }
    }
    gotoxy(10,15);
    fmenue();



}








/*********************************** FIN







/******************************************************************************************************************************/
/**************************************************  AffICher Par Type De FILM   **********************************************/
/******************************************************************************************************************************/






void Affichef()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9





    int i=0,k=0;
    char T[250][250],A[250][250];

    fpf=fopen("films.txt","r");
    rewind(fpf);
    while(fread(&F,sizeof(F),1,fpf))
    {
        if(F.quantity > 0)
        {
            strcpy(T[i],F.titre);
            strcpy(A[i],F.type);
            i++;
            k++;
        }
    }
    fclose(fpf);


    if(k==0)
    {
        system("cls");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\xB2\xB2\xB2\xB2\xB2 <->. La Liste Des Films Est Vide !!");
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(20,10);
        returnfmenue();

    }




    char title[]=("Les Films Disponibles En Stock Par Type") ;


    printf("\n\n                          ");

    for(i=0; i<53; i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                          ||     ");

    for(i=0; i<strlen(title); i++)
    {
        printf("%c",title[i]);
        Sleep(20);
    }

    printf("     ||\n                          ");

    for(i=0; i<53; i++)
    {
        printf("*");
        Sleep(25);
    }



    printf("\n\n\n\t   ********************************************************************\n");

    printf("\t   ||         Titre                            Type                  ||\n");

    printf("\t   ********************************************************************\n");



    for (i = 0; i < k; i++)
    {
        SetConsoleTextAttribute(hConsole, 14);
        printf("\t   *  <%d> - %s                      %s\n",i+1,T[i],A[i]);

    }

    SetConsoleTextAttribute(hConsole, 11);
    printf( "\t   ********************************************************************\n\n");
    SetConsoleTextAttribute(hConsole, 14);
    returnfmenue();


}






/*********************************** FIN












/******************************************************************************************************************************/
/**************************************************  Gestion Des Emprunteurs   ************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/**************************************************  Gestion Des Emprunteurs   ************************************************/
/******************************************************************************************************************************/
/******************************************************************************************************************************/
/**************************************************  Gestion Des Emprunteurs   ************************************************/
/******************************************************************************************************************************/









/******************************************************************************************************************************/
/**************************************************  Emprunter Un Film   ******************************************************/
/******************************************************************************************************************************/











void emprfilm()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9




    char FAUD[50][50]; // Stock The Audience Of Filme
    char TY[50][50]; // Scan The Type Of The Film
    char T[50][50]; // Scan The Title Of The Filme
    char temp [20]; // Stock The Audience of Member
    int d; // Scan The ID Of Member Included By The User
    int i=0; // Indice Pour Le Tableau
    int k=7; // For Gotoxy Function
    int C[50]; // Stock The Code Of Specific Films
    int Q[50]; // Stock The Quantity Of Specific Filmes
    int j=0; // Conteur pour le Nombre D'apparence Des Members Dans Le Fichier Des Emprunteurs
    int s;
    int u=0;

    system("cls");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Emprunter Un Film \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    SetConsoleTextAttribute(hConsole, 14);
    printf("\xB2\xB2\xB2\xB2\xB2 <1>. Entrer Le ID Du Membre Qui Veut EmprunTer Un Film : ");
    fflush(stdin);
    scanf("%d",&d);
    if(checkid(d)==1)
    {
        fclose(fp) ;
        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(20,9);
        printf("\xB2\xB2\xB2\xB2\xB2 <2>. -- Membre N'existe Pas !!");
        gotoxy(20,11);
        printf("           -- Vous Devez S'assurer De Ce ID !!");
        gotoxy(20,14);
        SetConsoleTextAttribute(hConsole, 14);
        returnfmenue();

    }
    fclose(fp);

    P.id=d; // Affecter ID au P.ID   *1


    fp=fopen("adherents.txt","r");
    rewind(fp);
    while(fread(&A,sizeof(A),1,fp)==1)
    {
        if(d==A.id)
        {
            strcpy(temp,A.audience);
            break;
        }

    }
    fclose(fp);

    fpp=fopen("prets.txt","a");
    fclose(fpp);

    if(strcmp(temp,"Enfant")==0)
    {
        fpp=fopen("prets.txt","r");
        rewind(fpp);
        while(fread(&P,sizeof(P),1,fpp))
        {
            if(d==P.id)
            {
                fclose(fpp);
                system("cls");
                gotoxy(20,5);
                SetConsoleTextAttribute(hConsole, 11);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Atteindre Les Limites Du Categorie \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20,7);
                SetConsoleTextAttribute(hConsole, 12);
                printf("\xB2\xB2\xB2\xB2\xB2 <1>. Vous Avez Depasse Le Max Des Films Que Vous Pouvez Emprunter !! ");
                gotoxy(20,9);
                printf("\xB2\xB2\xB2\xB2\xB2 <2>. -- Pour Puissiez Emprunter Ce Film Vous Devez : ");
                gotoxy(20,11);
                printf("           -- Rendre Le Film Que Vous Avez Deja Empruntes !!");
                gotoxy(20,13);
                printf("           -- Notamment : Le Max Des Films A Emprunter Pour Categorie Enfant Est Fixe En : 1 film !!");
                gotoxy(20,16);
                SetConsoleTextAttribute(hConsole, 14);
                returnfmenue();

            }

        }
        fclose(fpp);
        system("cls");

        gotoxy(20,5);
        SetConsoleTextAttribute(hConsole, 11);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Choix Du Film a Emprunter \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        fpf=fopen("films.txt","r");
        rewind(fpf);
        SetConsoleTextAttribute(hConsole, 14);
        while(fread(&F,sizeof(F),1,fpf))
        {


            if(((strcmp(F.audience,"Enfant")==0) || (strcmp(F.audience,"Familier")==0)) && (F.quantity > 0))
            {
                u++;
                strcpy(FAUD[i],F.audience);
                strcpy(TY[i],F.type);
                strcpy(T[i],F.titre);
                Q[i]=F.quantity;
                C[i]=F.code;
                i++;
                gotoxy(20,k);
                printf("\xDB\xDB\xDB\xDB <%d>. %s",i,F.titre);

                k=k+2;

            }

        }

        fclose(fpf);

        if(u==0)
        {
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(20,k);
            printf("\xDB\xDB\xDB\xDB <->. Desole Il n y a Aucun Film En Stock Correspond Avec La Categorie Du Membre Saisi !!!");
            SetConsoleTextAttribute(hConsole, 14);
            gotoxy(20,k+3);
            returnfmenue();

        }

        gotoxy(20,k);
        SetConsoleTextAttribute(hConsole, 11);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        k=k+2;
        gotoxy(20,k);
        printf("<-> Enter your choice : ");
        SetConsoleTextAttribute(hConsole, 14);
        fflush(stdin);
        scanf("%d",&s);
        system("cls");


        P.code=C[s-1];// Affecter Le Code Du Film Au P.code *2
        P.id = d ;
        timer(P.pdate); // Affecter La Date De Prise Au P.pdate  *3

        fpp=fopen("prets.txt","a");
        fseek(fpp,0,SEEK_CUR);
        fwrite(&P,sizeof(P),1,fpp);
        fclose(fpp);

        P.id = d; // Affecter Le id du Member au File P.id *1
        P.code=C[s-1]; // Affecter Le Code Du Film Au P.code *2
        timer(P.pdate); // Affecter La Date De Prise Au P.pdate  *3
        Q[s-1]=Q[s-1]-1;

        system("cls");
        gotoxy(20,5);
        SetConsoleTextAttribute(hConsole, 10);
        printf("--------------------------------------------");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 14);
        printf("1- Le ID Du Membre : %d",P.id);
        gotoxy(20,9);
        printf("2- Le Code Du Film Emprunte : %d",P.code);
        gotoxy(20,11);
        printf("2- Le Date De Prise : %s",P.pdate);
        gotoxy(20,13);
        SetConsoleTextAttribute(hConsole, 10);
        printf("--------------------------------------------");
        gotoxy(20,15);
        printf("------> Le Film est Emprunte !!");



        fpf=fopen("films.txt","r");
        rewind(fpf);
        fpt=fopen("test.txt","w");  //temporary file for delete

        while(fread(&F,sizeof(F),1,fpf)==1)
        {
            if(F.code!= C[s-1])
            {
                fseek(fpt,0,SEEK_CUR);
                fwrite(&F,sizeof(F),1,fpt); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(fpt);
        fclose(fpf);
        remove("films.txt");
        rename("test.txt","films.txt");//copy all item from temporary file to fp

        strcpy(F.audience,FAUD[s-1]);
        strcpy(F.type,TY[s-1]);
        strcpy(F.titre,T[s-1]);
        F.quantity = Q[s-1];
        F.code = C[s-1];

        fpf=fopen("films.txt","a");
        fseek(fpt,0,SEEK_CUR);
        fwrite(&F,sizeof(F),1,fpf);
        fclose(fpf);
        gotoxy(20,17);
        SetConsoleTextAttribute(hConsole, 14);
        returnfmenue();



    }

    else if(strcmp(temp,"Adolescent")==0)
    {



        fpp=fopen("prets.txt","r");
        rewind(fpp);
        while(fread(&P,sizeof(P),1,fpp))
        {
            if(d==P.id)
            {
                j++;

            }

        }
        fclose(fpp);
        if(j == 2)
        {
            fclose(fpp);
            system("cls");
            gotoxy(20,5);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Atteindre Les Limites Du Categorie \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,7);
            SetConsoleTextAttribute(hConsole, 12);
            printf("\xB2\xB2\xB2\xB2\xB2 <1>. Vous Avez Depasser Le Max Des Films Que Vous Pouvez Empruntes !! ");
            gotoxy(20,9);
            printf("\xB2\xB2\xB2\xB2\xB2 <2>. -- Pour Que Vous Puissiez Emprunter Encore Un Film Vous Devez : ");
            gotoxy(20,11);
            printf("           -- Rendre Au Moins Un Des Films Que Vous Avez Deja Empruntes !!");
            gotoxy(20,13);
            printf("           -- Notamment : Le Max Des Films A Emprunter Pour Categorie Adolescent Est Fixe En : 2 films !!");
            gotoxy(20,16);
            SetConsoleTextAttribute(hConsole, 14);
            returnfmenue();
        }

        system("cls");

        gotoxy(20,5);
        SetConsoleTextAttribute(hConsole, 11);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Choix Du Film a Emprunter \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        fpf=fopen("films.txt","r");
        rewind(fpf);
        SetConsoleTextAttribute(hConsole, 14);
        while(fread(&F,sizeof(F),1,fpf))
        {


            if(((strcmp(F.audience,"Adolescent")==0) || (strcmp(F.audience,"Familier")==0)) && (F.quantity >= 1))
            {
                u++;
                strcpy(FAUD[i],F.audience);
                strcpy(TY[i],F.type);
                strcpy(T[i],F.titre);
                Q[i]=F.quantity;
                C[i]=F.code;
                i++;
                gotoxy(20,k);
                printf("\xDB\xDB\xDB\xDB <%d>. %s",i,F.titre);

                k=k+2;

            }

        }
        fclose(fpf);

        if(u==0)
        {
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(20,k);
            printf("\xDB\xDB\xDB\xDB <->. Desole Il n y a Aucun Film En Stock Correspond Avec La Categorie Du Membre Saisi !!!");
            SetConsoleTextAttribute(hConsole, 14);
            gotoxy(20,k+3);
            returnfmenue();

        }


        gotoxy(20,k);
        SetConsoleTextAttribute(hConsole, 11);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        k=k+2;
        gotoxy(20,k);
        printf("<-> Enter your choice : ");
        SetConsoleTextAttribute(hConsole, 14);
        fflush(stdin);
        scanf("%d",&s);
        system("cls");


        P.code=C[s-1];// Affecter Le Code Du Film Au P.code *2
        P.id = d ;
        timer(P.pdate); // Affecter La Date De Prise Au P.pdate  *3

        fpp=fopen("prets.txt","a");
        fseek(fpp,0,SEEK_CUR);
        fwrite(&P,sizeof(P),1,fpp);
        fclose(fpp);

        P.id = d ; // Affecter Le Id Du Membre Au P.id *1
        P.code=C[s-1]; // Affecter Le Code Du Film Au P.code *2
        timer(P.pdate); // Affecter La Date De Prise Au P.pdate  *3
        Q[s-1]=Q[s-1]-1;

        system("cls");
        gotoxy(20,5);
        SetConsoleTextAttribute(hConsole, 10);
        printf("--------------------------------------------");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 14);
        printf("1- Le ID Du Membre : %d",P.id);
        gotoxy(20,9);
        printf("2- Le Code Du Film Emprunte : %d",P.code);
        gotoxy(20,11);
        printf("2- Le Date De Prise : %s",P.pdate);
        gotoxy(20,13);
        SetConsoleTextAttribute(hConsole, 10);
        printf("--------------------------------------------");
        gotoxy(20,15);
        printf("------> Le Film est Emprunte !!");

        fpf=fopen("films.txt","r");
        rewind(fpf);
        fpt=fopen("test.txt","w");  //temporary file for delete

        while(fread(&F,sizeof(F),1,fpf)==1)
        {
            if(F.code!=C[s-1])
            {
                fseek(fpt,0,SEEK_CUR);
                fwrite(&F,sizeof(F),1,fpt); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(fpt);
        fclose(fpf);
        remove("films.txt");
        rename("test.txt","films.txt");//copy all item from temporary file to fp

        strcpy(F.audience,FAUD[s-1]);
        strcpy(F.type,TY[s-1]);
        strcpy(F.titre,T[s-1]);
        F.quantity = Q[s-1];
        F.code = C[s-1];

        fpf=fopen("films.txt","a");
        fseek(fpf,0,SEEK_CUR);
        fwrite(&F,sizeof(F),1,fpf);
        fclose(fpf);
        gotoxy(20,17);
        SetConsoleTextAttribute(hConsole, 14);
        returnfmenue();


    }

    else if(strcmp(temp,"Adulte")==0)
    {

        j=0;

        fpp=fopen("prets.txt","r");
        rewind(fpp);
        while(fread(&P,sizeof(P),1,fpp))
        {
            if(d==P.id)
            {
                j++;

            }

        }
        fclose(fpp);
        if(j == 3)
        {

            system("cls");
            gotoxy(20,5);
            SetConsoleTextAttribute(hConsole, 11);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Atteindre Les Limites Du Categorie \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,7);
            SetConsoleTextAttribute(hConsole, 12);
            printf("\xB2\xB2\xB2\xB2\xB2 <1>. Vous Avez Depasser Le Max Des Films Que Vous Pouvez Emprunter !! ");
            gotoxy(20,9);
            printf("\xB2\xB2\xB2\xB2\xB2 <2>. -- Pour Que Vous Puissiez Emprunter Encore Un Film Vous Devez : ");
            gotoxy(20,11);
            printf("           -- Rendre Au Moins un des Films Que Vous Avez Deja Emprunte !!");
            gotoxy(20,13);
            printf("           -- Notamment : Le Max Des Films A Emprunter Pour Categorie Adulte Est Fixe En : 3 films !!");
            gotoxy(20,16);
            SetConsoleTextAttribute(hConsole, 14);
            returnfmenue();


        }
        system("cls");

        gotoxy(20,5);
        SetConsoleTextAttribute(hConsole, 11);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Choix Du Film a Emprunter \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        fpf=fopen("films.txt","r");
        rewind(fpf);
        SetConsoleTextAttribute(hConsole, 14);
        while(fread(&F,sizeof(F),1,fpf))
        {


            if(((strcmp(F.audience,"Adulte")==0) || (strcmp(F.audience,"Familier")==0)) && (F.quantity >= 1))
            {

                u++;
                strcpy(FAUD[i],F.audience);
                strcpy(TY[i],F.type);
                strcpy(T[i],F.titre);
                Q[i]=F.quantity;
                C[i]=F.code;
                i++;
                gotoxy(20,k);
                printf("\xDB\xDB\xDB\xDB <%d>. %s",i,F.titre);

                k=k+2;

            }

        }

        fclose(fpf);

        if(u==0)
        {
            SetConsoleTextAttribute(hConsole, 12);
            gotoxy(20,k);
            printf("\xDB\xDB\xDB\xDB <->. Desole Il n y a Aucun Film En Stock Correspond Avec La Categorie Du Membre Saisi !!!");
            SetConsoleTextAttribute(hConsole, 14);
            gotoxy(20,k+3);
            returnfmenue();

        }


        gotoxy(20,k);
        SetConsoleTextAttribute(hConsole, 11);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        k=k+2;
        gotoxy(20,k);
        printf("<-> Enter your choice : ");
        SetConsoleTextAttribute(hConsole, 14);
        fflush(stdin);
        scanf("%d",&s);
        system("cls");


        P.code=C[s-1];// Affecter Le Code Du Film Au P.code *2
        P.id = d ;
        timer(P.pdate); // Affecter La Date De Prise Au P.pdate  *3

        fpp=fopen("prets.txt","a");
        fseek(fpp,0,SEEK_CUR);
        fwrite(&P,sizeof(P),1,fpp);
        fclose(fpp);

        Q[s-1]=Q[s-1]-1;
        P.code=C[s-1];// Affecter Le Code Du Film Au P.code *2
        P.id = d ;
        timer(P.pdate); // Affecter La Date De Prise Au P.pdate  *3
        system("cls");

        gotoxy(20,5);
        SetConsoleTextAttribute(hConsole, 10);
        printf("--------------------------------------------");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 14);
        printf("1- Le ID Du Membre : %d",P.id);
        gotoxy(20,9);
        printf("2- Le Code Du Film Emprunte : %d",P.code);
        gotoxy(20,11);
        printf("2- Le Date De Prise : %s",P.pdate);
        gotoxy(20,13);
        SetConsoleTextAttribute(hConsole, 10);
        printf("--------------------------------------------");
        gotoxy(20,15);
        printf("------> Le Film est Emprunte !!");



        fpf=fopen("films.txt","r");
        rewind(fpf);
        fpt=fopen("test.txt","w");  //temporary file for delete

        while(fread(&F,sizeof(F),1,fpf)==1)
        {
            if(F.code!=C[s-1])
            {
                fseek(fpt,0,SEEK_CUR);
                fwrite(&F,sizeof(F),1,fpt); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(fpt);
        fclose(fpf);
        remove("films.txt");
        rename("test.txt","films.txt");//copy all item from temporary file to fp

        strcpy(F.audience,FAUD[s-1]);
        strcpy(F.type,TY[s-1]);
        strcpy(F.titre,T[s-1]);
        F.quantity = Q[s-1];
        F.code = C[s-1];

        fpf=fopen("films.txt","a");
        fseek(fpf,0,SEEK_CUR);
        fwrite(&F,sizeof(F),1,fpf);
        fclose(fpf);




        gotoxy(20,17);
        SetConsoleTextAttribute(hConsole, 14);
        returnfmenue();

    }


}






/*********************************** FIN










/******************************************************************************************************************************/
/**************************************************  Rendre Un Film   *********************************************************/
/******************************************************************************************************************************/







void rndrfilm()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9


    int z=0;
    char FAUD[50][50]; // Stock The Audience Of Film
    char TY[50][50]; // Scan The Type Of The Film
    char T[50][50]; // Scan The Title Of The Film
    char temp [20];// Stock The Audience of Member
    int d; // Scan The ID Of Member Included By The User
    int c; // Scan The Code Of Film Included By The User
    int i=0; // Indice Pour Le Tableau
    int k=7; // For Gotoxy Function
    int C[50]; // Stock The Code Of Specific Films
    int Q[50]; // Stock The Quantity Of Specific Films
    int j=0; // Conteur pour le Nombre D'apparence Des Members Dans Le Fichier Des Emprunteurs
    int s;
    int u=0; // Pour Camculer le nombre de meme film emprunter pour un membre et supprimer un seul



    system("cls");
    gotoxy(20,5);
    SetConsoleTextAttribute(hConsole, 11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Rendre Un Film \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    SetConsoleTextAttribute(hConsole, 14);
    printf("\xB2\xB2\xB2\xB2\xB2 <1>. Entrer Le ID Du Membre Qui Veut Rendre le Film : ");
    fflush(stdin);
    scanf("%d",&d);
    if(checkip(d)==1)
    {
        fclose(fpp) ;
        gotoxy(20,9);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\xB2\xB2\xB2\xB2\xB2 <2>. -- Membre N'existe Pas Dans La Liste Des Emprunteurs!!");
        gotoxy(20,11);
        printf("           -- Vous Devez S'assurer De Ce ID !!");
        gotoxy(20,14);
        SetConsoleTextAttribute(hConsole, 14);
        returnfmenue();

    }
    fclose(fpp);
    gotoxy(20,9);
    printf("\xB2\xB2\xB2\xB2\xB2 <1>. Entrer Le Code Du Film Rendu : ");
    fflush(stdin);
    scanf("%d",&c);

    fpp=fopen("prets.txt","r");
    while(fread(&P,sizeof(P),1,fpp)==1)
    {

        if((P.code==c) && (P.id==d))
        {
            z=1;
            break;
        }


    }
    fclose(fpp);
    if(z==0)
    {

        gotoxy(20,11);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\xB2\xB2\xB2\xB2\xB2 <2>. -- Film N'existe Pas Ou Le Membre Que Vous Avez Saisi N'a Pas Pri Le Film Saisi !!");
        gotoxy(20,13);
        printf("           -- Vous Devez S'assurer Du Code De Film Ou Si Le Membre A Le Pris !!");
        gotoxy(20,16);
        SetConsoleTextAttribute(hConsole, 14);
        returnfmenue();

    }



    // Remove The Borrower From The Borrowers FiLe
    u=0;
    fpt=fopen("test.txt","w");
    fpp=fopen("prets.txt","r");
    rewind(fpp);
    while(fread(&P,sizeof(P),1,fpp)==1)
    {
        if(u==0)
        {

            if((P.id == d) && (P.code == c))
            {
                u++;
                continue;

            }
            else
            {
                fseek(fpt,0,SEEK_CUR);
                fwrite(&P,sizeof(P),1,fpt) ;
            }


        }
        else
        {
            fseek(fpt,0,SEEK_CUR);
            fwrite(&P,sizeof(P),1,fpt) ;
        }

    }
    fclose(fpp);
    fclose(fpt);
    remove("prets.txt");
    rename("test.txt","prets.txt");


    // Store The Details Of The Film Before Modify IT Means Before Increase Its Quantity


    fpf=fopen("films.txt","r");
    rewind(fpf);
    while(fread(&F,sizeof(F),1,fpf)==1)
    {

        if(F.code == c)
        {
            strcpy(FAUD[i],F.audience);
            strcpy(TY[i],F.type);
            strcpy(T[i],F.titre);
            Q[i] = F.quantity ;
            C[i] = F.code ;
            break;

        }


    }

    fclose(fpf);


    // Increade The Quantity By One

    Q[i] = Q[i] + 1 ;

    // Delete The Film From films FILE


    fpf=fopen("films.txt","r");
    fpt=fopen("test.txt","w");

    while(fread(&F,sizeof(F),1,fpf)==1)
    {

        if(F.code != c)
        {
            fseek(fpt,0,SEEK_CUR);
            fwrite(&F,sizeof(F),1,fpt);

        }


    }
    fclose(fpf);
    fclose(fpt);
    remove("films.txt");
    rename("test.txt","films.txt");

    //Write The Film With New Details That Are Stored In The Previous Variables

    strcpy(F.audience,FAUD[i]);
    strcpy(F.type,TY[i]);
    strcpy(F.titre,T[i]);
    F.quantity = Q[i];
    F.code = c;


    fpf=fopen("films.txt","a");
    fseek(fpf,0,SEEK_CUR);

    fwrite(&F,sizeof(F),1,fpf);
    fclose(fpf);


    // Print Le Fil est rendu
    P.id = d ;
    P.code = c ;
    timer(P.pdate);
    system("cls");
    gotoxy(20,5);
    SetConsoleTextAttribute(hConsole, 10);
    printf("--------------------------------------------");
    gotoxy(20,7);
    SetConsoleTextAttribute(hConsole, 14);
    printf("1- Le ID Du Membre : %d",P.id);
    gotoxy(20,9);
    printf("2- Le Code Du Film Emprunte : %d",P.code);
    gotoxy(20,11);
    printf("2- Le Date De Retour : %s",P.pdate);
    gotoxy(20,13);
    SetConsoleTextAttribute(hConsole, 10);
    printf("--------------------------------------------");
    gotoxy(20,15);
    printf("------> Le Film est Rendu !!");
    gotoxy(20,17);
    SetConsoleTextAttribute(hConsole, 14);
    returnfmenue();








}






/*********************************** FIN








/******************************************************************************************************************************/
/**************************************************  Check In Prets FILE  *********************************************************/
/******************************************************************************************************************************/










int checkip(int t)
{

    fpp=fopen("prets.txt","r");
    rewind(fpp); // move pointer at the begining of file
    while(fread(&P,sizeof(P),1,fpp))
        if(P.id == t)
            return 0;
    return 1;


}






int checkcp(int t)
{

    fpp=fopen("prets.txt","r");
    rewind(fpp); // move pointer at the begining of file
    while(fread(&P,sizeof(P),1,fpp))
        if(P.code == t)
            return 0;
    return 1;


}








/*********************************** FIN







/******************************************************************************************************************************/
/**************************************************  Liste Des Films Empruntes ************************************************/
/******************************************************************************************************************************/










void AfficheEF()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9








    int i=0,l,z=0,j=0,k=0;
    int C[50];
    char T[250][250];

    fpp=fopen("prets.txt","r");
    rewind(fpp);
    while(fread(&P,sizeof(P),1,fpp))
    {
        C[i]=P.code;
        i++;
        k++;
    }
    fclose(fpp);


    if(k==0)
    {
        system("cls");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\xB2\xB2\xB2\xB2\xB2 <->. La Liste Des Films Empruntes Est Vide !!");
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(20,10);
        returnfmenue();



    }




    fpf=fopen("films.txt","r");
    rewind(fpf);
    while(fread(&F,sizeof(F),1,fpf)==1)
    {
        for(i=0; i<k; i++)
        {
            if(F.code == C[i])
            {
                strcpy(T[z],F.titre);
                z++;
                break; // We Need Just To Know If Exist So When We Reach It We Break The For Loop
            }
        }
    }

    fclose(fpf);


    for(i=0; i<z; i++)
    {
        for(j=i; j<z-1; j++)
        {
            if(strcmp(T[i],T[j+1])==0)
            {
                for(l=i; l<z-1; l++)
                {
                    strcpy(T[l],T[l+1]);
                }
                z--;
                j--;
            }


        }

    }



    char title[]=("La Liste Des Films Empruntes") ;


    printf("\n\n                          ");

    for(i=0; i<58; i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                          ||             ");

    for(i=0; i<strlen(title); i++)
    {
        printf("%c",title[i]);
        Sleep(20);
    }

    printf("             ||\n                          ");

    for(i=0; i<58; i++)
    {
        printf("*");
        Sleep(25);
    }



    printf("\n\n\n\t   **************************************************\n");

    printf("\t   ||         Titre                                ||\n");

    printf("\t   **************************************************\n");

    SetConsoleTextAttribute(hConsole, 14);

    for (i = 0; i < z; i++)
    {
        printf("\t   *    <%d> - %s .\n",i+1,T[i]);


    }
    SetConsoleTextAttribute(hConsole, 11);

    printf( "\t   **************************************************\n\n");
    SetConsoleTextAttribute(hConsole, 14);
    returnfmenue();





}








/*********************************** FIN










/******************************************************************************************************************************/
/*****************************************  Films Empruntes Par Adherent  *****************************************************/
/******************************************************************************************************************************/








void AfficheFP()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9


    SetConsoleTextAttribute(hConsole, 11);


    int i=0,d,l,z=0,j=0,k=0;
    int C[50];
    char T[250][250];
    char Mr[50];

    system("cls");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Les Films Emprunter Par Membre \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    SetConsoleTextAttribute(hConsole, 14);
    printf("\xB2\xB2\xB2\xB2\xB2 <1>. Entrer Le ID Du Membre Pour Voir Les Films Qu'il a Emprunte : ");
    fflush(stdin);
    scanf("%d",&d);
    if(checkid(d)==1)
    {
        fclose(fp);
        SetConsoleTextAttribute(hConsole, 12);
        gotoxy(20,9);
        printf("\xB2\xB2\xB2\xB2\xB2 <*>. ERREUR : Ce ID N'existe Pas Dans La Liste Des Adherents !! ");
        gotoxy(20,12);
        SetConsoleTextAttribute(hConsole, 14);
        returnfmenue();

    }
    fclose(fp);
    if(checkip(d)==1)
    {
        fclose(fpp);
        gotoxy(20,9);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\xB2\xB2\xB2\xB2\xB2 <*>. ERREUR : Ce ID N'existe Pas Dans La Liste Des Emprunteurs !! ");
        gotoxy(20,12);
        SetConsoleTextAttribute(hConsole, 14);
        returnfmenue();

    }
    fclose(fpp);


    fpp=fopen("prets.txt","r");
    rewind(fpp);
    while(fread(&P,sizeof(P),1,fpp))
    {
        if(P.id==d)
        {
            C[i]=P.code;
            i++;
            k++;
        }

    }
    fclose(fpp);

    fp=fopen("adherents.txt","r");
    rewind(fp);
    while(fread(&A,sizeof(A),1,fp))
    {
        if(A.id == d)
        {
            strcpy(Mr,A.name);
            break;
        }

    }
    fclose(fp);


    fpf=fopen("films.txt","r");
    rewind(fpf);
    while(fread(&F,sizeof(F),1,fpf)==1)
    {
        for(i=0; i<k; i++)
        {
            if(F.code == C[i])
            {
                strcpy(T[z],F.titre);

                z++;
            }
        }
    }

    fclose(fpf);


    system("cls");


    char title[]=("La Liste Des Films Empruntes Par") ;

    SetConsoleTextAttribute(hConsole, 11);
    printf("\n\n                          ");

    for(i=0; i<55+strlen(Mr); i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                          ||          ");

    for(i=0; i<strlen(title); i++)
    {
        printf("%c",title[i]);
        Sleep(20);
    }
    printf(" %s",Mr);

    printf("        ||\n                          ");

    for(i=0; i<55+strlen(Mr); i++)
    {
        printf("*");
        Sleep(25);
    }

    SetConsoleTextAttribute(hConsole, 11);

    printf("\n\n\n\t   **************************************************\n");

    printf("\t   ||         Titre                                ||\n");

    printf("\t   **************************************************\n");


    SetConsoleTextAttribute(hConsole, 14);
    for (i = 0; i < z; i++)
    {
        printf("\t   *    <%d> - %s .\n",i+1,T[i]);


    }

    SetConsoleTextAttribute(hConsole, 11);
    printf( "\t   **************************************************\n\n");
    SetConsoleTextAttribute(hConsole, 14);
    returnfmenue();




}








/*********************************** FIN














/******************************************************************************************************************************/
/**************************************************  Les Emprunteurs Des Films  ***********************************************/
/******************************************************************************************************************************/







void AfficheE()
{



    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    //Colored Text Function Li Lfu9





    int i=0,l,z=0,j=0,k=0;
    int D[50];
    char T[250][250];

    fpp=fopen("prets.txt","r");
    rewind(fpp);
    while(fread(&P,sizeof(P),1,fpp))
    {
        D[i]=P.id;
        i++;
        k++;
    }
    fclose(fpp);


    if(k==0)
    {
        system("cls");
        gotoxy(20,7);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\xB2\xB2\xB2\xB2\xB2 <->. La Liste Des Emprunteurs Des Films Est Vide !!");
        SetConsoleTextAttribute(hConsole, 14);
        gotoxy(20,10);
        returnfmenue();

    }






    fp=fopen("adherents.txt","r");
    rewind(fp);
    while(fread(&A,sizeof(A),1,fp)==1)
    {
        for(i=0; i<k; i++)
        {
            if(A.id == D[i])
            {
                strcpy(T[z],A.name);
                z++;
                break;
            }
        }
    }

    fclose(fp);


    for(i=0; i<z; i++)
    {
        for(j=i; j<z-1; j++)
        {
            if(strcmp(T[i],T[j+1])==0)
            {
                for(l=i; l<z-1; l++)
                {
                    strcpy(T[l],T[l+1]);
                }
                z--;
                j--;
            }


        }

    }


    char title[]=("La Liste Des Emprunteurs Des Films") ;


    printf("\n\n                          ");
    SetConsoleTextAttribute(hConsole, 11);
    for(i=0; i<57; i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                          ||         ");

    for(i=0; i<strlen(title); i++)
    {
        printf("%c",title[i]);
        Sleep(20);
    }

    printf("          ||\n                          ");

    for(i=0; i<57; i++)
    {
        printf("*");
        Sleep(25);
    }



    printf("\n\n\n\t   **************************************************\n");

    printf("\t   ||         Titre                                ||\n");

    printf("\t   **************************************************\n");

    SetConsoleTextAttribute(hConsole, 14);

    for (i = 0; i < z; i++)
    {
        printf("\t   *    <%d> - %s .\n",i+1,T[i]);


    }
    SetConsoleTextAttribute(hConsole, 11);

    printf( "\t   **************************************************\n\n");
    SetConsoleTextAttribute(hConsole, 14);
    returnfmenue();





}









/*********************************** FIN **************************/








/******************************************************************************************************************************/
/**************************************************  EXIT FUNCTION  ***********************************************************/
/******************************************************************************************************************************/


void exitfunction()
{

    int i;


// To Set The Dimensions Of The Console Automatically
    system("mode CON: COLS=105 LINES=40");
    char title[]=("EXIT THE VIDEO CLUB MANAGER") ;



    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    printf("\n\n                          ");

    for(i=0; i<50; i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                          ||         ");

    for(i=0; i<strlen(title); i++)
    {
        printf("%c",title[i]);
        Sleep(20);
    }

    printf("          ||\n                          ");

    for(i=0; i<50; i++)
    {
        printf("*");
        Sleep(25);
    }
    SetConsoleTextAttribute(hConsole, 14);


    printf("\n\n");
    printf("                                   .--.                   .---.\n");
    printf("                               .---|__|           .-.     |~~~|\n");
    printf("                            .--|===|--|           |_|     |~~~|--.\n");
    printf("                            ||||===|  |       .---!~|  .--|   |--|\n");
    printf("                            ||||   |  |       |===| |--|  |   |  |\n");
    printf("                            | ||   |  |       |   | |__|  |   |  |\n");
    printf("                            | ||   |  |       |===| |==|  |   |  |\n");
    printf("                            |  |   |__|       |   |_|__|  |~~~|__|\n");
    printf("                            |--|===|--|       |===|~|--|  |~~~|--|\n");
    printf("                            `--^---'--'       `---^-^--^--^---'--'\n\n");
    printf("                         -------------------------------------------------\n\n");
    printf("                                >> Grand MerCi a Notre Equipe <<       \n\n\n");
    printf("                         <1> Ayoub Alem\n\n");
    printf("                         <2> Abdelilah EL Allouli               \n\n");
    printf("                         <3> Soukaina Benkirane             \n\n");
    printf("                         <4> Chaimae Aachir               \n\n");
    printf("                         -------------------------------------------------   \n\n");
    Sleep(4000);
    exit(0);

}



/******************************************************************************************************************************/
/**************************************************  Start FUNCTION  ***********************************************************/
/******************************************************************************************************************************/









void startfunction()
{

    int i;


// To Set The Dimensions Of The Console Automatically
    system("mode CON: COLS=105 LINES=40");
    char title[]=("Welcome To THE VIDEO CLUB MANAGER") ;



    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 11);

    printf("\n\n                          ");

    for(i=0; i<50; i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                          ||         ");

    for(i=0; i<strlen(title); i++)
    {
        printf("%c",title[i]);
        Sleep(20);
    }

    printf("    ||\n                          ");

    for(i=0; i<50; i++)
    {
        printf("*");
        Sleep(25);
    }
    SetConsoleTextAttribute(hConsole, 14);


    printf("\n\n");
    printf("                                   .--.                   .---.\n");
    printf("                               .---|__|           .-.     |~~~|\n");
    printf("                            .--|===|--|           |_|     |~~~|--.\n");
    printf("                            ||||===|  |       .---!~|  .--|   |--|\n");
    printf("                            ||||   |  |       |===| |--|  |   |  |\n");
    printf("                            | ||   |  |       |   | |__|  |   |  |\n");
    printf("                            | ||   |  |       |===| |==|  |   |  |\n");
    printf("                            |  |   |__|       |   |_|__|  |~~~|__|\n");
    printf("                            |--|===|--|       |===|~|--|  |~~~|--|\n");
    printf("                            `--^---'--'       `---^-^--^--^---'--'\n\n");
    printf("                         -------------------------------------------------\n\n");
    printf("                                >> Grand MerCi a Notre Equipe <<       \n\n\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("                         <1> Ayoub Alem\n\n");
    printf("                         <2> Abdelilah EL Allouli               \n\n");
    printf("                         <3> Soukaina Benkirane             \n\n");
    printf("                         <4> Chaimae Aachir               \n\n");
    SetConsoleTextAttribute(hConsole, 14);
    printf("                         -------------------------------------------------   \n\n");
    printf("                         --> Enter Any Key To Continue ...   \n\n");
    getch();


}






/******************************************************************************************************************************/
/**************************************************  Rules FUNCTION  ***********************************************************/
/******************************************************************************************************************************/










void rulesfunction()
{

    int i;


// To Set The Dimensions Of The Console Automatically
    system("mode CON: COLS=115 LINES=40");
    char title[]=("Principe Du Programme Et Ses Regles") ;



    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 12);

    printf("\n\n                             ");

    for(i=0; i<48; i++)
    {
        printf("*");
        Sleep(20);
    }

    printf("\n                             ||    ");

    for(i=0; i<strlen(title); i++)
    {
        printf("%c",title[i]);
        Sleep(20);
    }

    printf("     ||\n                             ");

    for(i=0; i<48; i++)
    {
        printf("*");
        Sleep(25);
    }
    SetConsoleTextAttribute(hConsole, 14);


    printf("\n\n");
    SetConsoleTextAttribute(hConsole, 11);
    printf("      --------------------------------------------------------------------------------------------------\n\n");
    SetConsoleTextAttribute(hConsole, 14);
    printf("     Le programme permet  la gestion d’un video club tout en utilisant la base des fichiers , structures , \n");
    printf("     chaines de caractere ... \n\n");

    printf("   - Le menu apres avoir y acceder (entrer le nom d utilisateur et le mot de passe exacte) , presente des \n");
    printf("     divers suggestions a l utilisateur : \n\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("           <1> gestion des adherents/films : ajout/modification/suppression/affichage d un adherent / film. \n\n");
    printf("           <2> gestion des emprunts : Emprunter/rendre : un film , afficher la liste des : films empruntes \n");
    printf("               emprunteurs de films / films pretes par un adherent.\n\n");
    SetConsoleTextAttribute(hConsole, 14);
    printf("   -Le programme est gere selon des regles a respecter : \n\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("           <4> Enfant  a droit d un film / *Adolescent de deux films / *Adulte de  trois films.\n\n");
    printf("           <5> Un adherent ne peut prendre que un film adapte a sa categorie.\n\n");
    printf("           <6> Les prets dependent de la disponibilite des films.\n\n");
    printf("           <7> Un Adherent/Film Ne Peut Pas etre Modifier/Supprimer S il existe Dans La Liste Des Prets.\n\n");
    SetConsoleTextAttribute(hConsole, 11);
    printf("      ---------------------------------------------------------------------------------------------------   \n\n");
    SetConsoleTextAttribute(hConsole, 14);
    printf("                         --> Enter Any Key After Reading  ...   \n\n");
    getch();


}















#endif // FUNCTIONS_H_INCLUDED
