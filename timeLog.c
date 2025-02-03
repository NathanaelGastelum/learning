#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

char *action, *activity;
time_t startTime, currentTime;

// Define availible activities (struct/enum? - see #define keyword) 

int main(int argc, char *argv[])
{
    // TODO: Validate input

    action = argv[1];
    activity = argv[2];

    startTime = time(NULL); // remove after startTime check is implemented

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

        currentTime = time(NULL);
        double elapsedTime = difftime(currentTime, startTime);

        char startTimeString[8];
        //strftime(startTimeString, sizeof currentTimeString, "%X", currentTime); // TODO: fix startTime format
        char *elapsedTimeString;
        asprintf(&elapsedTimeString, "%.0f:%.0f:%.0f", elapsedTime/3600, (fmod(elapsedTime, 3600.0))/60, fmod(elapsedTime, 60.0)); // convert elapsedTime to readable h:m:s format

        printf("%s spent on %s\n", elapsedTimeString, activity);

        // Store elapsed time to a csv logfile
        FILE *fp = fopen("timeLog.csv", "a"); // TODO: add new csv column headers if file doesn't exist
        fprintf(fp, "%d,%s,%s\n", startTime, activity, elapsedTimeString);
        fclose(fp);
        free(elapsedTimeString);
    }

    // Get today's status

    // Enable removing/editing lines in csv file
}