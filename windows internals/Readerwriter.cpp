#include<queue>
#include<windows.h>
#include<iostream>

using namespace std;

queue <int> Tqueue;

int glob;

SRWLOCK  Rlock, Wlock;

CONDITION_VARIABLE QueueNotEmpty, QueueNotFull;

CONDITION_VARIABLE QueueEmpty, QueueFull;

//reader thrds call back functions



DWORD WINAPI read1(LPVOID Str)

{

	AcquireSRWLockExclusive(&Rlock);

	if (Tqueue.empty())
	{
		SleepConditionVariableSRW(&QueueNotEmpty, &Rlock, INFINITE, 0);
	}

	else
	{

		cout << "Reader thread1 consumed : " << Tqueue.front() << endl;
Tqueue.pop();
WakeAllConditionVariable(&QueueNotFull);

	}

	ReleaseSRWLockExclusive(&Rlock);


	return 0;
}



DWORD WINAPI read2(LPVOID Str)



{
AcquireSRWLockExclusive(&Rlock);
if (Tqueue.empty())
{

		SleepConditionVariableSRW(&QueueNotEmpty, &Rlock, INFINITE, 0);

		SleepConditionVariableSRW(&QueueEmpty, &Rlock, INFINITE, 0);
		WakeConditionVariable(&QueueFull);
	}

	else

	{

	cout << "Reader thread2 consumed : " << Tqueue.front() << endl;

		cout << "Reader consumed : " << Tqueue.front() << endl;

	Tqueue.pop();

	WakeAllConditionVariable(&QueueNotFull);
	WakeConditionVariable(&QueueFull);
	.

	}

	ReleaseSRWLockExclusive(&Rlock);
return 0;

}

//write callback functions.................................................................
DWORD WINAPI write1(LPVOID Str)

{
AcquireSRWLockExclusive(&Wlock);
if (Tqueue.size() == 5)

	{

		SleepConditionVariableSRW(&QueueNotFull, &Wlock, INFINITE, 0);

	}
	else

	{

Tqueue.push(1);
cout << "writer thread1 pushed value :" << '1' << endl;
WakeAllConditionVariable(&QueueNotEmpty);

	}

	ReleaseSRWLockExclusive(&Wlock);
return 0;

}

DWORD WINAPI write2(LPVOID Str)

{
	AcquireSRWLockExclusive(&Wlock);

	if (Tqueue.size() == 5)

{
	SleepConditionVariableSRW(&QueueNotFull, &Wlock, INFINITE, 0);
	}
	else
	{
		Tqueue.push(2);
	cout << "writer thread2 pushed value :" << '2' << endl;
	WakeAllConditionVariable(&QueueNotEmpty);
	}

	ReleaseSRWLockExclusive(&Wlock);
	return 0;
}

DWORD WINAPI write3(LPVOID Str)

{

	AcquireSRWLockExclusive(&Wlock);
	if (Tqueue.size() == 5)
	{

		SleepConditionVariableSRW(&QueueNotFull, &Wlock, INFINITE, 0);
	}

	else
	{

		Tqueue.push(3);

		cout << "writer thread3 pushed value :" << '3' << endl;

		WakeAllConditionVariable(&QueueNotEmpty);

	}

	ReleaseSRWLockExclusive(&Wlock);

	return 0;
}

DWORD WINAPI write4(LPVOID Str)
//writer calback functions........................................................
DWORD WINAPI write(LPVOID Str)
{
	AcquireSRWLockExclusive(&Wlock);
	if (Tqueue.size() == 5)
	{
		SleepConditionVariableSRW(&QueueNotFull, &Wlock, INFINITE, 0);
		SleepConditionVariableSRW(&QueueFull, &Wlock, INFINITE, 0);
WakeAllConditionVariable(&QueueEmpty);
	}
else
	{

		Tqueue.push(4);
		cout << "writer thread4 pushed value :" << "4" << endl;
		WakeAllConditionVariable(&QueueNotEmpty);
		Tqueue.push(++glob);
		cout << "writer produced :" << glob << endl;
WakeAllConditionVariable(&QueueEmpty);



	}



	ReleaseSRWLockExclusive(&Wlock);



	return 0;



}



int _tmain(int argc, WCHAR* argv[], WCHAR* env[])



{



	HANDLE Thread[6], read[2], write[4];



	HANDLE Thread[6];



	LPWSTR Str = NULL;



	InitializeSRWLock(&Rlock);



	InitializeSRWLock(&Wlock);



	InitializeConditionVariable(&QueueNotEmpty);



	InitializeConditionVariable(&QueueNotFull);



	InitializeConditionVariable(&QueueEmpty);



	InitializeConditionVariable(&QueueFull);



	while (1)



	{



		Thread[0] = read[0] = CreateThread(NULL,//security attributes thread is not inherited if null



			0,//stack size for thread if 0 it uses size of executable



			read1,//call back function



			Str,//parameter to function



			0,//creation flag



			NULL);//thread id



				  //reader threads......................................................................







		if (read[0] == NULL)



			glob = 0;



		for (int i = 0; i < 2; i++)



		{



			cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;



		}







		Thread[i] = CreateThread(NULL,//security attributes thread is not inherited if null



			0,//stack size for thread if 0 it uses size of executable



			read,//call back function



			Str,//parameter to function



			0,//creation flag



			NULL);//thread id



				  //reader threads......................................................................







		Thread[1] = read[1] = CreateThread(NULL,//security attributes thread is not inherited if null



			0,//stack size for thread if 0 it uses size of executable



			read2,//call back function



			Str,//parameter to function



			0,//creation flag



			NULL);//thread id



		if (read[1] == NULL)



		{



			cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;



			if (Thread[i] == NULL)



			{



				cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;



			}



		}







		//writer threads.................................................................................







		Thread[2] = write[0] = CreateThread(NULL,//security attributes thread is not inherited if null



			0,//stack size for thread if 0 it uses size of executable



			write1,//call back function



			Str,//parameter to function



			0,//creation flag



			NULL);//thread id



		if (write[0] == NULL)



		{



			cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;



		}











		Thread[3] = write[1] = CreateThread(NULL,//security attributes thread is not inherited if null



			0,//stack size for thread if 0 it uses size of executable



			write2,//call back function



			Str,//parameter to function



			0,//creation flag



			NULL);//thread id



		if (write[1] == NULL)



		{



			cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;



		}











		Thread[4] = write[2] = CreateThread(NULL,//security attributes thread is not inherited if null



			0,//stack size for thread if 0 it uses size of executable



			write3,//call back function



			Str,//parameter to function



			0,//creation flag



			NULL);//thread id



		if (write[2] == NULL)



		{



			cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;



		}











		Thread[5] = write[3] = CreateThread(NULL,//security attributes thread is not inherited if null



			0,//stack size for thread if 0 it uses size of executable



			write4,//call back function



			Str,//parameter to function



			0,//creation flag



			NULL);//thread id



		if (write[3] == NULL)



			for (int i = 2; i < 6; i++)



			{



				cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;



				Thread[i] = CreateThread(NULL,//security attributes thread is not inherited if null



					0,//stack size for thread if 0 it uses size of executable



					write,//call back function



					Str,//parameter to function



					0,//creation flag



					NULL);//thread id



				if (Thread[i] == NULL)



				{



					cout << "creation of thread failed due to error (" << GetLastError() << ")" << endl;



				}



			}



		WaitForMultipleObjects(6, Thread, TRUE, INFINITE);



	}