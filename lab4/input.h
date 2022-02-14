#include "Voter.h"

typedef struct Voter Voter;
typedef struct VotersArray VotersArray;

VotersArray *generateData(int n);

VotersArray *readFromStdInput();

VotersArray *readFromFile(const char *fileName);