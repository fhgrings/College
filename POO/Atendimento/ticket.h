#ifndef TICKET_H
#define TICKET_H


class Ticket
{
public:
    Ticket();
    Ticket(int);
    int value;
    time_t now;
    tm *ltm;
    // current date/time based on current system
    // print various components of tm structure.
    //   cout << "Year" << 1970 + ltm->tm_year<<endl;
    //   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
    //   cout << "Day: "<<  ltm->tm_mday << endl;
    //   cout << "Time: "<< 1 + ltm->tm_hour << ":";
    //   cout << 1 + ltm->tm_min << ":";
    //  cout << 1 + ltm->tm_sec << endl;
};

#endif // TICKET_H
