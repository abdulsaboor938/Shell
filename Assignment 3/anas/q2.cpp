#include<stdio.h>



#include<iostream>



#include<pthread.h>



using namespace std;



int siz;



bool checkPrime(int num)

{

	for(int i=2;i<=num/2;i++)



     {



        if(!(num%i))



          {



           return false;



          }

     }





return true;

}



void *prime(void *arg)



{



  bool check=false;

	int i=2;

  while(i<siz)



  {



     if(checkPrime(i))

     {



       cout<<i<<"   ";



     }

     i++;

  }

cout<<endl;

 pthread_exit(0);



}







int main(int argc,char *argv[])



{



 pthread_t thread;



 



   siz=atoi(argv[1]);









   pthread_create(&thread,NULL,prime,NULL);



   pthread_join(thread,NULL);





 return 0;







 }



