#pragma region Big-O notation
// Big-O notation: 입력의 크기에 대한 Asymptotic Analysis (점근적 분석)

// 복잡도 분류
/*
O(n^n)		: exponential complexity (이 복잡도는 절대 지양)
O(n^2)		: quadratic complexity (ploynomial complexity의 하나)
O(nlogn)	: 
O(n)		: linear complexity
O(logn)		: logarithmic complexity
O(loglogn)	: 
O(1)		: constant complexity
*/

//Big-O notation
/*
"최악의 경우에도 이 정도 시간이면 된다."라는 복잡도 증가율의 상한(upper bound)를 나타냄.
 보통은 tight upper bound로 나타냄

f(n) <= c * g(n) for n >= n0

-> g(n) = Big-O notation 복잡도, n0는 입력의 개수, int형(1보다 큰 경우여야 함.)
   c는 복잡도 앞의 계수, n은 복잡도 뒤의 상수
*/

// +)
// Big-Omega notation: 최소한 이만한 시간은 걸린다. Big-O의 반대 개념
// Big-Theta notation: Omega(f)인 문제에 O(f)인 알고리즘이 존재하는 경우, 상한과 하한이 마주침으로써 더 이상 나은 알고리즘을
//					   찾을 수 없을 경우에 사용한다.

#pragma endregion