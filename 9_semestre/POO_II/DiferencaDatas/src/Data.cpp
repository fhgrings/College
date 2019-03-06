#include "Data.h"
#include "time.h"

Data::Data(dia_s, mes_s, ano_s)
{
    time(&timeA);
    tptr = localtime(&timeA);
    tA = *tptr;

    tA.tm_mday = dia_s;
    tA.tm_mon = mes_s;
    tA.tm_year = ano_s - 1974;
    timeA = mktime(&tA);
}

Data Data::operator-(Data data_s)
{
    difference = difftime(timeA, data_s.timeA);
    printf ("Difference is %.0f seconds\n", difference);
}
