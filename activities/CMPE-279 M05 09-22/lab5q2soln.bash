gcc -g lab5q2problem.c -o lab5q2problem
gcc lab5q2.c -o lab5q2
./lab5q2 > gotexploitstr.txt
./lab5q2problem < ./gotexploitstr.txt
