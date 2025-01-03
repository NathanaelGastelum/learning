#include <stdio.h>
#include <string.h>
#include <time.h>

const char *action, *activity;
time_t startTime;

// Define availible activities (struct/enum?)

main(int argc, char *argv[])
{
    action = argv[1];
    activity = argv[2];

    // Get start time
    if(strcmp(action,"start") == 0)
    {
        startTime = time(NULL);
    }

    // Get elapsed time
    if(strcmp(action, "stop") == 0 && startTime != (time_t) NULL)
    {
        double elapsedTime = difftime(time(NULL), startTime);
        printf("%d spent on %s\n", activity, elapsedTime);
    }

    // Store elapsed time to a csv logfile
    
    // Get today's status
}