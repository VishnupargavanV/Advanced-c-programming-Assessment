#include <stdio.h>
#include <string.h>

#define MAX_DAYS 7
#define MAX_TASKS 3

// Structure for one day
struct Day
{
    char dayName[20];
    char tasks[MAX_TASKS][100];
    int taskCount;
};

int main()
{
    // Array of structures for 7 days
    struct Day week[MAX_DAYS] = {
        {"Monday", {}, 0},
        {"Tuesday", {}, 0},
        {"Wednesday", {}, 0},
        {"Thursday", {}, 0},
        {"Friday", {}, 0},
        {"Saturday", {}, 0},
        {"Sunday", {}, 0}
    };

    int i, j;

    // Input tasks for each day
    for(i = 0; i < MAX_DAYS; i++)
    {
        printf("\nEnter number of tasks for %s (max 3): ",
               week[i].dayName);

        scanf("%d", &week[i].taskCount);

        // Limit tasks to maximum 3
        if(week[i].taskCount > MAX_TASKS)
        {
            week[i].taskCount = MAX_TASKS;
        }

        getchar(); // clear newline from buffer

        // Input tasks
        for(j = 0; j < week[i].taskCount; j++)
        {
            printf("Enter task %d: ", j + 1);
            fgets(week[i].tasks[j], 100, stdin);

            // Remove newline character
            week[i].tasks[j][strcspn(week[i].tasks[j], "\n")] = '\0';
        }
    }

    // Display tasks grouped by day
    printf("\n\n===== WEEKLY CALENDAR =====\n");

    for(i = 0; i < MAX_DAYS; i++)
    {
        printf("\n%s:\n", week[i].dayName);

        if(week[i].taskCount == 0)
        {
            printf("No tasks.\n");
        }
        else
        {
            for(j = 0; j < week[i].taskCount; j++)
            {
                printf("%d. %s\n", j + 1,
                       week[i].tasks[j]);
            }
        }
    }

    return 0;
}