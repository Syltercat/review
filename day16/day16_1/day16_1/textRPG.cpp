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

		cout << "1. ����, 2. ������, 3. ����, 4. �ҷ�����, 5. ������\n";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Create_Object(&pTemp, "����", 10, 100);
			bSelect = true;
			break;
		case 2: 
			Create_Object(&pTemp, "������", 10, 100);
			bSelect = true;
			break;
		case 3:
			Create_Object(&pTemp, "����", 10, 100);
			bSelect = true;
			break;
		case 4:
			bSelect = Load_Data(&pTemp);
		case 5:
			cout << "������ �����մϴ�.\n";
			bSelect = true;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�.\n";
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
		cout << "�ҷ����� ����\n";
		fclose(pFile);
		system("pause");
		return true;
	}
	else {
		cout << "���� ����\n";
	}
	return false;
}

bool Save_Data(INFO* pPlayer)
{
	FILE* pFile = nullptr;
	errno_t err = fopen_s(&pFile, "../Save.txt", "wb");
	if (0 == err) {
		fwrite(pPlayer, sizeof(INFO), 1, pFile);
		cout << "���� ����\n";
		fclose(pFile);
		return true;
	}
	else {
		cout << "���� ����\n";
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

		cout << "1, �ʱ�, 2. �߱�, 3. ���, 4. �����ϱ� 5. ������\n";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Create_Object(&pMonster, "�ʱ�", 3, 30, 1, 10);
			break;
		case 2:
			Create_Object(&pMonster, "�߱�", 6, 60, 2, 20);
			break;
		case 3:
			Create_Object(&pMonster, "���", 9, 90, 3, 30);
			break;
		case 4:
			bSave = Save_Data(pInfo);
			break;
		case 5:
			cout << "������ �����մϴ�" << endl;
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�.\n";
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
	cout << "�̸�: " << pInfo->szName << "\t����: " << pInfo->iLevel << endl;
	cout << "���ݷ�: " << pInfo->iAttack << "\tü��: " << pInfo->iHp << " / " << pInfo->iMaxHp << endl;
	
	if (bChoice) {
		cout << "����ġ: " << pInfo->iExp << "\t�ִ� ����ġ: " << pInfo->iMaxExp << endl;
	}
}

int Fight(INFO* pPlayer, INFO* pMonster)
{
	int iInput(0);
	while (true) {
		system("cls");
		Render(pPlayer);
		Render(pMonster);

		cout << "1. ����, 2. ����\n";
		cin >> iInput;

		if (iInput == 1) {
			pMonster->iHp -= pPlayer->iAttack;
			pPlayer->iHp -= pMonster->iAttack;
			if (0 >= pPlayer->iHp) {
				cout << "�÷��̾� ���" << endl;
				pPlayer->iHp = pPlayer->iMaxHp;
				system("pause");
				return 0;
			}
			if (0 >= pMonster->iHp) {
				cout << "�¸�" << endl;
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
		if (!strcmp(pPlayer->szName, "����")) {
			pPlayer->iAttack += 10;
			pPlayer->iMaxHp += 20;
			pPlayer->iMaxExp += 50;
		}
		else if (!strcmp(pPlayer->szName, "������")) {
			pPlayer->iAttack += 20;
			pPlayer->iMaxHp += 10;
			pPlayer->iMaxExp += 50;
		}
		else if (!strcmp(pPlayer->szName, "����")) {
			pPlayer->iAttack += 15;
			pPlayer->iMaxHp += 15;
			pPlayer->iMaxExp += 50;
		}

		pPlayer->iLevel++;
		pPlayer->iHp = pPlayer->iMaxHp;
		pPlayer->iExp = 0;

		cout << "������\n";
	}
}
