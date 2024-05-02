#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	// 사용자 입력 cin, getline
	// 
	// 1999. 02. 12
	// 1993년 9월 6일
	//
	
	// string 변수에서 한 글자씩 가져오기 
	string name = "1234";

	// o 가져오기 (두 번째 글자)
	char one_letter = name[1];


	// 숫자인지 아닌지 판별하기 
	bool isNum = true;
	for (int i = 0; name.length(); i++)
	{
		// isdigit의 결과가 0이 아니면 = 숫자
		if (isdigit(name[i]) != 0)
		{
			//isNum = true;
		}
		else // isdigit의 결과가 0이면 = 문자 또는 특수문자
		{
			isNum = false;
		}
	}

	if (isNum == true)
	{
		int num = stoi(name);
		float fnum = stof(name);
	}
}