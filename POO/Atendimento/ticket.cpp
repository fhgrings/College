#include "ticket.h"

Ticket::Ticket()
{
    value = 0;
    time_t now = time(0);
    tm *ltm = localtime(&now);
}

Ticket::Ticket(int s_value)
{
    value = s_value;
    time_t now = time(0);
    tm *ltm = localtime(&now);
}
