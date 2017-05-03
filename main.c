/*================================================================================================*/
/* The project for algorithm test. */
/*================================================================================================*/




/*================================================================================================*/
/* Definition */
/*================================================================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*================================================================================================*/




/*================================================================================================*/
/* Definition */
/*================================================================================================*/


#define TEST_AREA 1


/*================================================================================================*/




/*================================================================================================*/
/* Function definition */
/*================================================================================================*/


int binarySearch(int, int,int* ,int);
void sequenceMerge(int*, int, int*, int*);
void dataMerge(int* , int);


/*================================================================================================*/



/*================================================================================================*/
/* Lowercase changing */
/*================================================================================================*/

void lowercaseChg(char* upperCase)
{
    int strIndex = 0;
    while(upperCase[strIndex]!='\0'){
            if(upperCase[strIndex]>='A' && upperCase[strIndex]<='Z'){
            printf("%c", upperCase[strIndex] - 'A' + 'a');
            } else {
                printf("%c", upperCase[strIndex]);
            }
            strIndex++;
    }
}

/*================================================================================================*/





/*================================================================================================*/
/* Hanoi ???*/
/*================================================================================================*/

void hanoi(int dishNum, char posFrom, char posBy, char posTo)
{
    if(dishNum==1){
        printf("Move sheet %d from %c to %c\n", dishNum, posFrom, posTo);
    } else {
        hanoi(dishNum-1, posFrom, posTo, posBy);
        hanoi(dishNum, posFrom, posBy, posTo);
        hanoi(dishNum-1, posBy, posFrom, posTo);
    }
}


/*================================================================================================*/



/*================================================================================================*/
/* Binary search */
/*================================================================================================*/


int binarySearch(int lowIndex, int highIndex, int* dataSet, int targetNum)
{
    int mid = (lowIndex + highIndex) / 2;
    if(dataSet[mid]==targetNum) return mid;
    else if(dataSet[mid]<targetNum) binarySearch(mid+1, highIndex, dataSet, targetNum);
    else if(dataSet[mid]>targetNum) binarySearch(lowIndex, mid-1, dataSet, targetNum);
    else return -1;
}


/*================================================================================================*/




/*================================================================================================*/
/* Divide and conquer */
/*================================================================================================*/


void sequenceSeparate(int* dataSet, int dataSize, int* uData, int* dData)/* Separate sequence into two sub-sequence */
{
    int mid = dataSize/2;
    int index = 0;
    int *dataBuffer = (int*)malloc(sizeof(int)*dataSize);
    memcpy(dataBuffer, dataSet, dataSize);
    for(;index<mid;index++)dData[index] = dataSet[index];
    for(;index<dataSize;index++)uData[index-mid] = dataSet[index];
    free(dataBuffer);
}


void dataMerge(int *dataSet, int dataSize)
{
    if(dataSize>1){
        int sizeBuf = dataSize;
        int *uData = (int*)malloc(sizeof(int)*(dataSize/2));
        int *dData = (int*)malloc(sizeof(int)*(dataSize/2));
        sequenceSeparate(dataSet, sizeBuf, uData, dData);
        sizeBuf/=2;
        dataMerge(uData, sizeBuf);/* The disappearing of local variables haven't been fixed yet */
        dataMerge(dData, sizeBuf);
        sequenceMerge(dataSet, dataSize, uData, dData);
    } else {
        printf("%d\n", dataSet[0]);
    }
}


void sequenceMerge(int* dataSet, int dataSize, int* uData, int* dData)/* Merge and arrangement (BUG) */
{
    int uIndex = 0;
    int dIndex = 0;
    int sIndex = 0;

    while(sIndex<dataSize)
    {
        if(sIndex<(dataSize/2)-1){

            if(dData[dIndex]<dData[dIndex+1]){
                dataSet[sIndex] = dataSet[sIndex] ^ dataSet[sIndex+1];
                dataSet[sIndex+1] = dataSet[sIndex] ^ dataSet[sIndex+1];
                dataSet[sIndex] = dataSet[sIndex] ^ dataSet[sIndex+1];
            } else {}

            sIndex++;
            dIndex++;
        } else {

            if(uData[uIndex]>uData[uIndex+1]){
                dataSet[sIndex] = dataSet[sIndex] ^ dataSet[sIndex+1];
                dataSet[sIndex+1] = dataSet[sIndex] ^ dataSet[sIndex+1];
                dataSet[sIndex] = dataSet[sIndex] ^ dataSet[sIndex+1];
            } else {}

            sIndex++;
            uIndex++;
        }
    }
}


/*================================================================================================*/




/*================================================================================================*/
/* Bobble sort */
/*================================================================================================*/


void bobbleArrg(int* dataSet, int dataSize)
{
    int indexPos = 0;
    int indexTar = 0;
    while(indexPos<dataSize){
        indexTar = indexPos;
        while(indexTar<dataSize){
            if(dataSet[indexTar]>dataSet[indexTar+1]){
                dataSet[indexTar] =  dataSet[indexTar] ^ dataSet[indexTar+1];
                dataSet[indexTar+1] =  dataSet[indexTar] ^ dataSet[indexTar+1];
                dataSet[indexTar] =  dataSet[indexTar] ^ dataSet[indexTar+1];
            } else {}
            indexTar++;
        }
        printf("Bubble sequence = %d\n", dataSet[indexPos]);
        indexPos++;
    }
}


/*================================================================================================*/




/*================================================================================================*/
/* Main program */
/*================================================================================================*/


int main()
{
    int dataSize = 8;
    int testData[8] = {1, 0, 4, 3, 6, 5, 8, 7};
    char* testChar = "TesT StrinG";
    /*
    int searchNum = 4;
    int searchResultIndex = binarySearch(0, 6, testData, searchNum);
    if(searchResultIndex<0)printf("Error.\n");
    else printf("Number in index %d and number is %d\n", searchResultIndex, testData[searchResultIndex]);
    bobbleArrg(testData, dataSize);

    dataMerge(&testData, dataSize);
    dataSize--;
    for(;dataSize>=0;dataSize--)printf("Data output : %d\n", testData[dataSize]);
    */
    lowercaseChg(testChar);

    return 0;
}


/*================================================================================================*/




/*================================================================================================*/
/* EOF */
/*================================================================================================*/
