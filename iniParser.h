#ifndef __INI_PARSER__
#define __INI_PARSER__

void iniwriteString(CString strAppName, CString strKeyName, CString strValue, CString strFilePath);
CString iniReadString(CString strAppName, CString strKeyName, CString strFilePath);
CString GetExePath();

#endif __INI_PARSER__