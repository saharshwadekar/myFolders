Saharshwadekar ~ % cal 11 2023   
   November 2023      
Su Mo Tu We Th Fr Sa  
          1  2  3  4  
 5  6  7  8  9 10 11  
12 13 14 15 16 17 18  
19 20 21 22 23 24 25  
26 27 28 29 30        
                      
Saharshwadekar ~ % date +%d/%m/%y
22/11/23
Saharshwadekar ~ % who           
saharshwadekar   console      Nov 22 13:11 
saharshwadekar   ttys000      Nov 22 13:12 
Saharshwadekar ~ % whoami        
saharshwadekar

=======================================================

Saharshwadekar % ls
Test
Saharshwadekar % ls -a
.		..		.DS_Store	Test
Saharshwadekar % ls -al
total 16
drwxr-xr-x  4 saharshwadekar  staff   128 Nov 22 13:27 .
drwx------+ 7 saharshwadekar  staff   224 Nov 22 13:25 ..
-rw-r--r--@ 1 saharshwadekar  staff  6148 Nov 22 13:27 .DS_Store
drwxr-xr-x  2 saharshwadekar  staff    64 Nov 22 13:27 Test
Saharshwadekar % ls -R
Test

./Test:
Saharshwadekar % touch first.txt
Saharshwadekar % nano first.txt
Saharshwadekar % nano second.txt
Saharshwadekar % cat first.txt
This is First of First Line
Saharshwadekar % cat second.txt
This Second of First Line
Saharshwadekar % cat first.txt second.txt > third.txt
Saharshwadekar % cat third.txt
This is First of First Line
This Second of First Line
Saharshwadekar % rm second.txt
Saharshwadekar % sudo
usage: sudo -h | -K | -k | -V
usage: sudo -v [-ABkNnS] [-g group] [-h host] [-p prompt] [-u user]
usage: sudo -l [-ABkNnS] [-g group] [-h host] [-p prompt] [-U user] [-u user]
            [command [arg ...]]
usage: sudo [-ABbEHkNnPS] [-C num] [-D directory] [-g group] [-h host] [-p
            prompt] [-R directory] [-T timeout] [-u user] [VAR=value] [-i | -s]
            [command [arg ...]]
usage: sudo -e [-ABkNnS] [-C num] [-D directory] [-g group] [-h host] [-p
            prompt] [-R directory] [-T timeout] [-u user] file ...
Saharshwadekar % man
What manual page do you want?
Saharshwadekar % mkdir practical_3
Saharshwadekar % mv practical_3 lab_3
Saharshwadekar % ls
Test		first.txt	lab_3		third.txt
Saharshwadekar % rmdir lab_3