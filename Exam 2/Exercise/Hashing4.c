#include <stdio.h>
#include <stdlib.h>

#define Table_size 20

typedef struct {
    int audio_id;
    int frequency;
} HashEntry;


HashEntry table[Table_size];

void initTable(void){
    for(int i = 0 ; i< Table_size ; i++){
        table[i].audio_id = -1;
        table[i].frequency = 0;
    }
}

void insertAndCount(int id){
    int index = id % Table_size;

    while(table[index].audio_id != -1 && table[index].audio_id != id){
        index = (index +1) % Table_size;
    }
    if(table[index].audio_id == -1){
        table[index].audio_id = id;
        table[index].frequency = 1;
    }else table[index].frequency++;

}

void findViralSounds(void){
    for(int i = 0 ; i< Table_size ; i++){
        if(table[i].audio_id != -1 && table[i].frequency >= 5){
            printf("Audio Id %d (Freq : %d)",table[i].audio_id,table[i].frequency);
        }
    }
}

void solve(void);

int main(void) {
    solve();
    return 0;
}

void solve(void) {
    int feed[] = {
        101, 777, 404, 777, 777, 202, 777, 101, 999, 999,
        101, 888, 999, 999, 777, 101, 888, 999, 101, 777
    };
    int n = sizeof(feed) / sizeof(feed[0]);

    /* TODO 4 */
    initTable();
    for (int i = 0; i < n; i++)
        insertAndCount(feed[i]);
    findViralSounds();
}