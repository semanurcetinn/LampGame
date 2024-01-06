#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool is_all_light_on(int lights[]);

int main() {
    int max_trial = 0;
    srand(time(NULL));
    int game_count = 1000000;

    for (int i = 0; i < game_count ; i++) {
        int trial=0;
        int lights[6] = {0,0,0,0,0,0};
        while(is_all_light_on(lights) == false){
            int value = (rand() % (6))+1;

            if(lights[value-1] == 1){
                lights[value-1] = 0;
            }
            else{
                lights[value-1] = 1;
            }
            trial++;
        }
        max_trial += trial;
    }
    double average_trial = (double)max_trial / game_count;
    printf("ortalama sayi:%f",average_trial);
    return 0;
}
bool is_all_light_on(int lights[]){
    for (int i = 0; i < 6 ; i++) {
        if( lights[i] == 0){
            return false;
        }
    }
    return true;
}
