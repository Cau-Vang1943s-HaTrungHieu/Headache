#include <iostream>

struct Date
{
    int day, month, year;
    int daysInMonth[13] = 
    {
        0,
        31, 0, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    };

    friend std::istream& operator>>(std::istream& input, Date& date)
    {
        input >> date.day >> date.month >> date.year;
        date.daysInMonth[2] = (date.is_leapYear() ? 29 : 28);
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Date date)
    {
        output 
        << date.day << "/" 
        << date.month << "/"
        << date.year;
        return output;
    }

    bool is_validDate()
    {
        if (year < 1) return false;
        if (month < 1 or month > 12) return false;

        int lastDay = daysInMonth[month];
        if (month == 2 and is_leapYear()) lastDay = 29;
        if (day < 1 or day > lastDay) return false;
        
        return true;
    }

    bool is_leapYear() const
    {
        return year % 400 == 0 or year % 4 == 0 and year % 100 != 0;
    }

    int dayOfYear() const
    {
        int total = day;

        for (int m = 1; m < month; m++)
        {
            total += daysInMonth[m];
        }
        return total;
    }

    std::string dayOfWeek() const
    {
        int q = day;
        int m = month;
        int y = year;
        /*
            Jan and Feb are treated as months 13 and 14 of
            the previous year.
        */
       if (m == 1 or m == 2)
       {
            m += 12;
            y--;
       }
       
       int K = y % 100;
       int J = y / 100;

       int h = (q
                + (13 * (m + 1)) / 5
                + K
                + K / 4
                + J / 4
                + 5 * J) % 7;

        static const std::string weekday[] =
        {
            "Saturday",
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday"
        };

        return weekday[h];
    }

    Date next_date() const
    {
        Date result;
        result.day = day + 1;
        result.month = month;
        result.year = year;

        if (result.day > daysInMonth[result.month])
        {
            result.day = 1;
            result.month += 1;
        }
        if (result.month > 12)
        {
            result.month = 1;
            result.year += 1;
        }
        return result;
    }

    bool operator==(const Date& other) const
    {
        return
        day == other.day and
        month == other.month and
        year == other.year;
    }

    bool is_the_same_DOW(const Date& other) const
    {
        return dayOfWeek() == other.dayOfWeek();
    }

    bool operator<(const Date& other) const
    {
        if (year < other.year) return true;
        else if (year == other.year)
        {
            if (month < other.month) return true;
            else if (month == other.month)
                if (day < other.day) return true;
        }
        return false;
    }


    // You stop at this
    int operator-(const Date& other) const
    {
        Date max, min;
        if (*this < other)
        {
            max = other;
            min = *this;
        }
    }
};

int main()
{

    return 0;
}