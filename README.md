# Ripper
A small c++ program that takes an html file, uses regex to extract file urls (usually image files), and downloads all urls while listing them in a file (or stdout if no file or dl path given).

usage (will change once parser is finnished):
./rip html_file regex_file url_list_file /path/to/download/to/

You need the final 2 options right now (will change once parser is finnished).

Runs in bash, needs curl.

TODO:
 - parser
 - multidownload mode
 - sigint/sigkill handler
 - help page
 - convert files to cbz/pdf/other
 - error handling

Maybe:
 - logging
 - download html file (thats up to you at the moment)
 - download next html (next page/chapter)
 - support other media types (text to ebook)
