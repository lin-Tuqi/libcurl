// libcurl.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<curl\curl.h>

#pragma comment(lib,"libcurl.lib")

void Test()
{
	CURL* curl = curl_easy_init();

	if (nullptr == curl)
	{
		std::cout << "curl_easy_init error!\n";
		return;
	}
	curl_easy_setopt(curl, CURLOPT_URL, "www.baidu.com");
	curl_easy_setopt(curl, CURLOPT_NOBODY, 1);

	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
}

int _tmain(int argc, _TCHAR* argv[])
{
	curl_global_init(CURL_GLOBAL_ALL);
	Test();

	curl_global_cleanup();
	system("pause");
	return 0;
}

