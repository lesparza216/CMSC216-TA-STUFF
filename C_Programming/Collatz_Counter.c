#include <stdio.h>
#include <stdlib.h>

int collatz_counter(int);

int main(int argc, char *argv[]){
  if(argc != 2){
    printf("To use this program type in the exectuable name and a number\n");
    printf("What this program does is tell you what number repeats the collatz sequence specified\n");
    printf("For example type in collatz 10 and it will tell you what number repeats the sequence 10 times\n");
    return 1;
  }

  int steps = 0;
  int counter = 1;

  while(1){
    steps = collatz_counter(counter);
    if(steps == atoi(argv[1])){
      break;
    }
    counter++;

  }
  printf("It seems the number that repeats the sequence %d times is %d\n",atoi(argv[1]),counter);

  return 0;


}

int collatz_counter(int number){
  int steps = 0;
  while(number != 1){
    if(number % 2 == 0){
      number = number /2;
      steps++;
    }else{
      number = (number * 3) + 1;
      steps++;

    }

  }
  return steps;
}
