// ------------------------- 執行時要把其他檔案的main註解掉 ------------------

// gcc -o 4.16 4.16_Multithreaded.c
// ./4.16

//#include <pthread.h>  // All Pthreads programs must include this header file.
//#include <stdio.h>
//
//// these data are shared by the thread(s)
//int n, i;
//// 要把print放在main裏面的話，這些data要改成global
//int min, max;
//float avg;
//
///* Threads */
//void *average(int arr[]) {
//    int sum = 0;
////    float avg;
//    for (i=0;i<n;i++) sum += arr[i];
//    avg = sum / n;
////    printf("\nThe average value is %f", avg);
//    pthread_exit(0);  // Thread termination
//}
//void *minimum(int arr[]){
//    min = arr[0];
//    for (i=0;i<n;i++) {if (min>arr[i]) min = arr[i];}
////    printf("\nThe minimum value is %d", min);
//    pthread_exit(0);
//}
//void *maximum(int arr[]){
//    max = arr[0];
//    for (i=0;i<n;i++) {if (max<arr[i]) max = arr[i];}
////    printf("\nThe maximum value is %d", max);
//    pthread_exit(0);
//}
//
//int main(int argc, char *argv[]) {
//    /* the thread identifier */
//    pthread_t tid1, tid2, tid3;
//    pthread_attr_t attr;  /* set of attributes for the thread */
//
//    printf("Please enter your numbers:\n");
//    scanf("%d", &n);
//    printf("\n");
//    int arr[n];
//    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
//
//    /* get the default attributes */
//    pthread_attr_init(&attr);  // Use default thread attributes
//
//    /* create the thread */
//    pthread_create(&tid1, &attr, average, arr);
//
//    /* now wait for the thread to exit */
//    pthread_join(tid1, NULL);
//
//    pthread_create(&tid2, &attr, minimum, arr);
//    pthread_join(tid2, NULL);
//
//    pthread_create(&tid3, &attr, maximum, arr);
//    pthread_join(tid3, NULL);
//
//    printf("The average value is %f\n", avg);
//    printf("The minimum value is %d\n", min);
//    printf("The maximum value is %d\n", max);
//}
