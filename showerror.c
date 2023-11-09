#include "showerror.h"

INT UiLength(UINT ui) {
    int iLength = 1;
    for (; ui > 10u; ui /= 10u)
        iLength++;
    return iLength;
}

INT ShowError(HWND hWnd, LPCSTR lpszFile, UINT uiLine) {
    DWORD dwError = GetLastError();
    if (!dwError)
        return 1;
    LPSTR lpszErrorDescription = NULL;
    DWORD dwErrorDescriptionLength = FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS |
        FORMAT_MESSAGE_ALLOCATE_BUFFER,
        NULL,
        dwError,
        MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
        (LPSTR)&lpszErrorDescription,
        0,
        NULL
    );
    if (!dwErrorDescriptionLength)
        return 2;

    LPSTR lpszFormat = "Error in %s in line %u:\n%s";
    INT iMessageLength = (
        strlen(lpszFormat) - 6
        + strlen(lpszFile)
        + UiLength(uiLine)
        + dwErrorDescriptionLength
        + 1
    );
    LPSTR lpszMessage = malloc(iMessageLength*sizeof(CHAR));
    if (!lpszMessage) {
        LocalFree(lpszMessage);
        return 3;
    }
    sprintf(lpszMessage, lpszFormat, lpszFile, uiLine, lpszErrorDescription);
    LocalFree(lpszErrorDescription);

    INT iBoxCode = MessageBox(hWnd, lpszMessage, NULL, MB_OK | MB_ICONERROR);
    free(lpszMessage);
    return iBoxCode ? 0 : 4;
}
