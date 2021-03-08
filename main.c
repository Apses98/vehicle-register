#include "library.h"

/**< Programmets Main */
int main( ){

    /**< Variabler deklarationer  */
    person_t FordonReg[ MAX ];
    char s_alt[ MAX ] , s_sfordon[ MAX ] , s_id[ MAX ];
    int alt , id , i , antal_fordon = ZERO , sfordon;
    FILE * data;

    /**< Ladda Datan från filen och beräkna antalet fordon som finns i Registret */
    antal_fordon = ladda_data( FordonReg , data );

    /**< Varning Header */
    Line();
    if( antal_fordon == ZERO ){
        printf("Varning!!\nRegistret är Tomt.");
    }else if( antal_fordon == MAX ){
        printf("Varning!!\nRegistret är fullt.");
    }else {
        printf("DVGA01 - Labboration 4 - 2021\nAhmad Abo Warda & Abada Aroub");
    }
    Line();

    /**< Programmet startar här */
    while ( alt != 6 ){

        /**< Visa en meny med tillgängliga alternativ! */
        printf("\nVälj ett alternativ :\n 1. Lägg till ett fordon i Registret.\n 2. Ta bort ett fordon från Registret.\n 3. Sortera Registret efter Fordons Märke.\n 4. Skriv ut information om ett specifikt Fordon.\n 5. Skriv ut hela Registret.\n 6. Avsluta programmet.\n\nVänligen välj ett alternativ: ");

        /**< Ta emot användarens val */
        scanf("%s" , s_alt);
        alt = atoi( s_alt );

        /**< Switch satsen */
        switch ( alt )
        {
            /**< Case 1. Lägg till ett nytt fordon till registret */
            case 1:
                antal_fordon = laggtill( FordonReg , antal_fordon );
                break;

            /**< Case 2. Ta bort ett fordon från registret */
            case 2:
                /**< skriv ut tillgängliga fordons nummer */
                for( i = 0 ; i < antal_fordon ; i++ ){
                    printf("Fordon nr.%d\n" , i + 1 );
                }

                /**< Välj ett fordon att tabort */
                tabortigen:
                printf("Vilken fordon vill du ta bort?\nTa bort fordon nr.");
                scanf( "%s" , s_id );
                id = atoi( s_id );
                if( antal_fordon != ZERO && id <= antal_fordon && id > ZERO ){
                    antal_fordon = tabort( FordonReg , antal_fordon , id );
                } else {
                    Line();
                    printf("Ogitigt! \nFörsök igen.\n");
                    Line();
                    goto tabortigen;
                }
                break;

            /**< Case 3. Sortera alla fordon i registret efter fordonets märke */
            case 3:
                sortera_fordon( FordonReg , antal_fordon );
                break;

            /**< Case 4. Skriv ut information om ett spacifikt fordon i Registret*/
            case 4:
                /**< Visa tillgängliga fordon */
                Line();
                for( i = ZERO ; i < antal_fordon ; i++ ){
                    printf("Fordon nr.%d\n" , i + ONE );
                }
                Line();

                /**< Välj ett fordon för att visa */
                spacefikfordon:
                printf("Vilket fordon vill du se?\n");
                scanf( "%s" , s_sfordon );
                sfordon = atoi( s_sfordon );
                if( sfordon != ZERO ){
                    Line();
                    hittaettfordon( antal_fordon , sfordon, FordonReg );
                    Line();
                } else {
                    Line();
                    printf("Ogiltigt Val\nFörsök igen!");
                    Line();
                    goto spacefikfordon;
                }
                break;

            /**< Case 5. Skriv ut information om alla Fordon som finns i Registret */
            case 5:
                Line();
                skrivut( antal_fordon , FordonReg );
                Line();
                break;

            /**< Spara datan i filen och Avsluta programmet */
            case 6:
                Line();
                spara_fil( FordonReg , antal_fordon );
                Line();
                printf("Avslutar...\n");
                Line();
                break;

            /**< Default medelande vid ogitiga val */
            default:
                Line();
                printf("\nOgiltigt alternativ.\nVälj ett annat alternativ:\n\n");
                Line();
                break;

        } /**< Stängning för switch */
    }/**< Stängning för while loop */
}/**< Stängning för main */
