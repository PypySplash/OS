// ------------------------- 執行時要把其他檔案的main註解掉 ------------------

// gcc -o hw1-2 hw1-2.c
// ./hw1-2

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <fcntl.h>    // For 0_* constant
//#include <sys/stat.h>
//#include <sys/mman.h> // For shm_open
//#include <sys/types.h>
//#include <unistd.h>   // For ftruncate
//#include <sys/wait.h> // For wait
//
//int main() {
//    // First create a shared memory area.
//    const int SIZE = 4096;
//    const char *name = "OS";
//    const int BUFFER_SIZE = 10;
//
//    int shm_fd;  // shared memory file descriptor
//    void *ptr;   // pointer to shared memory object
//
//    shm_fd = shm_open(name,O_CREAT | O_RDWR,0666);
//
//    ftruncate(shm_fd,SIZE);  // Truncate the file
//
//    ptr = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shm_fd,0);  // Map the file into memory
//
//    // And now we create the process
//    // 開一個buffer，先在buffer裡面寫數據，再通過sprintf一次性將buffer的內容寫入ptr，避免ptr每次都要移動。
//    // 透過移動一開始指向buffer首地址的指針比移動ptr安全。
//    // sprintf每次會返回寫入的長度（不包括\0字符），這也給我們移動指向buffer的指針帶來了方便。
//    int n;
//
//    pid_t pid;
//
//    printf("Please enter a number greater than 0: \n");
//    scanf("%d", &n);
//
//    pid = fork();
//
//    if (pid < 0) {
//        fprintf(stderr, "Fork Failed\n");
//        shm_unlink(name);
//        return 1;
//    }
//    else if (pid == 0) {                              // child process
//        char buffer[BUFFER_SIZE];
////        memset(buffer,0,sizeof(char)*BUFFER_SIZE);  // Set buffer to 0
//        char *buffer_temp = &buffer[0];                  // Point to the head of the buffer
//        buffer_temp += sprintf(buffer_temp,"%d ",n);        // Move n of buffer_p, which n is the length of written data
//        if (n <= 0) {
//            printf("positive integer is needed!");
//            shm_unlink(name);
//            return 0;
//        }
//        while (n != 1) {
//            if (n % 2 == 0) {n /= 2;}
//            else if (n % 2 == 1) {n = 3 * n + 1;}
//            buffer_temp += sprintf(buffer_temp,"%d ",n);
//        }
//        sprintf(ptr,"%s",buffer);  // Copy buffer to ptr, also you can use memcpy to get higher efficiency*/
//        printf("The data to shared memory has written.\n");
//    }
//    else {  // Parent process
//        wait(NULL);  // wait until Child process completed
//        printf("Reading the shared memory\n");
//        shm_fd = shm_open(name,O_RDONLY, 0666);            // O_RDONLY = READ_ONLY
//        ptr = mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);  // PROT_READ = READ_ONLY
//        printf("%s\n",(char *)ptr);
//        shm_unlink(name);
//        printf("Child Complete\n");
//    }
//}
