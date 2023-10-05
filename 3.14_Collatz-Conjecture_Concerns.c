// ------------------------- 執行時要把其他檔案的main註解掉 ------------------

// gcc -o hw1-1 hw1-1.c -lrt (lrt可不加）
// ./hw1-1

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// ----------------- Method_1 -----------------

//int main() {
//   int n;
//
//   pid_t pid;
//
//   printf("Please enter a number greater than 0: \n");
//   scanf("%d", &n);
//
//   pid = fork();  // fork another process
//
//   if (pid < 0) {
//       fprintf(stderr, "Fork Failed\n");
//       return 1;  // exit(1);
//   }
//   else if (pid == 0) {  // child process
//       if (n <= 0) {
//           printf("positive integer is needed!");
//           return 0;
//       }
//       printf("%d ", n);
//       while (n != 1) {
//           if (n % 2 == 0) {n /= 2;}
//           else if (n % 2 == 1) {n = 3 * n + 1;}
//           printf("%d ", n);
//       }
//   }
//   else {  // parent process
//       wait(NULL);  // parent will wait until child to complete
//       printf("Child Complete\n");
//   }
//   return 0;  // exit(0);
//}


//// -------------------- Method_2: Call Collatz_Conjecture_Concerns function -------------------


//int Collatz_Conjecture_Concerns(int n) {
//    if (n <= 0) {
//        printf("positive integer is needed");
//        return 0;
//    }
//    while (n != 1) {
//        if (n % 2 == 0) {n /= 2;}
//        else if (n % 2 == 1) {n = 3 * n + 1;}
//        printf("%d ", n);
//    }
//}
//
//int main() {
//    int n;
//
//    pid_t pid;
//
//    printf("Please enter a number greater than 0 to run the Collatz Conjecture.\n");
//    scanf("%d", &n);
//
//    pid = fork();
//
//    if (pid < 0) {
//        fprintf(stderr, "Fork Failed\n");
//        return 1;
//    }
//    else if (pid == 0) {
//        Collatz_Conjecture_Concerns(n);
//    }
//    else {
//        wait(NULL);
//        printf("Child Complete\n");
//    }
//    return 0;
//}


//// -------------------- Method_3(do-while): ---------------------------


//int main() {
//    int n=0;
//
//    pid_t pid;
//
//    do {
//        printf("Please enter a number greater than 0 to run the Collatz Conjecture.\n");
//        scanf("%d", &n);
//    } while (n <= 0);
//
//    pid = fork();
//
//    if (pid == 0) {
//        printf("%d ",n);
//        while (n!=1) {
//            if (n%2 == 0) {n = n/2;}
//            else if (n%2 == 1) {n = 3 * n + 1;}
//            printf("%d ",n);
//        }
//    }
//    else {
//        wait(NULL);
//        printf("Child Complete.\n");
//    }
//    return 0;
//}