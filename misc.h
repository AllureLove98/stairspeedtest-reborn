#ifndef MISC_H_INCLUDED
#define MISC_H_INCLUDED

#include <string>
#include <vector>

#ifdef _WIN32
#define PATH_SLASH "\\"
#else
#define PATH_SLASH "//"
#endif // _WIN32

#include "geoip.h"

using namespace std;

struct nodeInfo
{
    int linkType = -1;
    int id = 0;
    bool online = false;
    string group;
    string remarks;
    string server;
    int port = 0;
    string proxyStr;
    long long rawSpeed[20] = {};
    long long totalRecvBytes = 0;
    int duration = 0;
    string avgSpeed = "0.00B";
    string maxSpeed = "0.00B";
    string pkLoss = "100.00%";
    int rawPing[6] = {};
    string avgPing = "0.00";
    double rawSitePing[6] = {};
    string sitePing = "0.00";
    string traffic;
    geoIPInfo inboundGeoIP;
    geoIPInfo outboundGeoIP;
    string testFile;
};

static const string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

string UrlDecode(const string& str);
string base64_decode(string encoded_string);
string base64_encode(string string_to_encode);

vector<string> split(const string &s, const string &seperator);
string getUrlArg(string url, string request);
string replace_all_distinct(string str, string old_value, string new_value);
string urlsafe_base64_reverse(string encoded_string);
string urlsafe_base64_decode(string encoded_string);
string UTF8ToGBK(string str_src);
string GBKToUTF8(string str_src);
string trim(const string& str);
string getSystemProxy();

void sleep(int interval);
string regReplace(string src, string match, string rep);
int regMatch(string src, string match);
string speedCalc(double speed);
bool strFind(string str, string target);
string grabContent(string raw);
string getMD5(string data);
bool isIPv4(string address);
bool isIPv6(string address);

bool fileExist(string path);
bool fileCopy(string source,string dest);
string fileToBase64(string filepath);
string fileGetMD5(string filepath);

#ifdef _WIN32
void StringToWstring(std::wstring& szDst, std::string str);
#endif // _WIN32

#endif // MISC_H_INCLUDED
