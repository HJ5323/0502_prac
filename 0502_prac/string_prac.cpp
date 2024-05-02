// 1. 사용자에게 몇 명의 학생을 입력할 것인지 묻기
// 2. 학생 수 만큼 "이름, 나이, 생일" 순서로 한번에 입력 받기
// 3. 1) 학생 정보 출력, 2) 평균나이, 3) 가장 빠른 생일, 4) 프로그램 종료, 네 가지 기능을 모두 구현
// 4. 지금까지 배운 자료구조(배열, 벡터, 리스트), 문자열(스트링) 등 자유롭게 활용

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

    // 1. 사용자에게 학생 수 입력 받기
    cout << "학생 수를 입력하세요: ";
    cin >> student_num;
    cin.ignore();

    vector<Student> students;

    // 2. 학생 수 만큼 정보 입력 받기
    for (int i = 0; i < student_num; i++) 
    {
        string student_info;
        cout << "학생 " << i + 1 << " 정보 입력 (이름,나이,생일(0000.00.00)): ";
        getline(cin, student_info);

        stringstream ss(student_info); // 공백을 따라 변수 나눔
        string name, birthday;
        float age;

        // 공백이 아닌 쉼표(,)를 기준으로 문자열을 나누고 각 정보를 저장
        getline(ss, name, ','); // 쉼표가 나올때까지 읽고 name으로 저장, 쉼표 버림
        ss >> age; // 그 다음 age로 저장
        ss.ignore(); // 쉼표 버림
        getline(ss, birthday); // 나머지 birthday 저장

        // Student 구조체에 정보 저장
        Student student{ name, age, birthday };
        students.push_back(student); // students 벡터에 저장
    }

    students.size();

    // 정보 출력
    cout << "\n<학생 정보>" << endl;
    for (int i = 0; i < student_num; i++) 
    {
        cout << "학생 " << i + 1 << endl;
        cout << "이름: " << students[i].name << endl;
        cout << "나이: " << students[i].age << endl;
        cout << "생일: " << students[i].birthday << "\n" << endl;
    }

    // 평균 나이 출력
    float sum_age = 0;
    for (int i = 0; i < students.size(); i++)
    {
        sum_age += students[i].age;
    }
    cout << "\n평균나이 : " << sum_age / student_num << endl;

    // 가장 빠른 생일 출력
    string old_age = students[0].birthday; // 초기화
    for (int i = 1; i < students.size(); i++)
    {
        if (students[i].birthday < old_age) // 현재 생일이 더 빠른 경우 업데이트
        {
            old_age = students[i].birthday;
        }
    }
    cout << "\n가장 빠른 생일 : " << old_age << "\n" << endl;

    return 0;
}
