
#include "library.h"
/**< Funtionerna */
void skrivut( int antal_fordon , person_t FordonReg[ MAX ] ){
    for( int i = ZERO ; i < antal_fordon ; i++ ){
        printf("Fordon nr.%d\n Ägaren: %s %d år\n Fordonstyp: %s\n Registreringen: %s\n Fordonsmärke: %s\n\n", i + ONE, FordonReg[ i ].namn , FordonReg[ i ].alder , FordonReg[ i ].fordon.fordonstyp , FordonReg[ i ].fordon.regnummer , FordonReg[ i ].fordon.marke );
    }
}

int ladda_data( person_t FordonReg[ MAX ] , FILE * data ){
    int las_fil;
    int t = ZERO;

    /**< Ladda Datan från filen till vektorn */
    data = fopen( "data.txt", "r" );
    ( !data ) ? printf("Error\nKunde inte öppna filen!.") : ( 0 );
    do{
        las_fil = fscanf( data , "%s %d %s %s %s" , FordonReg[ t ].namn , &FordonReg[ t ].alder , FordonReg[ t ].fordon.fordonstyp , FordonReg[ t ].fordon.regnummer , FordonReg[ t ].fordon.marke );
       if( las_fil != EOF ){
        t++;
        }
    }while( las_fil != EOF );
    fclose( data );
    return t;
};

int laggtill( person_t FordonReg[ MAX ] , int antal_fordon ){
    /**< Funktionen Skriver ett nytt fordon i registret */
        char s_alder[ MAX ];

        /**< lägg till nytt fordon om registret är inte fullt */
        if( antal_fordon < MAX ){
            /**< Ta imot användarens inmatningar */
            Line();
            printf("\nSkriv namnet på bilensägare:");
            scanf("%s",FordonReg[ antal_fordon ].namn);
            Line();

            alderigen:
            printf("\nHur gammal är bil ägaren? :");
            scanf( "%s" , s_alder );
            FordonReg[ antal_fordon ].alder = atoi( s_alder );
            if( FordonReg[ antal_fordon ].alder == 0 ){
              printf("Ogiltigt!\nFörsök igen");
              goto alderigen;
            }
            Line();
            printf("\nVilken typ har din fordon? :");
            scanf( "%s" , FordonReg[ antal_fordon ].fordon.fordonstyp );

            Line();
            printf("\nVad är fordonets registreringsnummer? :");
            scanf( "%s" , FordonReg[ antal_fordon ].fordon.regnummer );

            Line();
            printf( "\nVad är fordonets Märke? :" );
            scanf( "%s" , FordonReg[ antal_fordon ].fordon.marke );

            Line();
            printf( "\nRegistreringen lyckades!\n\n" );
            Line();
            antal_fordon++ ;
        } else {
            Line();
            printf("\nRegistret är fullt\nTa bort ett fordon och försök igen!.\n\n");
            Line();
        }
            return antal_fordon;
};

int tabort( person_t FordonReg[ MAX ] , int antal_fordon , int id ){
    /**< Funktionen tar bort ett fordon från registret.     */
        person_t tmp[ MAX ];
        int j = ZERO;

        for( int i = ZERO ; i < MAX; i++ ){
            if( i != id - ONE ){
                strcpy( tmp[ j ].namn , FordonReg[ i ].namn );
                tmp[ j ].alder = FordonReg[ i ].alder;
                strcpy( tmp[ j ].fordon.fordonstyp , FordonReg[ i ].fordon.fordonstyp );
                strcpy( tmp[ j ].fordon.regnummer , FordonReg[ i ].fordon.regnummer );
                strcpy( tmp[ j ].fordon.marke , FordonReg[ i ].fordon.marke);
                j++;
            }
        }
        for( int i = ZERO ; i < antal_fordon; i++){
                strcpy( FordonReg[ i ].namn, tmp[ i ].namn );
                FordonReg[ i ].alder = tmp[ i ].alder ;
                strcpy( FordonReg[ i ].fordon.fordonstyp , tmp[ i ].fordon.fordonstyp );
                strcpy( FordonReg[ i ].fordon.regnummer , tmp[ i ].fordon.regnummer );
                strcpy( FordonReg[ i ].fordon.marke , tmp[ i ].fordon.marke );
            }
        antal_fordon -= ONE ;
        Line();
        printf("Borttagningen lyckades.");
        Line();
    return antal_fordon;
};
  void hittaettfordon( int antal_fordon , int sfordon , person_t FordonReg[ MAX ] ){
        /**< Funktionen läser filen och skriver ut alla fordon */
        for( int i = ZERO ; i < antal_fordon ; i++ ){
            if( i + ONE == sfordon ){
                printf("Fordon nr.%d\n Ägaren: %s %d år\n Fordonstyp: %s\n Registreringen: %s\n Fordonsmärke: %s\n", i + ONE, FordonReg[i].namn, FordonReg[i].alder, FordonReg[i].fordon.fordonstyp, FordonReg[i].fordon.regnummer, FordonReg[i].fordon.marke);
            }
        }
};

void sortera_fordon( person_t marke_sortering[ MAX ] , int id ){
        /**< Funktionen jämför alla fordons märke och sorterar alla fordon */
        person_t tmp;

        if( id != ZERO ){
            for( int i = ZERO ; i < id ; i++ ){
                if(marke_sortering[ i ].fordon.marke[ ZERO ] > ascii_id_innan_a && marke_sortering[ i ].fordon.marke[ ZERO ] < ascii_id_efter_z ){
                    marke_sortering[ i ].fordon.marke[ ZERO ] -= ascii_diff_stor_o_liten;
                }
             }
            for( int j = ZERO ; j < id ; j++ ){
                for( int i = ZERO ; i < id ; i++ ){
                    if(marke_sortering[ i ].fordon.marke[ ZERO ] > marke_sortering[ i + ONE ].fordon.marke[ ZERO ] && i < id - ONE ){
                        // i to tmp
                        strcpy( tmp.namn , marke_sortering[ i ].namn );
                        tmp.alder = marke_sortering[ i ].alder;
                        strcpy( tmp.fordon.fordonstyp , marke_sortering[ i ].fordon.fordonstyp );
                        strcpy( tmp.fordon.regnummer , marke_sortering[ i ].fordon.regnummer );
                        strcpy( tmp.fordon.marke , marke_sortering[ i ].fordon.marke );
                        // i+1 to i
                        strcpy( marke_sortering[ i ].namn , marke_sortering[ i + ONE ].namn );
                        marke_sortering[ i ].alder = marke_sortering[ i + ONE ].alder;
                        strcpy( marke_sortering[ i ].fordon.fordonstyp , marke_sortering[ i + ONE ].fordon.fordonstyp );
                        strcpy( marke_sortering[ i ].fordon.regnummer , marke_sortering[ i + ONE ].fordon.regnummer );
                        strcpy( marke_sortering[ i ].fordon.marke , marke_sortering[ i + ONE ].fordon.marke );
                        // tmp to i+1
                        strcpy( marke_sortering[ i + ONE ].namn , tmp.namn );
                        marke_sortering[ i + ONE ].alder = tmp.alder;
                        strcpy( marke_sortering[ i + ONE ].fordon.fordonstyp , tmp.fordon.fordonstyp );
                        strcpy( marke_sortering[ i + ONE ].fordon.regnummer , tmp.fordon.regnummer );
                        strcpy( marke_sortering[ i + ONE ].fordon.marke , tmp.fordon.marke );
                    }
                }
            }
        }
            Line();
            printf("Sorteringen lyckades.\nTryck 5 för att se den sorterade registret!");
            Line();
};

void Line(){
    printf("\n----------------------------------------------------------\n");
}

void spara_fil( person_t FordonReg[ MAX ] , int antal_fordon ){
    FILE * data;
    data = fopen( "data.txt", "w" );
    printf("Sparar datan...\n %d Fordon har sparats.\n" , antal_fordon);
     ( !data ) ? printf("Error\nKunde inte öppna filen!.") : ( 0 );
    for( int t = ZERO ; t < antal_fordon ; t++ ){
        fprintf( data , "%s %d %s %s %s\n" ,  FordonReg[ t ].namn , FordonReg[ t ].alder , FordonReg[ t ].fordon.fordonstyp , FordonReg[ t ].fordon.regnummer , FordonReg[ t ].fordon.marke );
    }
    fclose( data );
}
