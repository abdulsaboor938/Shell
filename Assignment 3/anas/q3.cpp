#include <pthread.h>



#include <stdio.h>



#include <sys/wait.h>



#include<iostream>







using namespace std;







int *fib;

int siz;

bool check = 1;





void *fibonacci(void *arg) /* the thread */



{







  fib[0]=0;



  fib[1]=1;



	



  for(int i=2;i<siz;i++)



  {

     fib[i]=fib[i-1]+fib[i-2];

  }



check = 0;



  pthread_exit(0);



}



int main(int argc, char * argv[])



{



int pid;



pthread_t thread;



 



  siz=atoi(argv[1]);



  fib=new int[siz];

  



     pthread_create(&thread,NULL,fibonacci,NULL);



     pthread_join(thread,NULL);



    

	while(check);



    for (int i=0; i<siz; i++)

		cout<<fib[i]<<"    ";

	cout<<endl;

     

     return 0;



}



