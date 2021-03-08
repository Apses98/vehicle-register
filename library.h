
/**< Header filer */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10
#define ZERO 0
#define ONE 1
#define ascii_id_innan_a 96
#define ascii_id_efter_z 123
#define ascii_diff_stor_o_liten 32


/**< Structar / objekt*/
struct fordon
{
  char fordonstyp[ MAX + MAX ];
  char regnummer[ MAX ];
  char marke[ MAX + MAX ];
};
typedef struct fordon fordon_t;

struct person
{
  char namn[ MAX + MAX ];
  int alder;
  fordon_t fordon;
};
typedef struct person person_t;

/**< Funktion deklaration */
void spara_fil( person_t FordonReg[ MAX ] , int antal_fordon );
int ladda_data( person_t FordonReg[ MAX ] , FILE * data );
void skrivut( int antal_fordon , person_t FordonReg[ MAX ] );
int laggtill( person_t FordonReg[ MAX ] , int antal_fordon );
int tabort( person_t FordonReg[ MAX ] , int antal_fordon , int id );
void hittaettfordon( int antal_fordon , int sfordon , person_t FordonReg[ MAX ] );
void sortera_fordon( person_t marke_sortering[ MAX ] , int id );
void Line();
