#include <unordered_map>

class StudentScoreManager
{
private:
	unordered_map<int /* StudentID */, unordered_map<ESubjectType /* SubjectType */, int /*Score */>> myMap;

public:
	bool AddStudent(int StudentID);


};