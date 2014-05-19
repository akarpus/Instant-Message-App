instant-message
===============

A program that allows two users to instant message each other over TCP/IP

###Configuration
---
#####In order to execute this program:

1) Clone the repository

2) To simulate a session, open two terminal windows that will represent user1 & user2

3) Enter "```Make```" at the respective directory

4) To represent user1, execute "```./InstantMessage```" in one of the terminal windows.

5) To represent user2, execute "```./InstantMessage 127.0.0.1```" with a command line argument of your IP address in the other terminal window.

###IP Address Locator
---
#####On a Windows 8 Machine: 

1) Hold  "```Windows Key + R```" to open a command prompt. 

2) Enter "```cmd```" in the terminal window.

3) Enter "```ipconfig```" in the terminal window.

4) Locate your respective IP address and pass this address as a command line argument in Step 5 of Configuration.

#####On a Linux Machine:

1) Hold "```CTRL + SHIFT + T```" to open a terminal window.

2) Enter "```ifconfig```" in the terminal window.

3) Locate your respective IP address and pass this address as a command line argument in Step 5 of Configuration.
