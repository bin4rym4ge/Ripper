# Ripper
A small c++ program that takes an html file, uses regex to extract file urls (usually image files), and downloads all urls while listing them in a file. 

usage:
./rip html_file regex_file url_list_file /path/to/download/to/
Final slash is important (no err handaling right now)
You don't need the final 2 options.
