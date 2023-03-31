#include <stdio.h>

typedef unsigned char uint8_t;
typedef signed int int32_t;
typedef signed char int8_t;
int8_t insertionSort(int32_t *array, uint8_t arraySize);
void printArray(int32_t *array, uint8_t arraySize);
int Array_userinput(int32_t *array);
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);



int main(){
  int32_t array[10];
  uint8_t arraySize =10;
  uint8_t sizeofLCS=0;
  int c=1;
  uint8_t *ptr_sizeofLCS=&sizeofLCS;
  for (int i=0;i<4;i++){
    c= Array_userinput(array);
  if (c==0){
  insertionSort(array,arraySize);
  printArray(array,arraySize);
  }}
  c=1;
  for (int i=0;i<5;i++){
  c= Array_userinput(array);
  if (c==0){
  insertionSort(array,arraySize);
  printArray(array,arraySize);
  lcsGetSize(array,arraySize,ptr_sizeofLCS);
  }}
}
/**********************************************************************
/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm*/
int8_t insertionSort(int32_t *array, uint8_t arraySize){
    int32_t temp;
    int32_t prev;
    if (array==NULL) {
            printf("Empty array\n");
            return -1;}
    else if (arraySize==0||arraySize>10) {printf("Array size out of range\n"); return -2;}

    else {
        for (int i=1;i<arraySize;i++){
        temp =array[i];
        prev= i - 1;
        while (temp < array[prev] && prev >= 0) {
          array[prev + 1] = array[prev];
          --prev;
        }
        array[prev+1] = temp;
    }
    return 0;}

}//returns -1 if the array is empty- returns -2 if the array size is 0 or >10- returns 0 if sorting is done without errors
/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(int32_t *array, uint8_t arraySize){
for (int i = 0; i < arraySize; i++) {
  printf("%d, ", array[i]);
  }
printf("\n");
}
/*Description:
* - This function asks user for array elements
*/
int Array_userinput(int32_t *array){
printf("\nEnter array elements:");
char x='m';
fflush(stdin);
scanf("%c",&x);
if (x=='\n') {printf("Empty array\n"); return 1;}
else{
array[0]=x-48;
for(int i=1;i<10;i++){
    scanf("%d",&array[i]);
}
scanf("%c",&x);
if (x!='\n') {printf("Array is out of range\n"); return 1;}
fflush(stdin);
    return 0;}
}

/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size*/

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS){
int counter=0;
*sizeofLCS=0;
for (int i=0;i<10;i++){
    int k=array[i]+1;
    if (array[i+1]==k){
     counter++;
     if (counter>*sizeofLCS)
     *sizeofLCS=*sizeofLCS+1;
    }
   else counter=0;
}
if (*sizeofLCS>0) {*sizeofLCS=*sizeofLCS+1; printf("LCS equal: %d\n",*sizeofLCS);}
if (arraySize==0) return-1;
else if (arraySize==0||arraySize>10) {printf("Array size out of range\n"); return -2;}
else if (*sizeofLCS==0) {printf("There is no Consecutive Subsequence\n"); return -3;}
else return 0;
}
