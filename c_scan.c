#include <stdio.h>
#include <stdlib.h>

void main()
{
    int req[20], new[20], ini, size, i, j, headm = 0, d, temp, cpy, space;
    int dir;
    
    printf("enter disk space :");
    scanf("%d", &space);
    
    printf("enter number of requests :");
    scanf("%d", &size);
    
    printf("enter requests : ");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &req[i]);
    }
    
    printf("enter head location :");
    scanf("%d", &ini);
    
    // Sorting the requests in ascending order
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(req[j] > req[j + 1])
            {
                temp = req[j + 1];
                req[j + 1] = req[j];
                req[j] = temp;
            }
        }
    }
    
    new[0] = 0;
    new[size + 1] = space - 1;
    
    for(i = 0; i < size; i++)
    {
        new[i + 1] = req[i];
    }
    
    i = 0;
    while(new[i] < ini)
    {
        i++;
    }

    cpy = i;
    do
    {
        d = abs(ini - new[i]);
        headm += d;
        ini = new[i];
        printf("%d\t", new[i]);
        i = (i + 1) % (size + 2);
    } while(i != cpy);
    
    printf("\nTotal head movement: %d", headm);
}
