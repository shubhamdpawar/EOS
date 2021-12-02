# library functionality

what is library?

library is combination of binary files which contains various  functions like add subutract dft fft

#### when we have to transfer our functions to our colegue then we make a library wich contains that functions which colege wants to add in ther project.

in below diagram we type  in red colour library  which are functions wich we going to send our feind by making library.



**THE STRCPY,PRINTF,SCANF this also a library** and the functionality of thise library at **libc**

also we can create our own library



![image-20211201102622783](/home/shubham/.config/Typora/typora-user-images/image-20211201102622783.png)

how to create library?

make one saprate folder .in that folder add your obj files which contains function or function defination.

![image-20211201103440126](/home/shubham/.config/Typora/typora-user-images/image-20211201103440126.png)



what we did here just adding a command ar -cr libraryname.a add.o sub.o (which functionality we have to add just mention after the .a) at  end we get libarith.c which is our library

![image-20211201103833389](/home/shubham/.config/Typora/typora-user-images/image-20211201103833389.png)

when get library created we have to add the header file which contain the prototype of the funtion that way reciver can understand what kind argument have to pass and how many. withought header file reciver cannot identifi what kind of aurgument he has to pass.always add header file with library.

below picture is our header file

after ![image-20211201111619813](/home/shubham/.config/Typora/typora-user-images/image-20211201111619813.png)

till now we have headerfile which contains prototype of fuction or some macro.in library we have defination of function now reciver has to devlope his own project to use function which we send to him.

so now assume his making a program to for  addition in that case he wants to use only one function which is addition 

now he wants to write a program which shows in below picture.

![image-20211201112528442](/home/shubham/.config/Typora/typora-user-images/image-20211201112528442.png)

### we can see in above picture reciver created his own main fiction in which he used a add function in that add function he give aurgument is 3 diffenant number ,how he get know?he see our heder file from that file he get know what kind of aurgument he has to pass.also he added arith.h header file 

so now we have header file proj.c main and in library function defination so now we are going to compile the program by 

command:gcc -o proj proj.c -llibarith -L.

in this command by using small -l we are going to say include thise library file and -L. is used for where your lib file located.  the dot . is the location if we are in current reposatory we using dot . or if our file belong from somwere else then at dot we will include the paath of our library location.



![image-20211201093912383](/home/shubham/.config/Typora/typora-user-images/image-20211201093912383.png)

  there are two types of library static and dynymic library 

static liberary extension is .a    and dynymic library extension is .so(shared object)

how we create static library:

![image-20211201103833389](/home/shubham/.config/Typora/typora-user-images/image-20211201103833389.png)



how we create dynymic library:

<u>**command: gcc -o librith.so -shared -FPIC add.c sub.c**</u>

![image-20211201121401267](/home/shubham/.config/Typora/typora-user-images/image-20211201121401267.png)

.so :shared object

-fPIC: position indipendant code thise we used bcz the library where stored in memory we didnt know.

-shared: to say that i have genrate shared library

![image-20211201131259950](/home/shubham/.config/Typora/typora-user-images/image-20211201131259950.png)

if u add ./prij it will give a error saying cannot open shared file to overcome this error we use commond 

export LD_LIBRARY_PATH=.  //WE ARE TELLING TO SHELL IF U LOOKING FOR LIBRARY U GET IN THIS PATH

WHATT HAPPENS HERE.

when (.so) file exicuted first exicute the bibrary file then exicute proj file in synymic memory.   proj.c is a refferance of dynymic file.

  what happend with static memory in prog file contains library it self

![image-20211201132535582](/home/shubham/.config/Typora/typora-user-images/image-20211201132535582.png)

![image-20211201133143093](/home/shubham/.config/Typora/typora-user-images/image-20211201133143093.png) 

static library                                                                                                      dynymic library

in static binary contais library in itself                                    in dynymic binary contais a reffrance of function     

![image-20211201133856251](/home/shubham/.config/Typora/typora-user-images/image-20211201133856251.png)

### staic lib                                                                                                                                          dynymic lib



library each binary contains library                                                           in dynymic allbinary contais same library                                 

even if binary contains same function.......                                                if binary going to use same function.



![image-20211201164151114](/home/shubham/.config/Typora/typora-user-images/image-20211201164151114.png)





# interview questions:

explain the process of library configuration.

explain what is dynymic lib and stic lib?

differance between dynymic and static lib.

# program to process conversion

![image-20211201144257755](/home/shubham/.config/Typora/typora-user-images/image-20211201144257755.png)

for looking entire process of systeam use comand 

<u>**command:  ps -el**</u>

**command:pstree //it shows complete process tree**



![image-20211201151146951](/home/shubham/.config/Typora/typora-user-images/image-20211201151146951.png)

### 
