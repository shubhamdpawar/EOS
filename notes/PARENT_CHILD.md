# #PARENT CHILD

A PROCESS HAS its OWN SUBROUTIN THAT SUB ROUTIN WE CALLED CHILD AND MAIN PROGRAM WE CALLED PARENT EG:the crome browser is parent and the tabs are child of that chrom browser.

by using FORK we can make a chilld child is reflaction of parent .the parent adress spce is differnt and child adress space s differant and parent and child are differant from each other in the sense they cannot ascess each others data.

![image-20211202234244351](/home/shubham/.config/Typora/typora-user-images/image-20211202234244351.png)

in thebelow program we are going to aunderstand functionality of FORK,basicaly fork is used for  creates  a new process by duplicating the calling process.  The  new process is referred to as the child process.  The  calling  process is referred to as the parent process. in below program we used the fork header fies,program will start exicutiong after main ,the return type of fork is PID_T process id ,we used print f statement "before fork" will exicute once ,we called fork on line number 9 ,so after calling fork ,fork will make new process,that is child and parent so now printf statement "after fork"will exicute twice 1 time for parent 2nd time for child.

![image-20211204031513375](/home/shubham/.config/Typora/typora-user-images/image-20211204031513375.png)

output:

![image-20211204032510617](/home/shubham/.config/Typora/typora-user-images/image-20211204032510617.png)

man page of fork,here we can see which heADER FILE WE HAVE TO ADD AND what will be the return type of fork.

![image-20211204031345353](/home/shubham/.config/Typora/typora-user-images/image-20211204031345353.png)

a small modificatio in program to see the pid number.in below program after fork will print two time one is for child and another one for parentletss see

![image-20211204032908540](/home/shubham/.config/Typora/typora-user-images/image-20211204032908540.png)

here is output of program  now we have to understand which id is get print for child and which id printed for parent .take look on man page of fork here mention that  VALUE On success, the PID of the child process is returned in the parent, and 0  is returned in the child.  On failure, -1 is returned in the parent, no child process is created, and errno is set appropriately.

![image-20211204032809182](/home/shubham/.config/Typora/typora-user-images/image-20211204032809182.png)

after sucess of fork ,the process id of child return to parent means the id of child copy in parent ,and in child get 0 value so we can see in output the after fork 0 is printed for child and after fork 454926 is printed for parent.![image-20211204032448553](/home/shubham/.config/Typora/typora-user-images/image-20211204032448553.png)

 and again some channg in program,in thise program we make ,here after fork we took the pid of child  how?when controll go in if statement means in  0 then we are in child space we can write whatewer code for child. and in else part we can add code for parent.for now we added code for getting pid number of child and parents.

![image-20211204035156441](/home/shubham/.config/Typora/typora-user-images/image-20211204035156441.png)

output:here we can see parent id and child is differant butobvious because both have differant adress space,grnd parent  id of perent is differant is also ok but how child parent id is differant?as i think it should be parent process id becase child born from parent wht u think? the answer is when parent complite exicution and child still exicuting that time parent  get killed by system and child get i**nherited** by the systeamd and noew the parent of that child is systemd 8156 is system d process id,and not always systeam d  thise case happens only when parent killed before child.                                                                                                                                                                                                                        i                                               in second picture we can see child ppid is same as parent pid 456457, in thes case parent not killed before child 

![image-20211204040019728](/home/shubham/.config/Typora/typora-user-images/image-20211204040019728.png)

2nd time exicution of program o/p:

![image-20211204041458828](/home/shubham/.config/Typora/typora-user-images/image-20211204041458828.png)

ther is second case in which child dies first,in thise case after fork parent alive and child get killed first now parent want some details or get status about his child so how he get that status? so what os do is it didnt killed thi child os puts child in zombie state with deallocated resorses resorces .

![image-20211204042818245](/home/shubham/.config/Typora/typora-user-images/image-20211204042818245.png)

to implement zombie state we make modification in progam,we added sleep in program for longlasting exicution of parent and after 10milisecond sleep we give statement to print.that way child exicute fast and get killed by the os and we know thart if the child exicuteted before the parent os put child on zombie state.

**![image-20211204043852018](/home/shubham/.config/Typora/typora-user-images/image-20211204043852018.png)**

output:

![image-20211204044722456](/home/shubham/.config/Typora/typora-user-images/image-20211204044722456.png)



why os put in ZOMBIE STATE?

because it might happent parrent make querry letter point of time that get me thDemand paging follows that pages should only be brought into memory if the executing process demands them.e status of my child is it exit sucessfully or wether it crashed and then exited what is status of exitfor thise reson child put in zombie state until parent complete process.& deallocatedd resorces.and only few details maintained by os

APLICATION:able to exicute multiple task when we used parent child.taking a siplistic example if we have a big file in which we have to find one intruction if we have 2 cpu then parent stat to find from up to down and child starts from low to high this way it take less time ,this functionality aslo work when we have single cpu we can use  perent and child in speudo parlally manner.

another example: if we want to serve multiple clients simutaniously we can can use parent child.![image-20211204045940308](/home/shubham/.config/Typora/typora-user-images/image-20211204045940308.png)

**demand paging**:Demand paging follows that pages should only be brought into memory if the executing process demands them.

**copy on write(cow)** 

**INTER PROCESS COMMUNCATION:**

INT HIS I HAVE TOPASS DATA FROM PROCESS 1 TO PROSESS 2 THAT COMMUNICATION WE CALLED IPC(INTER PRCESS COMMUNICATION).

TO COMMUNCATE FROM PARENT TO CHILD WE USED **PIPE** ,LETS UNDESTAND PIPE BY TAKING REAL WORLD PIPE PIPE WE USED FOR TRANSMETT WATER FROM ANE POINT TO ANOTHE POINT IN THAT CASE ONE END OF PIPE IS TRANSMITTER AND ANOTHER ONE IS RECIVER SAME WAY WATER=DATA IN IPC PIPE WHER WE TRANSMITT DATA THAT END WE CALLED INPUT ANSD RECIVER END WE CALLED OUTPUT.AND PIPE IS UNIDERECTIONAL COMPONANT DATA CAN FLOW IN ONLY ONE DIRECTION

**pipe**

![image-20211204121744997](/home/shubham/.config/Typora/typora-user-images/image-20211204121744997.png)

for writing program on pipe we have to add header file of pipe,to the pipe we have to pass array of 2 integers

 int pipe(int pipefd[2]);   also we cn see on man page  pipefd[0] refers  to the read end of the pipe.  pipefd[1] refers to the write end of  the pipe.  lets write a program for pipe.

![image-20211204141432337](/home/shubham/.config/Typora/typora-user-images/image-20211204141432337.png)

we write thise program for sending data from parent to child ,lets illustrate program here we used pid id which is return type of fork  and in ipe we used 2 file discripter as we can see man page of pipe it needs 2 file desripter.                         **int pipe2(int pipefd[2], int flags);**  by int fd[2] we assign two array ,by pipe(fd) pipe is created , by using fork we make child here we set child as a reciver and parent as transmitter ,lets take look on transmitter we want t transmitt data means we have to write data in one end for writing data we used write command ,in which we used fd1 which made pipefd[1] refers to the write end of  the pipe.   Data  written  to  the write end of the pipe is buffered by the  kernel until it is read from the read end of  the  pipe.  now we give the bubber what we have to send in this buffer we give a text which is DESD ,and then count of that buffer                                                                                                                                                       now take look on child in child we give read command which we give fd 0 pipefd[0] refers
to the read end of the pipe. ,buffer ,and size of buffer. and we innitialize 16 byte.

![image-20211204150150216](/home/shubham/.config/Typora/typora-user-images/image-20211204150150216.png)

in abovw program we clase the fd 1 for child because it was not in use aswe doing read opration which is depend upon fd 0,similarly closed fd 0 in parent bcz we doing write opration on parent that way we decreesing the extra requirment of resorces.     

till now we see pipe which transfers data from  parent to child and child to parent.now we going to see how we transfer data to one parent to another parent.for performing thise kind of data transfer we have concept we called **ipc named pipes**.withought any relation like child to parent we can transmitt data to one parent to another parent and its also known as **fifos** 

here we created a fifo file by using **mkfifo -m600 desdfifo** command in which mkfifo we thelling make a fifo file by -m600 we tell which kind of permission we have to give thise file and last one is desdfifo is name of our file. wencan see in below image prw ----------- here p stands for pipe 

![image-20211204152011370](/home/shubham/.config/Typora/typora-user-images/image-20211204152011370.png)

we put thise two processes in desdfifo tor transmitting data![image-20211204152515611](/home/shubham/.config/Typora/typora-user-images/image-20211204152515611.png)

![image-20211204153247077](/home/shubham/.config/Typora/typora-user-images/image-20211204153247077.png)

here is process p1 and and another is p2 in p1 process we open the file desdfifo in write only mode,when get open  we writing in fd then what we have to write and then count then close the file descriptor.                                                                      similarly in process p2 open desd fifo in readonly mode read fd,then used buffer in which we are going to stire the recived massage and close pogram.

in above program we writing on desdinfo and in process p2 we reading data from desdfifo.in short we transmitting data from p1 to p2.

in below program we added pintf for showing content of buffer.

![image-20211204153206815](/home/shubham/.config/Typora/typora-user-images/image-20211204153206815.png)

here if we exicute  p2 then process go in waiting mode , in p2 we give read opration if p1 not exicuteed no chance of getting output

![image-20211204162348284](/home/shubham/.config/Typora/typora-user-images/image-20211204162348284.png)

when exicute both

![image-20211204162547401](/home/shubham/.config/Typora/typora-user-images/image-20211204162547401.png)

process state digram:

![image-20211204165622441](/home/shubham/.config/Typora/typora-user-images/image-20211204165622441.png)

basic state common across rtos and os.1.create state :process is created here allocate adress space,in thise state we are giving all resorces required for exicute.once orocess created it goes in ready state.

2 ready state:   means im now ready to exicute on cpu,for that there is a ready table and there could be many process in ready state.

running state:when cpu is avalble that time redy state program come in running statete ,when cpu is uniprocessor then in running state only one process is running, suppose 1 process finishesh exicution then process goes in exit state.and all resorces will be deallocate,now os will go and reffer to ready state and pic one program and put in running state.and process is exicting and os said i will give 100ms to exicute after that time os bring running process and put in ready state gtake another program from ready state and start exicuting for 100ms after that time os pick running opration and put back in ready state pick another program from ready state and strat exicution again,we can share running time with ready table program.

waiting state:suppose process in running and that time we get  scan f function ,which we getting from the user so that instead of time it put to waiting state.when runnig process requerd some data from external world or waiting for some event to happen that time process go in waiting state,after getting data from user or external world thise prpcess get back to ready state and then go in running state whe cpu is free,when process is in waiting state the process can go directly to exit state.eg:when user inted og giving input if he give cntroll+c is directly go in exit withought going in goin in running state.

command : **kill -9 process id**  i can kill the process





