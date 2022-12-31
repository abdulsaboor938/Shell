#include<iostream>

#include<stdio.h>

#include<pthread.h>



using namespace std;



int *numbers;

int run=3;

int siz = 0;

int minim,maxim;

float avg = 0;



void *average(void *arg)



{

	for(int i=0;i < siz;i++)

	{

	     avg+=numbers[i];

	}



	avg/=siz;

	run--;

	pthread_exit(0);

}



void *minimum(void *arg)



{

	minim=numbers[0];



	for(int i=1;i<siz;i++)



	{

		if(numbers[i]<minim)



		{

			minim=numbers[i];

		}

	}

	run--;

        pthread_exit(0);

}



void *maximum(void *arg)



{

	maxim=numbers[0];



	for(int i=1;i<siz;i++)



	{

		if(numbers[i]>maxim)



		{

			maxim=numbers[i];

		}



	}

	run--;

	pthread_exit(0);

}







int main(int argc,char *argv[])



{

	pthread_t thread_1;

	pthread_t thread_2;

	pthread_t thread_3; 



	numbers=new int[argc-1];

	

	for(int i=0;i<argc-1;i++,siz++)

	{

		numbers[i]=atoi(argv[i+1]);

	}



	pthread_create(&thread_1,NULL,average,NULL);



	pthread_join(thread_1,NULL);

	

	pthread_create(&thread_2,NULL,minimum,NULL);



        pthread_join(thread_2,NULL);



	pthread_create(&thread_3,NULL,maximum,NULL);



        pthread_join(thread_3,NULL);

        

        //while(run);

        

        cout<<"Minimum: "<<minim<<endl;

        cout<<"Maximum: "<<maxim<<endl;

        cout<<"Average: "<<avg<<endl;



	return 0;

}