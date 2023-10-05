// gcc ____.c -o cp
// echo "______" > input.txt (或是直接打開txt進行編輯，若直接打開編輯則不需要這行）
// ./cp input.txt copy.txt
// cat copy.txt (可看copy.txt的內容）

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
//#define BUFFER_SIZE 50
//#define READ_END 0
//#define WRITE_END 1
//
//int main(int argc, char* argv[]) {  // input char* array
////    char write_msg[BUFFER_SIZE] = "Greetings";
//    char read_msg[BUFFER_SIZE];
//    int fd[2];  // 長度2
//    pid_t pid;
//
//    // create a pipe
////    pipe(fd);  // 這行不需要
//    if (pipe(fd) == -1) {
//        fprintf(stderr, "Pipe failed");
//        return 1;
//    }
//
//    if (argc != 3) {
//        printf("Need 2 parameters");
//        return 1;
//    }
//
//    int fileOpen = open(argv[1], 0);
//    int targetFile = open(argv[2], O_RDWR|O_CREAT|O_APPEND, 0666);
//
//    if (fileOpen == -1 || targetFile == -1) {
//        printf("File can NOT be opened");
//        return 1;
//    }
//
//    pid = fork();
//
//    if (pid < 0) {
//        fprintf(stderr, "Fork failed");
//        return 1;
//    }
//    if (pid == 0) {  // child process
//        close(fd[WRITE_END]);
//        while (read(fd[READ_END], read_msg, sizeof(read_msg)) > 0) {
//            write(targetFile, read_msg, strlen(read_msg));  //Writing to the target fileOpen
//        }
//        printf("read: %s\n", read_msg);
//        close(fd[READ_END]);
//        close(targetFile);
//    } else {  // parent process
//        close(fd[READ_END]);
//        printf("parent sending message\n");
//        // code to read from a text file
//        while (read(fileOpen, read_msg, sizeof(read_msg)) > 0) {
//            write(fd[WRITE_END], read_msg, sizeof(read_msg));
//            memset(read_msg, 0, BUFFER_SIZE);
//        }
//        close(fd[WRITE_END]);
//        close(fileOpen);
//        wait(NULL);
//    }
//    return 0;
//}
