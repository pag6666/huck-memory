#include"Library.h"
 
void HuckMmeory();
class Foo 
{

public:
	char cha;
	char chb;
	short sha;
	int ina;
};
int main() 
{
	
	
	/*for (auto i = 1;i < 600024;i++) 
	{
		if (auto p=malloc(i)) 
		{
			
			free(p);
		}
	}*/
	cout << sizeof(Foo) << endl;
	return 0;
}
void HuckMemory() 
{

	int valuetowrite = 0;
	malloc(0);
	cin >> valuetowrite;
	HWND windwos = FindWindowA(NULL, "Form1");
	if (windwos > (HWND)0x000)
	{
		cout << "Success open" << endl;
		DWORD ProcessId;
		GetWindowThreadProcessId(windwos, &ProcessId);
		cout << "My ID Process: " << ProcessId << endl;
		HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessId);
		cout << "My Procces: " << process << endl;
		if (process)
		{
			cout << "lpvoid(windows): " << (LPVOID)windwos << endl;
			cout << "&valuetowrite: " << &valuetowrite << endl;
			cout << "(DWORD)sizeof(valuetowrite): " << (DWORD)sizeof(valuetowrite) << endl;
			int WriteMemoryProcess = WriteProcessMemory(process, (LPVOID)0x028B59E4, &valuetowrite, (DWORD)sizeof(valuetowrite), NULL);
			cout << "WriteMemoryProcess: " << WriteMemoryProcess << endl;
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

