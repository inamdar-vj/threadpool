
#include <iostream>

using namespace std;

class A_worker
{
public:
	virtual bool start(void) = 0;
	virtual bool stop(void) = 0;
	
	virtual bool doWork(  void (*)()  ) = 0;
};

class B_threadpool : public A_worker
{
public:
	bool start (void) 
    {
		cout << "ok start" << endl;
		return true;
	}

	bool stop (void)
	{
		cout << "ok stop" << endl;
		return true;
	}
		
	bool doWork (  void(*func1)()  )
	{
		cout << "doWork" << endl;
		func1();
		return true;
	}
};
	

void test_func()
{
	cout << "test func" << endl;
}	
	
int main()
{
	//void (*funcPtr)() = test_func;
	B_threadpool b;
	b.start();
	b.doWork(&test_func);
	b.stop();
		
	return 0;
}

