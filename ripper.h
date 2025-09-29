#ifndef RIPPER_H
#define RIPPER_H

std::string fnumstr4(int num);

std::vector<std::vector<std::string>> mdiv(std::vector<std::string> in, int x);

void seqdl(std::vector<std::string> vurl, std::vector<std::string> vfname, std::string dlpath);

void multidl(std::vector<std::vector<std::string>> inurl, std::vector<std::vector<std::string>> inname, std::string dlpath);

#endif

