#include"Library.h"
 
void HuckMemory();


int main() 
{
	
HuchMemory();
return 0;
}
//.....................................................
void HuckMemory() 
{
	int valuetowrite = 0;
	malloc(0);
	cin >> valuetowrite;
	//пишем любое имя окна 
	HWND windwos = FindWindowA(NULL, "Form1");
	// проверям существует ли окно или нет
	if (windwos > (HWND)0x000)
	{
		cout << "Success open" << endl;
		DWORD ProcessId;
		// берём process id
		GetWindowThreadProcessId(windwos, &ProcessId);
		cout << "My ID Process: " << ProcessId << endl;
		HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessId);
		cout << "My Procces: " << process << endl;
		//делаем проверку на то если мы смогли открыть процесс 
		if (process)
		{
			cout << "lpvoid(windows): " << (LPVOID)windwos << endl;
			cout << "&valuetowrite: " << &valuetowrite << endl;
			cout << "(DWORD)sizeof(valuetowrite): " << (DWORD)sizeof(valuetowrite) << endl;
			// где мы водим адресс памятьи, мы изменяем на наше введеное число, можно узнать адресс паямтьи в cheat engeine
			int WriteMemoryProcess = WriteProcessMemory(process, (LPVOID)0x028B59E4, &valuetowrite, (DWORD)sizeof(valuetowrite), NULL);
			cout << "WriteMemoryProcess: " << WriteMemoryProcess << endl;
			//здесь мы проверяем смогли ли мы перезаписать память или нет 
			if (WriteMemoryProcess > 0)
			{
				cout << "success write memory" << endl;
			}
			else
			{
				printf("\x1B[31mError:\033[0m\t\t");
				cout << "don't could write memory" << endl;
			}
		}
		else
		{
			cout << "process couls don't open" << endl;
		}
		CloseHandle(process);
		cin.get();
	}
	else
	{
	printf("\x1B[31mError: \033[0m\t\t");
	cout << "winsows not form" << endl;
	}
}

