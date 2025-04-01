#include <iostream>
#include <vector>
#include <random>

#include "MyCalc.h"
#include "StudentScoreManager.h"
#include "SharedPtr.h"

using namespace std;

void TestMyCalc()
{
	// ������ �þ �ʿ䰡 ���ٸ�, ���� �迭�� �ʿ��ұ�?
	vector<int> IntAnswers;
	IntAnswers.push_back(IntCalculater::Add(1, 2));
	IntAnswers.push_back(IntCalculater::Minus(1, 2));
	IntAnswers.push_back(IntCalculater::Multiply(1, 2));
	IntAnswers.push_back(IntCalculater::Divide(1, 2));

	cout << "Int Answer Out" << endl;
	for (const auto& IntAnswer : IntAnswers)
	{
		cout << IntAnswer << endl;
	}

	vector<float> FloatAnswers;
	FloatAnswers.push_back(FloatCalculater::Add(1.f, 2.f));
	FloatAnswers.push_back(FloatCalculater::Minus(1.f, 2.f));
	FloatAnswers.push_back(FloatCalculater::Multiply(1.f, 2.f));
	FloatAnswers.push_back(FloatCalculater::Divide(1.f, 2.f));

	cout << "Float Answer Out" << endl;
	for (const auto& FloatAnswer : FloatAnswers)
	{
		cout << FloatAnswer << endl;
	}

	return;
}

void TestStudentManager()
{
	StudentScoreManager* ScoreManager = new StudentScoreManager();

	int StudnetsIDs[] = { 0, 1, 2, 3, 4 };
	for (const auto& StudnetsID : StudnetsIDs)
	{
		ScoreManager->AddStudent(StudnetsID);
	}
	
	random_device RandomDevice;
	mt19937 RandomGenerator(RandomDevice());
	uniform_int_distribution<> RandomNumberGetter(1, 100);

	for (const auto& StudnetsID : StudnetsIDs)
	{
		ScoreManager->AddStudent(StudnetsID);
		for (int Index = 0; Index < 4; Index++)
		{
			ScoreManager->AddStudentScore(StudnetsID, static_cast<ESubjectType>(Index), RandomNumberGetter(RandomGenerator));
		}
	}

	for (const auto& StudnetsID : StudnetsIDs)
	{
		cout << "ID : " << StudnetsID << endl;
		for (int Index = 0; Index < 4; Index++)
		{
			cout << ScoreManager->GetScore(StudnetsID, static_cast<ESubjectType>(Index)) << endl;
		}
	}
}

void TestSharedPtr()
{
	SharedPtr<StudentScoreManager> Ptr0 = new StudentScoreManager();
	SharedPtr<StudentScoreManager> Ptr1 = Ptr0;
	SharedPtr<StudentScoreManager> Ptr2 = new StudentScoreManager();

	SharedPtr<StudentScoreManager> Ptrs[10];
	for (int i = 0; i < 10; i++)
	{
		Ptrs[i] = new StudentScoreManager();
	}

	cout << Ptr0.GetRefCount() << " " << Ptr1.GetRefCount() << endl;

	Ptr1 = Ptr2;

	cout << Ptr0.GetRefCount() << " " << Ptr1.GetRefCount() << endl;

	for (const auto& Ptr : Ptrs)
	{
		cout << Ptr.GetRefCount() << endl;
	}
}

void TestMap()
{
	int Map[10][10] = { 0 };

	for (int Index0 = 1; Index0 < 9; Index0++)
	{
		for (int Index1 = 1; Index1 < 9; Index1++)
		{
			Map[Index0][Index1] = 1;
		}
	}

	for (int Index0 = 0; Index0 < 10; Index0++)
	{
		for (int Index1 = 0; Index1 < 10; Index1++)
		{
			cout << Map[Index0][Index1] << " ";
		}
		cout << endl;
	}

	for (int Index0 = 1; Index0 < 6; Index0++)
	{
		for (int Index1 = 0; Index1 < Index0; Index1++)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}
}

int main()
{
	TestMap();
}
