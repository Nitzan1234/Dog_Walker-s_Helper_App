#include <stdio.h>
#include <stdlib.h>

void writeToFile(FILE *filename, int variable)
{
    const char *fileName = "C:\\Users\\nyznl\\Downloads\\משכורת.txt";
    filename = fopen(fileName, "a");
    if (filename == NULL) {
        printf("Failed to open the file: %s\n", fileName);
        return;
    }

    fprintf(filename, "%d\n", variable);

    fclose(filename);
}

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
        FILE *fp;
        printf("Money made today is: $%.2f\n",dailyPay);
        writeToFile(fp, dailyPay);
        break;
    }
    FILE *fp;
    fp = fopen("C:\\Users\\nyznl\\Downloads\\משכורת.txt","r+");
    if(fp == NULL)
   {
      printf("Error!");
      exit(1);
   }
    int sum = 0;
    char line[31];
    while (fgets(line, sizeof(line), fp))
    {
        sum += atoi(line);  // Convert line to an integer and add to sum
    }

    fclose(fp);

    printf("Sum of all lines: %d\n", sum);
    return 0;
    }
}
