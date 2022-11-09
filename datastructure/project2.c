#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include<windows.h>

int n = 100000;
int limit[] = { 1,100,500,1000 };

//eq범위를 저장할 구조체
typedef struct equalRange {
   int a, b;
}er;

//중앙값 리턴
int findIndexOfMedianOfThree(int *arr, int a, int b, int c) {
   if ((arr[b] >= arr[a] && arr[c] <= arr[a]) || (arr[b] <= arr[a] && arr[c] >= arr[a])) {
      return a;
   }
   else if ((arr[a] >= arr[b] && arr[c] <= arr[b]) || (arr[a] <= arr[b] && arr[c] >= arr[b])) {
      return b;
   }
   else {
      return c;
   }
}

int findPivot(int *arr, int l, int r, int ver) {
   //ver) 0:결정적1, 1:결정적3, 2:무작위1, 3:무작위3
   int a, b, c;
   if (ver == 0) {
      return r;
   }
   else if (ver == 2) {
      return ((long)(rand() << 15 | rand()) % (r - l + 1)) + l;//l~r사이의 난수 리턴
   }
   else {
      //결정적3||무작위3 버전
      if (r - l + 1 < 3) {
         return l;//부배열의 크기가 3미만일때 l반환
      }
      else {
         if (ver == 1) {
            return findIndexOfMedianOfThree(arr, l, (r + l) / 2, r);//맨앞,중간,맨뒤중 중앙값
         }
         else {
            a = ((long)(rand() << 15 | rand()) % (r - l + 1)) + l;
            b = ((long)(rand() << 15 | rand()) % (r - l + 1)) + l;
            c = ((long)(rand() << 15 | rand()) % (r - l + 1)) + l;
            return findIndexOfMedianOfThree(arr, a, b, c);//랜덤한 세 원소의 중앙값 리턴
         }
      }
   }
}

er inPlacePartition(int *arr, int l, int r, int k) {
   int i, temp;
   int left, right;
   int p = arr[k];//피봇값 저장
   er result;//eq 범위를 저장할 변수
   left = l;
   right = r - 1;

   //피봇과 r의 원소 교환
   temp = arr[k];
   arr[k] = arr[r];
   arr[r] = temp;


   //피봇보다 작은건 왼쪽으로, 큰거나 같은건 오른쪽으로 이동
   while (left <= right) {
      while (arr[left] < p) {
         left++;
      }
      while (arr[right] >= p) {
         right--;
      }
      if (left < right) {
         temp = arr[left];
         arr[left] = arr[right];
         arr[right] = temp;
      }
   }
   //left값과 r의 값 변경-> 인덱스가left인곳에 피봇값이 위치해있고,
   //left보다 큰쪽에 피봇과 크거나 같은 원소들이 있음.
   temp = arr[left];
   arr[left] = arr[r];
   arr[r] = temp;

   //left보다 큰쪽에 있는 pivot값과 같은 원소들을 재배치 하는과정
   result.a = left;//a저장
   left++;
   for (i = result.a + 1; i <= r; i++) {
      //피봇기준 오른쪽에 있는것중 같은게 있으면 피봇쪽으로 스왑
      if (arr[i] == p) {
         temp = arr[left];
         arr[left++] = arr[i];
         arr[i] = temp;
      }
   }
   result.b = left - 1;//b저장
   return result;//범위 리턴
}

void rQuickSort(int *arr, int l, int r, int ver, int li) {
   int k;
   int a, b, i;
   er result;//피봇과 같은 원소의 범위를 저장할 배열
   //부배열의 크기가 li보다 클때만 실행
   //부배열의 크기가 li이하가되면 스탑후 quickSort함수안의 삽입정렬 수행
   if (r - l >= li) {
      k = findPivot(arr, l, r, ver);//피봇값 배정
      result = inPlacePartition(arr, l, r, k);//inPlacePartition을 한 뒤 eq바구니의 범위 리턴
      //재귀 호출
      rQuickSort(arr, l, result.a - 1, ver, li);
      rQuickSort(arr, result.b + 1, r, ver, li);
   }
}

//삽입정렬
void insertSort(int *arr, int n) {
   int i, j, temp;
   for (i = 1; i < n; i++) {
      temp = arr[i];
      for (j = i - 1; j >= 0; j--) {
         if (arr[j] > temp) {
            arr[j + 1] = arr[j];
         }
         else {
            break;
         }
      }
      arr[j + 1] = temp;
   }
}

//메인quickSort
void quickSort(int *arr, int ver, int li) {
   rQuickSort(arr, 0, n - 1, ver, li);
   if (li > 1) {
      insertSort(arr, n);
   }
   return;
}

//n개의 1~n까지의 난수 생성
void createArray(int *arr) {
   int i;
   for (i = 0; i < n; i++) {
      arr[i] = ((long)(rand() << 15 | rand()) % n) + 1;
   }
   return;
}

int main() {
   int  *arr = NULL, i, j, k;
   int *carr = NULL;
   LARGE_INTEGER st, end, diff, ticksPerSec;
   srand(time(NULL));
   arr = (int *)malloc(n * sizeof(int));
   carr = (int *)malloc(n * sizeof(int));
   createArray(arr);
   printf("Limit\t\t결정적1\t\t\t결정적3\t\t\t무작위1\t\t\t무작위3\n");
   QueryPerformanceFrequency(&ticksPerSec);
   for (i = 0; i < 4; i++) {
      printf("%d\t\t", limit[i]);
      for (j = 0; j < 4; j++) {
         for (k = 0; k < n; k++) {
            carr[k] = arr[k];
         }
         QueryPerformanceCounter(&st);
         //quicksort
         //i) 리미트 인덱스
         //j) 0:결정적1, 1:결정적3, 2:무작위1, 3:무작위3
         quickSort(carr, j, limit[i]);
         QueryPerformanceCounter(&end);
         diff.QuadPart = end.QuadPart - st.QuadPart;
         printf("%.12f ms\t", 1000 * ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
      }
      printf("\n");
   }
   free(arr);
   free(carr);
}