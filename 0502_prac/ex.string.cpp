#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	// ����� �Է� cin, getline
	// 
	// 1999. 02. 12
	// 1993�� 9�� 6��
	//
	
	// string �������� �� ���ھ� �������� 
	string name = "1234";

	// o �������� (�� ��° ����)
	char one_letter = name[1];


	// �������� �ƴ��� �Ǻ��ϱ� 
	bool isNum = true;
	for (int i = 0; name.length(); i++)
	{
		// isdigit�� ����� 0�� �ƴϸ� = ����
		if (isdigit(name[i]) != 0)
		{
			//isNum = true;
		}
		else // isdigit�� ����� 0�̸� = ���� �Ǵ� Ư������
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