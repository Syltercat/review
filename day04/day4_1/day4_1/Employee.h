#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
public:
	Employee(const char* const, const char* const);	// paramenter 앞의 const: 포인터 안에 들어있는 값을 바꿀 수 없게 함.
													// 포인터 뒤의 const: paramenter의 포인터를 고칠 수 없게 함.
	~Employee();
	const char* getFirstName() const;	// 함수 끝 const: 멤버 함수로 멤버 변수를 바꿀 수 없게ㅊ하기 위함.
										//				  함수가 어떤 멤버 데이터도 수정하지 않겠다는 것을 의미
	const char* getLastName() const;	// 함수 앞 const: 멤버 함수로 반환된 포인터에 들어있는(포인터가 가르키는) 값을 바꿀 수 없게 함.
										//				  읽기 권한만 부여
	static int getCount();				// static 데이터를 사용하는 함수는 static 사용

private:
	char* firstName;
	char* lastName;
	static int count;
};
#endif