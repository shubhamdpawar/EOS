# MEMORY ALOCATION

MEMORY ALLOCATION IS COMPLEX PROCEDURE IN OS.

memory allocation in ram,

RAM contains adress space,in which .text .data .bss heap stack are include.for each process or program or application requred a adress space for exicution of program.

same way for exicution of oprating syteam program also required adress space.we can see in below diagram basicaly there are two space kernal space and user space. when the systeam is in reset mode os kernal  stored in flash or hdd when system set or start the fisrt opration perform on flash or hdd from this flash kernal load in RAM.in ram for kernal has a seprate space we called that space as kernal space.kernal space also containing adress space.and another is user space in which all user program get exicuted.there are mutiple application has to exicute so oprating systeam make a seprate adress spaces for each aplication or process.that aplication process contains .text .data .bss heap and stack sections.due to there are seprate adress space for each process or aplication any aplication cannot acess the information from another application.

![image-20211201184346107](/home/shubham/.config/Typora/typora-user-images/image-20211201184346107.png)



lets take look on user space .

for simplicity we have two program files A1  A2 in HDD when we give command ./filename os make a **PCB** **datastructure** **(PROCESS CONTROLL BLOCK) CONTAINS 8KB SPACE** for that process in which it saves the start adress and the lenght of the application and now it is a process, so it will add PID no. that three things it will do for A1 and same process OS will do for A2 also build a stucture boath are contains differant address spaces .

####      OS will not allow to access another scop adress like we give a pointer ptr =0x003e if we dereffrance ptr* then  os kills the process. and give us <u>**segmentation error*</u>*

we getting segmentation falt in thise program bcz we added a ponter which is pointing to the null location out of process adress.

![image-20211201194052697](/home/shubham/.config/Typora/typora-user-images/image-20211201194052697.png)

![image-20211201194558803](/home/shubham/.config/Typora/typora-user-images/image-20211201194558803.png)

here we can see in blue line segmentation fault occurs . and it is showing that ptr [rax]

here is a good aplication which make our life easy which is gdb-gef to perform exicution throug this app we have to give that same command which we can see in below image.

and while compiling program gcc -o segmntation segmentation.c  -g

add always -g which gives a symballyc represenTAtion .  

![image-20211201195227076](/home/shubham/.config/Typora/typora-user-images/image-20211201195227076.png)

# systeam calls

every device or file, computer treated as file.

there are some imporant calls in device drivers open read write and close.

lets see open analogy.

in thise we have to givethis header files as a aurgument we haVE to give path name or file name  and flags also according to image we know that the retern tytpe of open is an int

![image-20211202093759588](/home/shubham/.config/Typora/typora-user-images/image-20211202093759588.png)

flags :give a instruction that what we have to do with file?if we wanrt read a file then o_readonly,similarly for write and read write.as we can see in below image.

![image-20211202094145471](/home/shubham/.config/Typora/typora-user-images/image-20211202094145471.png)

we took o_writeonly now  we have to take look on write functionality. **command:man -k write** it will give all write functionality which we have to use we have to decide from these page only.like we have options write(1):send a massage to another user write(2):write to a file discriptor. as we are performing opration on file so we used write (2)  how we will see **cmmand :MAN 2 write** 

![image-20211202100316817](/home/shubham/.config/Typora/typora-user-images/image-20211202100316817.png)

we have to add thise unistd headerfile and in aurgument have to give bufer(what  we have write in file ) and count also.

by using all abovee information we created a below program.

![image-20211202102706447](/home/shubham/.config/Typora/typora-user-images/image-20211202102706447.png)

 librarys are stores in user space.os implement the systeam calls .in these program we write  by using open command is state that go in kernal space exicute that function and  by using close (fd(file dicrimiator )) coming back to user space.in above program we used requred header files in main function we give return type of fd is int which is mention in man page. what happning in thise program is we saying in write funtion where we have to save program which is fd.and above line of write  we innitialize fd to desd.text that means any data saves in fd which is indirectly save in desd.text file .now come back to write command where we give buffer in which we gave which data  we want to store in desd.text file also give the lenghth of that data.then use close function which telling the os.lets go back to the user space from kernal space.in thise program we did a mistake and every devloper should avoid that.

1.whatewer is return type we didnt validate it.wether is corrct or wrong .we can see the return type of the open we will get new file dicripter or there is error it will give -1.so we should handle the error by giving if statement in program.

![image-20211202110302936](/home/shubham/.config/Typora/typora-user-images/image-20211202110302936.png)

we icluded if sttatement if the flag s -1 then shuld print erro.idealy it should exit from process at that point of tyme so we can use **EXIT**  BY USING macro.

![image-20211202110859382](/home/shubham/.config/Typora/typora-user-images/image-20211202110859382.png)

![image-20211202111218612](/home/shubham/.config/Typora/typora-user-images/image-20211202111218612.png)

we used lib header file exit function.it will come out from program when error occures.so error can cause due to multiple resons we should know why we get the error,which we can achive by using **errno** we can see error cause by ising thise **command :errno --list** each error has a specified number 

to getting that error no we used 1 header file and some modification in program we can see below.

![image-20211202113139263](/home/shubham/.config/Typora/typora-user-images/image-20211202113139263.png)

​                                   output:![image-20211202113423753](/home/shubham/.config/Typora/typora-user-images/image-20211202113423753.png)

we get eror number 2.which states that thers no such file or directory.

we can use preerror function to avoid that long if statement.we get that specifie result by using same functionality.

![image-20211202113645291](/home/shubham/.config/Typora/typora-user-images/image-20211202113645291.png)

as per we get error we will create desd.text file.in case we doesnt have assess to remote machine to create a file.then we have solution for this we can see below

![image-20211202114548655](/home/shubham/.config/Typora/typora-user-images/image-20211202114548655.png)

![image-20211202114705453](/home/shubham/.config/Typora/typora-user-images/image-20211202114705453.png)

permissions should be give to our file in  fd= ()

![image-20211202120838160](/home/shubham/.config/Typora/typora-user-images/image-20211202120838160.png)

![image-20211202120959081](/home/shubham/.config/Typora/typora-user-images/image-20211202120959081.png)

if we want give a read write  permission to user then we should give s_irusr & s_iwusr

![image-20211202121233110](/home/shubham/.config/Typora/typora-user-images/image-20211202121233110.png)

focuse on fd=(    )  are telling here if desd.txt file is present then open in only write mode bt if there is no file then create a file and give the permission to user which is read and write.

# file discripter:

**file discripter is integer value in user space which denotes the open file in kernal space.** **to denote that specific file we need a file discripter number.** now if we want to perform any opration of fd then just have to mention fd number eg: o_ write(fd.no) by thise fd number kernal knows opraation perform on which file.

lets write program to print file disripter. line number 20.

![image-20211202125748351](/home/shubham/.config/Typora/typora-user-images/image-20211202125748351.png)

in below image we can se a library function printf which stored in libc.c in userspace.now printf function have to print the hello world in display and display is hardware high privilage so printf function have to give permission from kernal space  and exicute opration ,,print f library trying to perform output functionality,so now print f fuction iternaly perform system call which is write call **fd=write(1,hello world ,11)**  and why fd is 1? stinput = 0 ,stout = 1 , error= 2 thats why fd is 1.

![image-20211202131701145](/home/shubham/.config/Typora/typora-user-images/image-20211202131701145.png)

read this COW copy on write

blocking api 

non_blocking api's

