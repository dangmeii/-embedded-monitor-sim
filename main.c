#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char type[20];
    float threshold;
} SensorConfig;

int main (){
    SensorConfig list[30];
    int count = 0;

    FILE *file = fopen("config.txt", "r");
    if (file == NULL){
        printf("Khong mo duoc file config.txt\n");
        return 1;
    }

    printf("Mo file thanh cong. Bat dau doc du lieu cau hinh...");

    while (fscanf(file, "%d %s %f", &list[count].id, list[count].type, &list[count].threshold) == 3){
        printf("Da nap Sensor [%d]: Loai = %s, Nguong = %.2f\n", list[count].id, list[count].type, list[count].threshold);
        count++;
        if(count >= 30) break;
    }

    fclose(file);
   
    printf("Tong so sensor san sang: %d ", count);

     system("pause"); 

    return 0;
    
}