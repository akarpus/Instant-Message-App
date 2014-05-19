#define SERVER_PORT 60002
#define MAX_STR 100

static volatile int oracle_Signal = 0;

// User Functions
void user2(char*);
void user1();

/* Signal Handler Functions */
void yes_Signal(int);
void no_Signal(int);
void win_Signal(int);
