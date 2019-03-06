#ifndef DATA_H
#define DATA_H
#include "time.h"


class Data
{
    public:
        Data();

        Data(int dia_s, int mes_s, int ano_s);

        Data operator-(Data data);

        virtual ~Data();

    protected:

    private:
        time_t timeA;
        struct tm tA, *tptr;
        double difference;
};

#endif // DATA_H
