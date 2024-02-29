#include <iostream>
using namespace std;

typedef struct tanInfo {
	char szName[32];
	int iAttack;
	int iHp;
	int iMaxHp;
	int iLevel;
	int iExp;
	int iMaxExp;
}INFO;

INFO* Select_Job();
void Create_Object(INFO** ppInfo, const char* pName, int iAttack, int iMaxHp, int iLevel = 1, int iExp = 0);
bool Load_Data(INFO** ppPlayer);
bool Save_Data(INFO* pPlayer);
void MainGame(INFO* pInfo);
void Render(INFO* pInfo, bool bChoice = true);
int Fight(INFO* pPlayer, INFO* pMonster);
void Level_Up(INFO* pPlayer, int iExp);

int main() {
	INFO* pPlayer = Select_Job();

	if (!pPlayer) {
		return 0;
	}

	MainGame(pPlayer);

	if (nullptr != pPlayer) {
		delete pPlayer;
		pPlayer = nullptr;
	}
}

INFO* Select_Job()
{
	int iInput(0);
	INFO* pTemp = nullptr;
	bool bSelect(false);

	while (!bSelect) {
		system("cls");

		cout << "1. 전사, 2. 마법사, 3. 도적, 4. 불러오기, 5. 끝내기\n";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Create_Object(&pTemp, "전사", 10, 100);
			bSelect = true;
			break;
		case 2: 
			Create_Object(&pTemp, "마법사", 10, 100);
			bSelect = true;
			break;
		case 3:
			Create_Object(&pTemp, "도적", 10, 100);
			bSelect = true;
			break;
		case 4:
			bSelect = Load_Data(&pTemp);
		case 5:
			cout << "게임을 종료합니다.\n";
			bSelect = true;
			break;
		default:
			cout << "잘못된 입력입니다.\n";
			break;
		}
		system("pause");
	}
	return pTemp;
}

void Create_Object(INFO** ppInfo, const char* pName, int iAttack, int iMaxHp, int iLevel, int iExp)
{
	*ppInfo = new INFO;
	strcpy_s((*ppInfo)->szName, sizeof((*ppInfo)->szName), pName);

	(*ppInfo)->iAttack = iAttack;
	(*ppInfo)->iExp = iExp;
	(*ppInfo)->iHp = iMaxHp;
	(*ppInfo)->iMaxHp = iMaxHp;
	(*ppInfo)->iLevel = iLevel;
	(*ppInfo)->iMaxExp = 100;
}

bool Load_Data(INFO** ppPlayer)
{
	FILE* pFile = nullptr;
	*ppPlayer = new INFO;
	errno_t err = fopen_s(&pFile, "../Save.txt", "rb");

	if (0 == err) {
		fread((*ppPlayer), sizeof(INFO), 1, pFile);
		cout << "불러오기 성공\n";
		fclose(pFile);
		system("pause");
		return true;
	}
	else {
		cout << "저장 실패\n";
	}
	return false;
}

bool Save_Data(INFO* pPlayer)
{
	FILE* pFile = nullptr;
	errno_t err = fopen_s(&pFile, "../Save.txt", "wb");
	if (0 == err) {
		fwrite(pPlayer, sizeof(INFO), 1, pFile);
		cout << "저장 성공\n";
		fclose(pFile);
		return true;
	}
	else {
		cout << "저장 실패\n";
	}
	return false;
}

void MainGame(INFO* pInfo)
{
	int iInput(0);
	INFO* pMonster = nullptr;
	bool bSave = false;

	while (true) {
		system("cls");
		Render(pInfo);

		cout << "1, 초급, 2. 중급, 3. 고급, 4. 저장하기 5. 나가기\n";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Create_Object(&pMonster, "초급", 3, 30, 1, 10);
			break;
		case 2:
			Create_Object(&pMonster, "중급", 6, 60, 2, 20);
			break;
		case 3:
			Create_Object(&pMonster, "고급", 9, 90, 3, 30);
			break;
		case 4:
			bSave = Save_Data(pInfo);
			break;
		case 5:
			cout << "게임을 종료합니다" << endl;
			return;
		default:
			cout << "잘못 입력했습니다.\n";
			break;
		}
		if (bSave) {
			bSave = false;
			continue;
		}

		int iResult = Fight(pInfo, pMonster);
	}
}

void Render(INFO* pInfo, bool bChoice)
{
	cout << "-----------------------------------\n";
	cout << "이름: " << pInfo->szName << "\t레벨: " << pInfo->iLevel << endl;
	cout << "공격력: " << pInfo->iAttack << "\t체력: " << pInfo->iHp << " / " << pInfo->iMaxHp << endl;
	
	if (bChoice) {
		cout << "경험치: " << pInfo->iExp << "\t최대 경험치: " << pInfo->iMaxExp << endl;
	}
}

int Fight(INFO* pPlayer, INFO* pMonster)
{
	int iInput(0);
	while (true) {
		system("cls");
		Render(pPlayer);
		Render(pMonster);

		cout << "1. 공격, 2. 도망\n";
		cin >> iInput;

		if (iInput == 1) {
			pMonster->iHp -= pPlayer->iAttack;
			pPlayer->iHp -= pMonster->iAttack;
			if (0 >= pPlayer->iHp) {
				cout << "플레이어 사망" << endl;
				pPlayer->iHp = pPlayer->iMaxHp;
				system("pause");
				return 0;
			}
			if (0 >= pMonster->iHp) {
				cout << "승리" << endl;
				Level_Up(pPlayer, pMonster->iExp);
				system("pause");
				return 0;
			}
		}
	}
}

void Level_Up(INFO* pPlayer, int iExp)
{
	pPlayer->iExp += iExp;
	if(pPlayer->iExp >= pPlayer->iMaxExp) {
		if (!strcmp(pPlayer->szName, "전사")) {
			pPlayer->iAttack += 10;
			pPlayer->iMaxHp += 20;
			pPlayer->iMaxExp += 50;
		}
		else if (!strcmp(pPlayer->szName, "마법사")) {
			pPlayer->iAttack += 20;
			pPlayer->iMaxHp += 10;
			pPlayer->iMaxExp += 50;
		}
		else if (!strcmp(pPlayer->szName, "도적")) {
			pPlayer->iAttack += 15;
			pPlayer->iMaxHp += 15;
			pPlayer->iMaxExp += 50;
		}

		pPlayer->iLevel++;
		pPlayer->iHp = pPlayer->iMaxHp;
		pPlayer->iExp = 0;

		cout << "레벨업\n";
	}
}
