#include <stdio.h>
#include <string.h>
#include <time.h>

char *action, *activity;
time_t startTime;

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
    // add startTime check once data is logged to file: && startTime != (time_t) NULL
    if(strcmp(action, "stop") == 0)
    {
        double elapsedTime = difftime(time(NULL), startTime);
        printf("%d spent on %s\n", elapsedTime, activity);
    }

    // Store elapsed time to a csv logfile
    
    // Get today's status
}