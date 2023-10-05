// ------------------------- 執行時要把其他檔案的main註解掉 ------------------

// gcc -o Q2 Q2.c
// ./Q2

//#include <pthread.h>  // All Pthreads programs must include this header file.
//#include <stdio.h>
//#include <stdlib.h>
//
///* structure for passing data to threads */
//typedef struct {
//    int start;
//    int end;
//} parameters;
//
//int i, j;
//int OriginList[10] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};
//int SortedList[10];
//
//void *Sort(void *data) {
//    parameters *temp = (parameters *)data;
//    int swap;
//    for (i=temp->start; i<=temp->end; i++) {
//        for (j=i; j>0; j--) {
//            if (OriginList[j] < OriginList[j-1]) {
//                swap = OriginList[j];
//                OriginList[j] = OriginList[j-1];
//                OriginList[j-1] = swap;
//            }
//        }
//    }
//    pthread_exit(0);
//}
//void *MergeSort(void *data) {
//    parameters *temp = (parameters *)data;
//    int lo = temp->start, hi = temp->end;
//    int mid = (lo + hi) / 2;
//    i = lo, j = mid + 1;
//    for (int k=lo; k<=hi; k++) {
//        if      (i > mid) SortedList[k] = OriginList[j++];
//        else if (j > hi)  SortedList[k] = OriginList[i++];
//        else if (OriginList[j] < OriginList[i]) SortedList[k] = OriginList[j++];
//        else SortedList[k] = OriginList[i++];
//    }
//    pthread_exit(0);
//}
//
//int main() {
//    parameters *data = (parameters *) malloc(sizeof(parameters));
//    data->start = 0;
//    data->end = 9;
//    parameters *data2 = (parameters *) malloc(sizeof(parameters));
//    data2->start = 0;
//    data2->end = 4;
//    parameters *data3 = (parameters *) malloc(sizeof(parameters));
//    data3->start = 5;
//    data3->end = 9;
//    /* Now create the thread passing it data as a parameter */
//    pthread_t tid0, tid1, tid2;
////    pthread_attr_t attr;
//
//    printf("Original List: \n");
//    for (i=data->start; i<=data->end; i++) printf("%d ", OriginList[i]);
//    printf("\n");
//    // 下面attributes的地方放&attr就會失敗，原因尚未釐清。
//    pthread_create(&tid0, NULL, Sort, (void*)data2);
//    pthread_create(&tid1, NULL, Sort, (void*)data3);
//    pthread_join(tid0, NULL);
//    pthread_join(tid1, NULL);
//    pthread_create(&tid2, NULL, MergeSort, (void*)data);
//    pthread_join(tid2, NULL);
//
//    printf("Sorted List: \n");
//    for (i=data->start; i<=data->end; i++) printf("%d ", SortedList[i]);
//    printf("\n");
//}
