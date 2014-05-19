instant-message
===============

A program I wrote in C that I hoped would reinforce the concepts of signals and sockets that were taught in my Systems Programming class. The goal was to gain a better understanding of how these concepts actually worked. 

###Program Overview
---
The program allows for two users to connect to one and other and communicate through the terminal windows. The design of the code involved making a single InstantMessage.c file as oppossed to two separate user1.c and user2.c files for faster compilation and debugging. 

###Program Simulation
---
This program can be executed and ran in two ways: 

#####One Machine:
You may use a single machine and have two terminals open to represent the instant messaging conversation between two users

OR

#####Two Machines:
You may use two different machines on the same network. User1 would connect on one machine and wait for a connection through the form of an IP address from User2 on the other machine. 


###Configuration
---
#####In order to execute this program:

1. Clone the repository

2. To simulate a session, open two terminal windows that will represent user1 and user2

3. Enter "```Make```" at the respective directory

4. To represent user1, execute "```./InstantMessage```" in one of the terminal windows.

5. To represent user2, execute "```./InstantMessage XXX.XX.XX.X```" with a command line argument of your IP address in place of the X's.

###IP Address Locator
---
#####On a Windows 8 Machine: 

1. Hold  "```Windows Key + R```" to open a command prompt. 

2. Enter "```cmd```" in the terminal window.

3. Enter "```ipconfig```" in the terminal window.

4. Locate your respective IP address and pass this address as a command line argument in Step 5 of Configuration.

#####On a Linux Machine:

1. Hold "```CTRL + SHIFT + T```" to open a terminal window.

2. Enter "```ifconfig```" in the terminal window.

3. Locate your respective IP address and pass this address as a command line argument in Step 5 of Configuration.
