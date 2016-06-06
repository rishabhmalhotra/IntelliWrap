# IntelliWrap
Intelligent word wrap program written in C++

This program basically serves the purpose of confining the width of lines to the user specified input(on the command line). 
Don't worry though, if nothing has been specified as command line arguments, 25 is the default width.

This program wraps to the specified width but intelligently. If the remaining width on the line is less than the length of the 
next word, instead of breaking the word, this program intelligently moves the entire word onto the next line.

This smart piece of code breaks the word onto separate lines but only when it is absolutely necessary: for example when the
width of the complete line is 3 and the word is "altogether."
