#include <stdio.h>
#include "string.h"

unsigned int monatstage[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef enum
{
    MINUTE,
    STUNDE,
    TAG,
    MONAT,
    JAHR
} Datum;

typedef enum
{
    STUFE1,
    STUFE2,
    STUFE3
} Prioritaet;

typedef struct
{
    int wert;
    Datum einheit;
} Dauer;

typedef struct
{
    int minute;
    int stunde;
    int tag;
    int monat;
    int jahr;
    Dauer dauer;
    char beschreibung[10];
    Prioritaet prio;
} Termin;

Termin verschiebung(Termin, Dauer);
Termin terminBerechnung(Termin, Dauer);

int main()
{
    Termin terminA;
    Dauer zeitspanne;
    terminA.minute = 12;
    terminA.stunde = 21;
    terminA.tag = 28;
    terminA.monat = 2;
    terminA.jahr = 2023;
    terminA.prio = 1;
    strcpy(terminA.beschreibung, "KAFFEE");
    zeitspanne.einheit = TAG;
    zeitspanne.wert = 1;

    printf("Alter Termin %02d:%02d Uhr, %02d.%02d.%d Datum\n", terminA.stunde, terminA.minute, terminA.tag,
           terminA.monat, terminA.jahr);

    terminA = verschiebung(terminA, zeitspanne);

    printf("Neuer Termin %02d:%02d Uhr, %02d.%02d.%d Datum", terminA.stunde, terminA.minute, terminA.tag,
           terminA.monat, terminA.jahr);
    return 0;
}
Termin verschiebung(Termin t, Dauer z)
{

    if (z.einheit == MINUTE)
        t.minute += z.wert;
    else if (z.einheit == STUNDE)
        t.stunde += z.wert;
    else if (z.einheit == TAG)
        t.tag += z.wert;
    else if (z.einheit == MONAT)
        t.monat += z.wert;
    else if (z.einheit == JAHR)
        t.jahr += z.wert;

    return terminBerechnung(t, z);
}

Termin terminBerechnung(Termin termin, Dauer zeitspanne)
{
    if (termin.jahr < 1582)
    {
        printf("Beginn des gregorianischen Kalenders beginnt erst ab 1582, Bitte nur diese Jahr verwenden.");
        return termin;
    }
    if (termin.jahr % 4 == 0 && (termin.jahr % 100 != 0 || termin.jahr % 400 == 0))
        monatstage[1] = 29;

    if (zeitspanne.wert < 0)
    {

        /* -- Werte*/
        while (termin.minute < 0)
        {
            termin.minute += 60;
            termin.stunde--;
        }

        while (termin.stunde < 0)
        {
            termin.stunde += 24;
            termin.tag--;
        }

        while (termin.monat < 0)
        {
            termin.monat += 12;
            termin.jahr--;
        }

        while (termin.tag <= 0)
        {
            termin.monat--;

            if (termin.monat == 0)
            {
                termin.monat += 12;
                termin.jahr--;
            }

            if (termin.jahr % 4 == 0 && (termin.jahr % 100 != 0 || termin.jahr % 400 == 0))
                monatstage[1] = 29;
            else
                monatstage[1] = 28;

            termin.tag = monatstage[termin.monat - 1] + termin.tag;
        }
    }
    else
    {
        /* ++ Werte*/
        while (termin.minute >= 60)
        {
            termin.minute -= 60;
            termin.stunde++;
        }

        while (termin.stunde >= 24)
        {
            termin.stunde -= 24;
            termin.tag++;
        }
        while (termin.monat > 12)
        {
            termin.monat -= 12;
            termin.jahr++;
        }

        while (termin.tag > monatstage[termin.monat - 1])
        {
            termin.tag -= monatstage[termin.monat - 1];
            termin.monat++;
            if (termin.monat > 12)
            {
                termin.monat -= 12;
                termin.jahr++;
            }

            if (termin.jahr % 4 == 0 && (termin.jahr % 100 != 0 || termin.jahr % 400 == 0))
                monatstage[1] = 29;
            else
                monatstage[1] = 28;
        }
    }
    return termin;
}
