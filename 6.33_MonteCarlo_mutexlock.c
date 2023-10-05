// ------------------------- 執行時要把其他檔案的main註解掉 ------------------

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>

#define NUM_POINTS 1000
#define NUM_THREADS 5
int points_inCircle = 0;
pthread_mutex_t mutex;

// generate random points and count the points within the circle
void *points_generated(void *param) {
    /* acquire the mutex lock */
    pthread_mutex_lock(&mutex);
    /*** critical section ***/
    for (int i=0; i<NUM_POINTS; i++) {
        // generate (x,y) 會落在圖中的正方形(-1, 1), (-1, -1), (1, -1), (1, 1)內，*2 - 1確保(x, y)也會有負的座標
        double x = (double)rand() / RAND_MAX * 2 - 1;
        double y = (double)rand() / RAND_MAX * 2 - 1;
        // 計算在圓內的點（點到點距離公式： sqrt(x*2 + y*2) <= 1)
        if (x*x + y*y <= 1) points_inCircle++;  // update the global variable
    }
//    printf("%d\n", points_inCircle);
    /* release the mutex lock */
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {

    // 設定一個隨機種子seed，使得每次產生的隨機數才會不一樣
    // rand()為偽隨機數，每次產生的隨機數會一樣，故需在main裡加srand()，來確保每次產生的隨機數不一樣
    srand(time(NULL));

    /* create (initialize) the mutex lock */
    pthread_mutex_init(&mutex, NULL);  // 把地址傳給它

    /* 以下可用for迴圈來完成(? */
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;
    pthread_t tid5;
    /* Create the threads */
    pthread_create(&tid1, NULL, &points_generated, NULL);
    pthread_create(&tid2, NULL, &points_generated, NULL);
    pthread_create(&tid3, NULL, &points_generated, NULL);
    pthread_create(&tid4, NULL, &points_generated, NULL);
    pthread_create(&tid5, NULL, &points_generated, NULL);
    /* Wait for all threads to complete */
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);

    double pi = 4.0 * points_inCircle / (NUM_POINTS * NUM_THREADS);
    printf("Estimated value of π for %d points and %d threads: %f\n", NUM_POINTS, NUM_THREADS, pi);

    return 0;
}
