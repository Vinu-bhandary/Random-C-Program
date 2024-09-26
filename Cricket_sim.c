#include<stdio.h>
#include<time.h>
int wicket = 0,targetrun,totalrun=0;
int runsPerOver() {
    int runs=0;
    for(int i=0;i<6;i++) {
        sleep(rand()%3+1);
        srand(time(NULL));
        int runperball = rand()%6 +1;
        if(runperball==5) {
            printf("W ");
            wicket++;
            if(wicket==12) {
                printf("\nAll out!!!\n");
                break;
            }
        }
        else {
            printf("%d ",runperball);
            runs+=runperball;
        }
    }
    printf("\n");
    return runs;
}
int main() {
    int overs;
    printf("How many overs? ");
    scanf("%D",&overs);

    printf("Batting starts!!!\n");
    for(int over=1;over<=overs;over++) {
        printf("Over %d:\n",over);
        int runperover=runsPerOver();
        totalrun+=runperover;
        if(wicket==10)
            break;
    }
    printf("\nTotal score: %d/%d\n",totalrun,wicket);
    return 0;
}
