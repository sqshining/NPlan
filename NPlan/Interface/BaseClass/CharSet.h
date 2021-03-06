﻿//  File:        CharSet.h
//  Copyright:   Copyright(C) 2013-2017 Wuhan KOTEI Informatics Co., Ltd. All rights reserved.
//  Website:     http://www.nuiengine.com
//  Description:  This code is part of NPlan Project (Powered by NUI Engine)
//  Comments:
//  Rev:         1
//  Created:     2018/8/27
//  Last edit:   2015/11/30
//  Author:      Chen Zhi and his team
//  E-mail:       cz_666@qq.com
//  License: APACHE V2.0 (see license file) 
/**
* Copyright (C) 2003-2010，光庭导航数据有限公司(http://www.kotei-navi.com)
* All rights reserved.
* 
* 文件名称：CharSet.h
* 摘    要：字符集处理函数
*
* 版    本：1.0
* 创建日期：2010/04/01
* 作    者：zhifangh
*
* 修改历史：
* [修改序列][修改日期][修改者][修改内容]
**/

#ifndef _CHARSET_H_
#define _CHARSET_H_

#include "NE_pubhead.h"

//	字符集
enum CHARSETt
{
	CHARSET_GBK = 936,
	CHARSET_SJIS = 932
};

void ReleaseCharSetTable ();

int ConvertUnicode2GBK(IN const wchar_t* wszUnicode, IN size_t iUNLen, OUT char* szGBK);

int ConvertGBK2Unicode(IN const char* szGBK, IN size_t iGBLen, OUT wchar_t* wszUnicode);

// #ifdef QT_WINDOWS_LIB
//	SJIS -> utf8 ,返回转换的字符个数
int ConvertSJIS2Utf8(IN const char* pszSjis, IN int iSjisSize, OUT const char* pszUtf8);

//	GBK -> utf8 ,返回转换的字符个数
int ConvertGBK2Utf8(IN const char* pszGBK, IN int iGBKSize, OUT const char* pszUtf8);
// #endif
void ConvertCreateChar (IN const char* szIn, OUT char* szOut);

void ConvertSlash(wchar_t* wsz);

void ConvertSlash(char* sz);

kn_string Char2KnString(const char* sz);
void KnChar2WChar(IN const kn_char* pszKN, OUT wchar_t* pszWCHAR, IN int iOutLen);

kn_string Utf16ToKnString(const kn_char* pBuff, int iBytelen);

string Knstring2Utf8String(const kn_string& wstr);
string Knstring2String(const kn_string& wstr);

int KNMultiByteToWideChar(
                          UINT CodePage, 
                          DWORD dwFlags, 
                          LPCSTR lpMultiByteStr, 
                          int cbMultiByte, 
                          LPWSTR lpWideCharStr, 
                          int cchWideChar 
                          );

int KNWideCharToMultiByte(
                          UINT CodePage, 
                          DWORD dwFlags, 
                          LPCWSTR lpWideCharStr, 
                          int cchWideChar, 
                          LPSTR lpMultiByteStr, 
                          int cbMultiByte, 
                          LPCSTR lpDefaultChar, 
                          LPBOOL lpUsedDefaultChar 
                          );

#define MultiByteToWideChar KNMultiByteToWideChar
#define WideCharToMultiByte KNWideCharToMultiByte


size_t kn_wcstombs(char * dst, const wchar_t * src, size_t len);
size_t kn_mbstowcs(wchar_t * dst, const char * src, size_t len);

//	android没有实现wcstombs
#if defined(ANDROID_NDK)


	#ifndef wcstombs
		#define wcstombs kn_wcstombs
		#define mbstowcs kn_mbstowcs
	#endif

#endif


void KnChar2WChar(IN const kn_char* pszKN, OUT wchar_t* pszWCHAR, IN int iOutLen);
kn_string Char2KnString(const char* sz);
// kn_string WChar2KnString(const kn_char* pwszKds, const int& iLen);

//	kn_string -> String 
void KnString2String(const kn_string& strKn, string& strMutiByte, UINT CodePage = CP_ACP);
//	String -> kn_string 
void String2KnString(const string& strMutiByte, kn_string& strKn, UINT CodePage = CP_ACP);

string KnChars2String(const kn_char* p, UINT CodePage = CP_ACP);

kn_string Chars2KnString(const char* p, UINT CodePage = CP_ACP);


kn_string Utf16ToKnString(const kn_char* pBuff, int iBytelen);

bool IsFullWidthChar(unsigned char code);

string Knstring2String(const kn_string& wstr);

string Knstring2Utf8String(const kn_string& wstr);
#endif // _CHARSET_H_
