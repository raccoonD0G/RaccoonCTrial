#pragma once
#include <unordered_map>

using namespace std;

enum class ESubjectType
{
	Math,
	Korean,
	English,
	Science,
};

class StudentScoreManager
{

public:
	StudentScoreManager();

private:
	unordered_map<int /* StudentID */, unordered_map<ESubjectType /* SubjectType */, int /*Score */>> StudentScores;

public:
	bool IsStudentExist(int InStudentID) const;
	bool IsScoreExist(int InStudentID, ESubjectType InSubjectType) const;

	bool AddStudent(int InStudentID);
	bool AddStudentScore(int InStudentID, ESubjectType InSubjectType, int InScore);

	int GetScore(int InStudentID, ESubjectType InSubjectType) const;
	unordered_map<ESubjectType, int> GetScore(int InStudentID) const;
};