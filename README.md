# Orchestra
A repository for my group final project from the first semester of my Senior year of high school. My group members for this project were Jessica Ng and Fawn Wong.

The idea was to have "performer" computers play sounds based on instructions from a "conductor" computer. This met with some success.

Below is the README from the original project, copied and pasted directly, from line 10 onward:



#Orchestra 
######<i>String Quartet</i>
###Jessica Ng, Jake Olenick, Fawn Wong
####Period 3

##Compilation Instructions

* You need to install libao-dev (presumably "sudo apt-get install libao-dev" although getting it from the Ubuntu Software Center also works)
 * for macs: <a href = "http://rudix.org/packages/libao.html">download</a>
 * Make sure it's on all performing computers!
* Compile with make

##Usage Instructions

* Run conductor first with the piece you want to play as a parameter
 * ./conductor eine_kleine
 * ./conductor canon
* Run 4 performers either locally or otherwise
 * ./performer <ip address if you are not running it locallly>
* Follow instructions on conductor
 

##Bugs

* No errors or warnings when it's on the school computers (at least, the last time we checked), but 2 warnings (though it does run) on mac
* Doesn't work with school computer and outside laptop together

##List of Files
* conductor.c
* performer.c
* sounds
 * chart
 * convert.c
 * convert.h
 * sounds.c
 * mute_sounds.c
 * eine_kleine1
 * eine_kleine2
 * eine_kleine3
 * eine_kleine4
 * canon1
 * canon2
 * canon3
 * canon4
* converter.py (makes it easier to write sheet music)
