#include <stdio.h>
#include <stdlib.h>

static char day_tab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char row1[13] =  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char row2[13] =  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *daytable[2] = {
    row1, 
    row2
};

int is_leap_year(int year) {
    // Since 2020 is a leap year, see if the difference from 2020 is divisible by 4
    return (year - 2020) % 4 == 0;
}

/*Given the year, the month and day of the month, return the day of year*/
int day_of_year(int year, int month, int day_of_month) {
    if (month < 1 || month > 12 || day_of_month < 0 || day_of_month > 31) {
        return -1;
    }

    int leap_year = is_leap_year(year);
    int days = day_of_month; 
    
    for (int i = 1; i < month; i++)
        days += *(*(daytable + leap_year) + i);

    return days;
}

void day_of_month(int year, int doy, int *pmonth, int *pday) {
    if (doy < 0 || doy > 365) {
        return;
    }

    int i, dom = doy;
    int leap_year = is_leap_year(year);
    
    for (i = 1; dom > daytable[leap_year][i]; i++) {
        dom -= daytable[leap_year][i];
    }

    *pday = dom;
    *pmonth = i;
}


int main() {
    int year = 2023, month = 3, day_of_month = 29;
    printf("2023 is a leap year? %d\n", is_leap_year(year));
    printf("day_of_year(29.03.2023) = %d\n", day_of_year(year, month, day_of_month));
}