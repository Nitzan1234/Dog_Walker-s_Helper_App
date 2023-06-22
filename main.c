#include <stdio.h>

int main()
{
    int hourlyRate;
    int hourStart, minuteStart, hourFinish, minuteFinish;
    int hoursWorked, minutesWorked;
    int totalMinutes;
    float dailyPay;
    int Day_Sum=0;
    char isDue=0;

    while (1)
    {
    printf("Enter 1 to continue adding your pay and 0 for otherwise ");
    scanf("%c",&isDue);
    if(isDue)
    {
    printf("Enter 1 for an hourly rate of $50 or 0 for an hourly rate of $80: ");
    scanf("%d", &hourlyRate);

    printf("Enter the start time (hour minute): ");
    scanf("%d %d", &hourStart, &minuteStart);

    printf("Enter the finish time (hour minute): ");
    scanf("%d %d", &hourFinish, &minuteFinish);

    // Calculate the total minutes worked
    totalMinutes = (hourFinish - hourStart) * 60 + (minuteFinish - minuteStart);

    // Calculate the hours and minutes worked separately
    hoursWorked = totalMinutes / 60;
    minutesWorked = totalMinutes % 60;

    // Calculate the daily pay based on the hourly rate
    if (hourlyRate == 1) {
        dailyPay += hoursWorked * 50 + minutesWorked * (50.0 / 60.0);
    } else {
        dailyPay += hoursWorked * 80 + minutesWorked * (80.0 / 60.0);
    }

    printf("Total hours worked: %d hours and %d minutes\n", hoursWorked, minutesWorked);
    printf("Daily pay: $%.2f\n", dailyPay);
    isDue = 0;
    }
    else
    {
        printf("Money made today is: $%.2f\n",dailyPay);
        break;
    }
    }
    return 0;
    }    
    
    
