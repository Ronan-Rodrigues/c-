#include <windows.h>
#include <stdio.h>

typedef LONG(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

int main() {
    HMODULE hMod = GetModuleHandleW(L"ntdll.dll");
    if (hMod) {
        RtlGetVersionPtr fxPtr = (RtlGetVersionPtr)GetProcAddress(hMod, "RtlGetVersion");
        if (fxPtr != NULL) {
            RTL_OSVERSIONINFOW rovi = { 0 };
            rovi.dwOSVersionInfoSize = sizeof(rovi);
            if (fxPtr(&rovi) == 0) {
                wprintf(L"Windows versão %lu.%lu (Build %lu)\n",
                        rovi.dwMajorVersion,
                        rovi.dwMinorVersion,
                        rovi.dwBuildNumber);
                return 0;
            }
        }
    }

    printf("Não foi possível obter a versão do Windows.\n");
   return 1;

}








