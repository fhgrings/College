#include "ticket.h"
#include "time.h"

Ticket::Ticket()
{
    value = 0;
    timer = time(NULL);
    timeString = ctime(&timer);


}

Ticket::Ticket(int s_value)
{
    value = s_value;
    timer = time(NULL);
    timeString = ctime(&timer);

}
