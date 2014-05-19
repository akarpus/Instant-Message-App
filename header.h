#define SERVER_PORT 60002
#define MAX_STR 100

/* Signal Handler Global Variable */
static volatile int oracle_Signal = 0;

/* Player Functions */
void user2(char*);
void user1();

/* Signal Handler Functions */
void yes_Signal(int);
void no_Signal(int);
void win_Signal(int);
