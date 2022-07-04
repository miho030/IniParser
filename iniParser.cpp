#include "pch.h"

CCriticalSection g_criticalExe;

void iniwriteString(CString strAppName, CString strKeyName, CString strValue, CString strFilePath)
{
	WritePrivateProfileString(strAppName, strKeyName, strValue, strFilePath);
}

CString iniReadString(CString strAppName, CString strKeyName, CString strFilePath)
{
	CString szReturnString;
	LPWSTR szReturnTmp = (LPWSTR)(LPCWSTR)szReturnString;


	GetPrivateProfileString(strAppName, strKeyName, _T(""), szReturnTmp, 1024, strFilePath);

	CString strTemp;
	strTemp.Format(_T("%s"), szReturnTmp);

	return strTemp;
}


CString GetExePath()
{
	g_criticalExe.Lock();
	static TCHAR pBuf[256] = { 0, };
	memset(pBuf, NULL, sizeof(pBuf));

	GetModuleFileName(NULL, pBuf, sizeof(pBuf));

	CString strFilePath;
	strFilePath.Format(_T("%s"), pBuf);
	strFilePath = strFilePath.Left(strFilePath.ReverseFind(_T('\\')));
	g_criticalExe.Unlock();

	return strFilePath;
}
