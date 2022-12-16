#include <stdio.h>

struct TRIANGLE {

   int len_a;
   int len_b;
   int len_c;
};

enum {

   TRIANGLE_ERROR = -1,
   TRIANGLE_COMMO = 0,
   TRIANGLE_ISOSC,
   TRIANGLE_EQUIL,
};

int get(struct TRIANGLE *data); 

int main() {

   struct TRIANGLE data; 

   
    scanf("%d %d %d", &data.len_a, &data.len_b, &data.len_c);

    if (data.len_a <= 0 || data.len_b <= 0 || data.len_c <= 0) {
        printf("프로그램 종료!!\n");
        return 0;
    }

    switch (get(&data)) {

    case TRIANGLE_ERROR:
        printf("삼각형이 될 수 없습니다.\n");
        break;

    case TRIANGLE_EQUIL:
        printf("정삼각형 입니다.\n");
        break;

    case TRIANGLE_ISOSC:
        printf("이등변삼각형 입니다.\n");
        break;

    case TRIANGLE_COMMO:
        printf("일반삼각형 입니다.\n");
        break;

    default:
        printf("종료합니다\n"); 
        break;
    }
   

   return 0;

}

 

int get(struct TRIANGLE *data) {

   int room[3] = { data->len_a, data->len_b, data->len_c };
   int tmp = 0;

   for (int i = 0; i < 3; i++) {
       for (int k = i + 1; k < 3; k++) {
           if (room[i] > room[k]) {
               tmp = room[i];
               room[i] = room[k];
               room[k] = tmp;
           }
       }
   }

   if (room[2] >= room[0] + room[1]) {
       return TRIANGLE_ERROR;
   }

   tmp = 0;

   if (room[0] == room[1]) {
       tmp++;
   }

   if (room[0] == room[2]) {
       tmp++;
   }

   if (room[1] == room[2]) {
       tmp++;
   }

   switch (tmp) {

   case 0:

       return TRIANGLE_COMMO;
       break;

   case 1:

       return TRIANGLE_ISOSC;
       break;

   case 2:

   case 3:

       return TRIANGLE_EQUIL;
       break;

   default:

       break;
   }

   return TRIANGLE_ERROR;

}
