//   BY   : Shapour Discover
//   DATE : 2021-03-31
//   TIME : 20:01

#include "Date.h"

int main() {
    Date date1(2020, 1, 1);
    date1.Print();
    date1.NextDay().Print();
    date1.Print();

    date1.SetDate(2021, 1, 31);
    date1.Print();
    date1.NextDay().Print();

    date1.SetDate(2020, 2, 28);
    date1.Print();
    date1.NextDay().Print();

    date1.SetDate(2020, 12, 31);
    date1.Print();
    date1.NextDay().Print();

    date1.SetYear(1600);
    date1.Print();
    date1.SetDay(31);
    date1.Print();
    date1.NextMonth().NextMonth().NextMonth();
    date1.Print();
    date1.SetDay(31);
    date1.Print();


    if (Date::IsValidDate(2021, 2, 29))
    {
        cout << "Date is valid" << endl;
    }
    else
    {
        cout << "Date is not valid" << endl;
    }


    if (Date::IsLeapYear(2000))
    {
        cout << "2000 is leap year" << endl;
    }
    else
    {
        cout << "2000 is not leap year" << endl;
    }

    if (Date::IsValidDate(2021, 1, 1))
    {
        Date::PrintDayOfWeek(2021, 1, 1);
    }


    Date* date4 = nullptr;
    date4 = new Date(9999, 12, 30);
    date4->NextDay().Print();
    date4->NextDay();
    date4->Print();
    delete date4;

    Date date5(2021, 1, 1);
    date5.PreviousDay().Print();

    Date date6(2021, 3, 31);
    date6.NextMonth().Print();

    Date date7(2020, 3, 31);
    date7.PreviousMonth().Print();

    Date date8(2020, 2, 29);
    date8.NextYear().Print();

    Date date9(2020, 2, 29);
    date9.PreviousYear().Print();

	return 0;
}