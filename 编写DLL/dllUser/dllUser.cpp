// dllUser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wuygDll.h"
#include <iostream>
#include <windows.h>

#pragma comment(lib, "wuygDll")//������ʽ���á�Ҫ���ӵĵ���⣨.LIB files���������� DLL ʱ��������������⡣��

int _tmain(int argc, _TCHAR* argv[])
{
	//��ʽ����
	wuygFun();
	
	//��ʽ����
	typedef int (__stdcall *Fun)(void); //���庯��ָ������
	HMODULE hDll = ::LoadLibrary(L"wuygDll");//����DDL�Լ���ȡģ����

	/*��Ϊʹ����UNICODE�ַ�����ԭ��LoadLibraryʵ����ʹ��LoadLibraryW����LoadLibraryA
����Ӧ�ģ��ú�������Ҫ�Ĳ���Ӧ��Ϊ���ַ�������UNICODE�ַ���������խ�ַ���(���ֽ��ַ�������
���ַ�����ʽ�и���Lǰ׺����Ա�խ�ַ�(��)Ϊ���ַ�(��).*/

	Fun TestFun = ::GetProcAddress(hDll, "wuygFun");//��ȡָ��Ӧ�ó���Ҫ���õĵ��������ĺ���ָ��

	if (!TestFun)
	{
		// handle the error
		FreeLibrary(hDll);//���ָ���ȡ���������˳�֮ǰ����ж��DLL(FreeLibrary)
		printf_s("ERROR!");
		system("pause");
		return 0;
	}
	else
	{
		// call the function
		TestFun();
		system("pause");
		return 0;
	}
}

