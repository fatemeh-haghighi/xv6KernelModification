#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#define ARRAY_SIZE 7
void sort_func(int* array)
{
	int temp;
	for(int i =0; i < ARRAY_SIZE; i++)
	{
		temp = 0;
		for(int j = i + 1; j < ARRAY_SIZE; j++)
		{
			if(array[j] < array[i])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;	
			}
		}

	}

}
int main(int argc, char* argv[])
{
	int pid = 0;
	pid = getpid();	
	printf(1, "process id in middle user program is : %d\n", pid);
	int array[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; i++)
		array[i] = atoi(argv[i + 1]);
	sort_func(array);
	char out[15];
	int num = array[3];
	int i = 0;
	while(num > 0)
	{
		out[i] = (char)((num % 10) + '0');
		num = num / 10;
		i++;
	}
	// printf(1 , "middle is %s\n", out);

	int file = open("result.txt",O_CREATE |O_WRONLY);
	if(file != -1)
	{
		write(file , out, strlen(out) + 1);
		write(file , "\n", strlen("\n") +1 );
	}	
	
	exit();
}