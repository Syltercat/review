// Inheritance

// 이론
/*
상속(is-a 관계): 소프트웨어 재사용을 위한 효과적인 방법이다.
	- 기존 클래스로 부터 새로운 클래스 생성
	(기존 클래스의 데이터 멤버와 멤버 함수를 상속, 새로운 데이터 멤버와 함수를 추가하여 구체화 할 수 있다.)

	- 기본 클래스(base class)로부터 상속받아 파생 클래스(Derived class)가 생성된다.
	- tree 형태의 계층 구조를 형성한다.

is-a와 has-a의 차이
	* is-a 관계 - 상속
		파생 클래스의 객체는 기본 클래스의 객체처럼 취급
		ex) 차는 탈 것이다.
	* has-a 관계 - 복합 관계
		객체가 다른 class의 객체를 멤버로 포함
		ex) 차에는 운전대가 있다.
		has-a 관계는 생성자의 초기화 list에서 초기화 해줘야 한다.

base class와 derived class
	- 기본 클래스는 파생 클래스보다 더 넓은 범위의 객체를 표현한다. 탈 것(base) > 차(derived)

public 상속
	- class AShape:public Shape -> AShape is a Shape
	  AShape 클래스가 Shape 클래스로부터 상속받음.
	- private 멤버에는 직접적으로 접근할 수 없지만 같이 상속되기 때문에 상속된 public 멤버 함수를 통해 접근 가능하다.

protected member
	- public과 private의 중간 단계
	- 기본 클래스와 파생 클래스 멤버를 통해 직접 접근이 가능하다.
*/

// inheritance hierarchy and (using protected data / private data)
/*
CommissionEmployee - BasePulsCommissionEmployee 상속 계층

CommissionEmployee
	- firstname, lastname, SSN, commission_rate(판매 수당), gross_sale_amount(영업량)

BasePlusCommissionEmployee
	- firstname, lastname, SSN, commission_rate, gross_sale_amount
	- 기본 봉급

<CommissionEmployee Class>
   [header]
	- public
		> 생성자
		> get / set
		> 멤버 함수: earnings(commission_rate * gross_sale_acount), print
	-private
		> firstname, lastname, SSN, commission_rate(판매 수당), gross_sale_amount(영업량)

상속을 사용하지 않는다면
<BasePlusCommissionEmployee>
   [header]
	- public
		> 생성자
		> get / set
		> 멤버 함수: earnings(commission_rate * gross_sale_acount), print
	-private
		> firstname, lastname, SSN, commission_rate(판매 수당), gross_sale_amount(영업량), baseSalary
	
	=> 이걸 다 처음부터 작성하고 변형해야 함. (duplicating)

상속을 사용하면 위의 과정을 생략 가능 (단, 생성자, 소멸자는 상속되지 않음.)
	=> 상속 후에는 추가할 멤버 함수와 멤버 데이터만 작성하면 됨. 
	(파생 클래스에서 함수를 재정의(override)하고 싶다면 "기본클래스이름::함수이름"으로 호출해야 함)

public 상속을 하면 protected data를 사용하는 경우와 private data를 사용하는 경우 두 가지로 나뉜다.
위의 경우는 private로 데이터 멤버를 선언했기 때문에 private data를 inheritance hierarchy에 사용하는 경우이다.

protected 상속: 기본 클래스 public과 protected 멤버 -> 파생 클래스의 protected 멤버
private 상속: 기본 클래스 public과 protected 멤버 -> 파생 클래스의 private 멤버

일반적으로 private data를 사용하기 때문에 protected data는 코드에 구현하지 않았다.
private data를 사용하는 이유는 다음과 같다.

* protected data 사용의 장/단점
   (장점)
	- 파생 class에서 기본 class의 데이터 멤버는 직접 접근이 가능하다.
	- 직접 접근이 가능하므로 set / get 호출이 필요 없기 때문에 수행 속도가 조금 향상된다.
   (단점)
	- set / get 함수를 사용하지 않기 때문에 유효성 체크가 불가능하다.
	  (일반적으로 set, get에 유효성을 검사하는 코드를 삽입하는데 이 부분이 없기 때문에 파생 클래스에 비정상적인 값이 할당될 수 있다.)
	- 파생 클래스 함수가 기본 클래스 구현에 더 의존적이게 되어 기본 클래스를 수정하면 파생 클래스 또한 수정해야 한다.
	  (부서지기 쉬운(fragile) 소프트웨어가 된다.

=> 위의 장단점을 보면 proected data를 사용하면 encapsulation의 원칙을 지킬 수 없게 된다.	  

	+)encapsulation => 정보 은닉: 클래스를 패키징하여 내부 구현을 숨겨서 객체의 응집도와 독립성을 높일 수 있다.
								  이를 객체의 모듈화라고 하는데 객체의 모듈화가 잘 되어있다면 모듈 단위의 재사용이 용이하다.

그러나 기본 클래스의 private 멤버는 직접 접근이 불가능하다.
기본 클래스의 public 멤버 함수를 통해서 접근해야 한다.
								  
*/

#include <iostream>
#include <iomanip>	// setprecision(소수부 출력 범위 지정) 사용을 위해 include
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

int main() {
	CommissionEmployee employee("aa", "Bob", "123-123", 10000, 0.06);
	cout << fixed << setprecision(2);

	employee.setCommissionRate(8000);
	employee.setGrossSale(0.1);
	
	employee.print();
	cout << employee.earnings() << endl;
	cout << endl;

	// 파생 class
	BasePlusCommissionEmployee employee2("aa2", "Bob2", "234-234", 5000, 0.04, 300);
	employee2.print();
	cout << employee2.earnings() << endl;

	employee2.setBaseSalary(1000);
	cout << endl;
	employee2.print();
	cout << employee2.earnings() << endl;

	return 0;
}