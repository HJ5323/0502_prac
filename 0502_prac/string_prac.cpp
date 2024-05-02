// 1. ����ڿ��� �� ���� �л��� �Է��� ������ ����
// 2. �л� �� ��ŭ "�̸�, ����, ����" ������ �ѹ��� �Է� �ޱ�
// 3. 1) �л� ���� ���, 2) ��ճ���, 3) ���� ���� ����, 4) ���α׷� ����, �� ���� ����� ��� ����
// 4. ���ݱ��� ��� �ڷᱸ��(�迭, ����, ����Ʈ), ���ڿ�(��Ʈ��) �� �����Ӱ� Ȱ��

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    float age;
    string birthday;
};

int main() {
    int student_num;

    // 1. ����ڿ��� �л� �� �Է� �ޱ�
    cout << "�л� ���� �Է��ϼ���: ";
    cin >> student_num;
    cin.ignore();

    vector<Student> students;

    // 2. �л� �� ��ŭ ���� �Է� �ޱ�
    for (int i = 0; i < student_num; i++) 
    {
        string student_info;
        cout << "�л� " << i + 1 << " ���� �Է� (�̸�,����,����(0000.00.00)): ";
        getline(cin, student_info);

        stringstream ss(student_info); // ������ ���� ���� ����
        string name, birthday;
        float age;

        // ������ �ƴ� ��ǥ(,)�� �������� ���ڿ��� ������ �� ������ ����
        getline(ss, name, ','); // ��ǥ�� ���ö����� �а� name���� ����, ��ǥ ����
        ss >> age; // �� ���� age�� ����
        ss.ignore(); // ��ǥ ����
        getline(ss, birthday); // ������ birthday ����

        // Student ����ü�� ���� ����
        Student student{ name, age, birthday };
        students.push_back(student); // students ���Ϳ� ����
    }

    students.size();

    // ���� ���
    cout << "\n<�л� ����>" << endl;
    for (int i = 0; i < student_num; i++) 
    {
        cout << "�л� " << i + 1 << endl;
        cout << "�̸�: " << students[i].name << endl;
        cout << "����: " << students[i].age << endl;
        cout << "����: " << students[i].birthday << "\n" << endl;
    }

    // ��� ���� ���
    float sum_age = 0;
    for (int i = 0; i < students.size(); i++)
    {
        sum_age += students[i].age;
    }
    cout << "\n��ճ��� : " << sum_age / student_num << endl;

    // ���� ���� ���� ���
    string old_age = students[0].birthday; // �ʱ�ȭ
    for (int i = 1; i < students.size(); i++)
    {
        if (students[i].birthday < old_age) // ���� ������ �� ���� ��� ������Ʈ
        {
            old_age = students[i].birthday;
        }
    }
    cout << "\n���� ���� ���� : " << old_age << "\n" << endl;

    return 0;
}
