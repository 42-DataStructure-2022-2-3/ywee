#include "quicksort.h"

int main(){
  int i;
  int list[9] = {5, 3, 8, 4, 9, 1, 6, 2, 7};

  // 퀵 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 8)
  quicksort(list, 0, 8);

//  // 정렬 결과 출력
//  for(i=0; i< 9; i++){
//    printf("%d\n", list[i]);
//  }
  return 0;
}
