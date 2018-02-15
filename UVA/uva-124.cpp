Order is an important concept in mathematics and in computer science. For example, Zorn's Lemma states: ``a partially ordered set in which every chain has an upper bound contains a maximal element.'' Order is also important in reasoning about the fix-point semantics of programs. 

This problem involves neither Zorn's Lemma nor fix-point semantics, but does involve order. 

The Problem

Given a list of variable constraints of the form x < y, you are to write a program that prints all orderings of the variables that are consistent with the constraints. 

For example, given the constraints x < y and x < z there are two orderings of the variables x, y, and z that are consistent with these constraints: x y z and x z y. 

The Input

The input consists of a sequence of constraint specifications. A specification consists of two lines: a list of variables on one line followed by a list of constraints on the next line. A constraint is given by a pair of variables, where x y indicates that x < y. 

All variables are single character, lower-case letters. There will be at least two variables, and no more than 20 variables in a specification. There will be at least one constraint, and no more than 50 constraints in a specification. There will be at least one, and no more than 300 orderings consistent with the contraints in a specification. 

Input is terminated by end-of-file. 

The Output

For each constraint specification, all orderings consistent with the constraints should be printed. Orderings are printed in lexicographical (alphabetical) order, one per line. 

Output for different constraint specifications is separated by a blank line. 

Sample Input

a b f g

a b b f

v w x y z

v y x v z v w v

Sample Output

abfg

abgf

agbf

gabf

 

wxzvy

wzxvy

xwzvy

xzwvy

zwxvy

zxwvy

 

Solution: DFS (Run Time: 0.000)

#include<stdio.h>

 

#define SIZE1 26

#define SIZE2 1201

 

char line[SIZE2];

int variable[SIZE1], used[SIZE1], path[SIZE1][SIZE1];

int N;

char output[SIZE1];

int isFirst;

 

void initCase()

{

    int i, j;

    for (i=0; i<SIZE1; i++)

         variable[i] = 0;

    for (i=0; i<SIZE1; i++) for (j=0; j<SIZE1; j++)

         path[i][j] = 0;

    for (i=0; i<SIZE1; i++)

         used[i] = 0;

}

 

void readCase()

{

    int i, j, index1, index2;

    for (i=0; line[i]; i++) if (line[i]>='a' && line[i]<='z') {

         index1 = line[i] - 'a';

         variable[index1] = 1;

    }

    gets(line);

    for (i=0; line[i]; i++) {

         while (line[i] == ' ')

             i++;

         index1 = line[i] - 'a';

         i++;

         while (line[i] == ' ')

             i++;

         index2 = line[i] - 'a';

         path[index1][index2] = 1;

    }

}

 

void printPath()

{

    int i, j;

    for (i=0; i<SIZE1; i++) if (variable[i]) {

         for (j=0; j<SIZE1; j++) if (variable[j])

             printf("%d ", path[i][j]);

         printf("\n");

    }

    printf("\n");

}

 

void countVariable()

{

    int i;

    N = 0;

    for (i=0; i<SIZE1; i++) if (variable[i])

         N++;

}

 

void solve(int index)

{

    int i, j;

    if (index == N) {

         output[index] = '\0';

         printf("%s\n", output);

         return;

    }

    for (i=0; i<SIZE1; i++) if (variable[i] && used[i] == 0) {

         for (j=0; j<SIZE1; j++) if (path[i][j] && used[j])

             return;

         used[i] = 1;

         output[index] = i + 'a';

         solve(index + 1);

         used[i] = 0;

    }

}

 

void solveCase()

{

    int i;

    if (isFirst)

         isFirst = 0;

    else

         printf("\n");

    countVariable();

    solve(0);

}

 

int main()

{

    isFirst = 1;

    while(gets(line)) {

         initCase();

         readCase();

         solveCase();

    }

    return 0;

}
