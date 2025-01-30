#include <stdio.h>
#include <string.h>
#include <time.h>

char *action, *activity;
time_t startTime, currentTime;

// Define availible activities (struct/enum? - see #define keyword) 

int main(int argc, char *argv[])
{
    // TODO: Validate input

    action = argv[1];
    activity = argv[2];

    startTime = time(NULL);

    // Get start time
    if(strcmp(action, "start") == 0)
    {
        startTime = time(NULL);
    }

    // Get elapsed time
    if(strcmp(action, "stop") == 0)
    {
        // add startTime check once data is logged to file: && startTime != (time_t) NULL
        // enable user to enter elapsed time, to handle cases where start doesn't exist

        currentTime = time(NULL); //TODO: figure out why currentTime getting set to 0
        double elapsedTime = difftime(currentTime, startTime);
        printf("%f spent on %s\n", elapsedTime, activity);

        // Store elapsed time to a csv logfile
        FILE *fp = fopen("timeLog.csv", "a"); // TODO: add new csv column headers if file doesn't exist 
        fprintf(fp, "%d,%s,%f\n", startTime, activity, elapsedTime);
        fclose(fp);
    }

    // convert time to be more readable

    // Get today's status

    // Enable removing/editing lines in csv file
}