#include "StudentScoreManager.h"
#include "iostream"

using namespace std;

StudentScoreManager::StudentScoreManager()
{
	StudentScores = unordered_map<int, unordered_map<ESubjectType, int>>();
}

bool StudentScoreManager::IsStudentExist(int InStudentID) const
{
	auto StudentIdIt = StudentScores.find(InStudentID);
	if (StudentIdIt == StudentScores.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool StudentScoreManager::IsScoreExist(int InStudentID, ESubjectType InSubjectType) const
{
	auto StudentIdIt = StudentScores.find(InStudentID);
	if (StudentIdIt == StudentScores.end())
	{
		return false;
	}

	const unordered_map<ESubjectType, int>& Subjects = StudentIdIt->second;
	auto SubjectIt = Subjects.find(InSubjectType);
	if (SubjectIt == Subjects.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool StudentScoreManager::AddStudent(int InStudentID)
{
	if (IsStudentExist(InStudentID) == true)
	{
		return false;
	}

	unordered_map<ESubjectType, int> SubjectScores;
	StudentScores.insert(make_pair(InStudentID, SubjectScores));
	return true;
}

bool StudentScoreManager::AddStudentScore(int InStudentID, ESubjectType InSubjectType, int InScore)
{
	if (IsStudentExist(InStudentID) == false)
	{
		return false;
	}

	if (IsScoreExist(InStudentID, InSubjectType) == true)
	{
		return false;
	}

	auto StudentIdIt = StudentScores.find(InStudentID);
	StudentIdIt->second.insert(make_pair(InSubjectType, InScore));

	return true;
}

int StudentScoreManager::GetScore(int InStudentID, ESubjectType InSubjectType) const 
{
	if (IsStudentExist(InStudentID) == false)
	{
		return -1;
	}

	if (IsScoreExist(InStudentID, InSubjectType) == false)
	{
		return -1;
	}

	auto SubjectTypeIdIt = StudentScores.find(InStudentID)->second.find(InSubjectType);
	return  SubjectTypeIdIt->second;
}

unordered_map<ESubjectType, int> StudentScoreManager::GetScore(int InStudentID) const
{
	if (IsStudentExist(InStudentID) == false)
	{
		return unordered_map<ESubjectType, int>();
	}

	return StudentScores.find(InStudentID)->second;
}
