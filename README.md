# Ripper
A small c++ program that takes an html file, uses regex to extract file urls (usually image files), and downloads all urls while listing them in a file (or stdout if no file or dl path given. will change.).

Runs in bash, needs curl.

Requires [libargmage](https://github.com/bin4rym4ge/libargmage).
Just drop the libargmage folder into the project folder and make.<br />
or<br />
`git clone https://github.com/bin4rym4ge/libargmage.git`<br />
into the project file.


**Usage:**<br />
`-f file.html` (or url savefile. depends on your regex)<br />
`-r regex_file.txt`<br />
`-s url_save_file.txt`<br />
`-x` (no url save file or output)<br />
`-o /download/path/`<br />
<br /><br />
Feel free ot use whatever and learn from it.
<br /><br />

**Done:**
 - argv parser
 - help page


**TODO:**
 - multidownload mode
 - sigint/sigkill handler
 - convert files to cbz/pdf/other
 - error handling


**Maybe:**
 - logging
 - download html file (thats up to you at the moment)
 - download next html (next page/chapter)
 - support other media types (text to ebook)
