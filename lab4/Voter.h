struct Voter;
struct VotersArray;

const char *toString(struct Voter *voter);

int validateStationNumber(const char *number);

int validateAge(char* age);

void destroy(struct Voter *voter);

int insert(struct VotersArray *source, struct Voter *element, int index);

int delete(struct VotersArray *source, int index);

int deleteMany(struct VotersArray *source, int index, int count);

struct Voter *fromString(const char *str);

void destroyArray(struct VotersArray *votersArray);