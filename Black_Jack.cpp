#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 52

// ShowCard
void ShowCard(int PlayerCard)
{
	if (PlayerCard < 13)
	{
		cout << "��";
	}
	else if (PlayerCard < 26 && PlayerCard >= 13)
	{
		cout << "��";
	}
	else if (PlayerCard < 39 && PlayerCard >= 26)
	{
		cout << "��";
	}
	else
	{
		cout << "��";
	}

	if (PlayerCard % 13 == 0)
	{
		cout << "A";
	}
	else if (PlayerCard % 13 == 10)
	{
		cout << "J";
	}
	else if (PlayerCard % 13 == 11)
	{
		cout << "Q";
	}
	else if (PlayerCard % 13 == 12)
	{
		cout << "K";
	}
	else
	{
		cout << (PlayerCard % 13) + 1;
	}
}

// ���� �Լ�
int main(void)
{
	int i = 0;	// �ݺ��� ��� ���� ����
	int k = 0;  // �߰� ������ ���� ���� ����
	int ANum[1] = { 0 }; // ������ ������ �а� A���� ��� �� �迭
	int j0 = 0; // �ʱ�ȭ �� ��� ���� �� ����
	int j1 = 0;	// �÷��̾� �迭 ������ �� �� ����, A ������ ���� j1~j4���� �߰� ����
	int j2 = 0;
	int j3 = 0; // 3�� �̻� �ÿ� ���� ����
	int j4 = 0;
	int t = 0;
	int n = 0;	// �÷��̾� ��
	char InitialDraw;
	int AddCard1 = 0;
	int AddCard2 = 0;
	int AddCard3 = 0;	// 3�� �̻� �ÿ� ���� ����
	int AddCard4 = 0;
	char AddChoice;
	int ACardChoice;
	int Random1 = 0;
	int Random2 = 0;
	int Deck[52] = { 0, };
	int Dealer[11] = { 0, };
	int Player1[11] = { 0, };	// 21�� �ѱ� ������ ���� �� �ִ� �ִ� ī�� ��
	int Player2[11] = { 0, };
	int Player3[11] = { 0, };	// 3�� �̻� �ÿ� ���� ����
	int Player4[11] = { 0, };
	int ResultD = 0;  // ī�� ��
	int Result1 = 0;
	int Result2 = 0;
	int Result3 = 0;	// 3�� �̻� �ÿ� ���� ����
	int Result4 = 0;

	// ���� �ɱ�
	srand((unsigned int)time(NULL));

	cout << "�÷��̾� ���� �Է����ֽʽÿ�(1~2) : ";
	cin >> n;
	cout << endl;

	// �ʱ�ȭ, ���� 0���� 51����, *�Ŀ� 13�� %�� ����ϱ� ������ i+1�� �ƴ� i�� �ʱ�ȭ*
	for (i = 0; i < MAX; i++)
	{
		Deck[i] = i;
	}

	// �÷��̾� ���� 1�� ���
	// AI�� �׳� 
	// 2�� ���������, �߰��� AI�� A���� ��� �������� �����ؾ���
	// 2�� �ٸ��� A���� �߰��� �Ǻ��ؾ��ؼ� ������ �ٲ���Ѵ�.

	if (n == 1)
	{
		// ����
		for (i = 0; i < MAX * 5; i++)	// �� ��� 
		{
			Random1 = rand() % MAX;
			Random2 = rand() % MAX;

			t = Deck[Random1];
			Deck[Random1] = Deck[Random2];
			Deck[Random2] = t;
		}

		while (1)
		{
			cout << "�ʱ� ī�带 ��ο��Ͻ÷��� D �Ǵ� d�� �Է��Ͻʽÿ�: ";
			cin >> InitialDraw;

			if (InitialDraw == 'D' || InitialDraw == 'd')
			{
				break;
			}
			else
			{
				cout << "�߸��� �Է��Դϴ�" << endl;
			}
		}

		cout << endl;

		cout << setw(8) << " ";
		cout << setw(11) << "Dealer";
		cout << setw(11) << "Player1";
		cout << endl;

		// �ʱ� ī�� ��� �� 2�� ���


		for (i = 0; i < 2; i = i + 2)	// i�� 2�� �������Ѽ� �й�
		{
			cout << "Draw " << j0 + 1;

			Dealer[j1] = Deck[i];
			Player1[j2] = Deck[i + 1];

			cout << setw(10) << " ";   // ������ ù��° ī�带 ����� �صд�
			cout << setw(9) << " ";
			ShowCard(Player1[0]);
			cout << endl;

			j0 = j0 + 1;
			j1 = j1 + 1;
			j2 = j2 + 1;
		}

		for (i = 2; i < 4; i = i + 2)	// i�� 2�� �������Ѽ� �й�
		{
			cout << "Draw " << j0 + 1;

			Dealer[j1] = Deck[i];
			Player1[j2] = Deck[i + 1];

			cout << setw(8) << " ";
			ShowCard(Dealer[1]);
			cout << setw(8) << " ";
			ShowCard(Player1[1]);
			cout << endl;

			j0 = j0 + 1;
			j1 = j1 + 1;
			j2 = j2 + 1;
		}

		// ���Ŀ� ���� ����ǹǷ� ����� ���� ī���� ũ�⸦ �̸� �����صξ���.
		ANum[0] = Dealer[0];

		// �߰� ī�� ��ο�
		for (i = 4; i < 22; i = i + 2)	// 2�� ������ ���� 9�� �� �����ϵ��� ����
		{
			if (AddCard1 < 9)
			{
				for (k = 0; k < j1; k++)
				{
					if (Dealer[k] % 13 == 0)
					{
						Dealer[k] = 10;
					}

					ResultD += (Dealer[k] % 13) + 1;
				}

				if (ResultD <= 16)   // ������ +1�� ���� �������� �Ϸ��� ������ 2�� ���� 14�� �־��� ������
				{					 // �߰� ���� ���ʹ� �������� ������ ���� 1�� �ñ� ������ �������� ���ִ°� ����.
					Dealer[j1] = Deck[i];	// i+1�� ��ġ�� �ʰ� �ö󰡵��� �ʱ�ȭ
					cout << "Draw " << j1 + 1;
					cout << setw(8) << " ";
					ShowCard(Dealer[j1]);
					AddCard1++;
					j1 = j1 + 1;
					cout << endl;
					ResultD = 0;	// ���� ���� ��꿡�� ���� ResultD�� ���� ���� �ʵ��� �ʱ�ȭ
				}

				else
				{
					AddChoice = 0;
					AddCard1 = 11;
				}

				cout << endl;
			}

			if (AddCard2 < 9)
			{
				cout << endl;
				cout << "<Player1>�� �߰� Draw �Ͻðڽ��ϱ�? (�׷���:Y,y or �ƴϴ�:�ƹ�Ű): ";
				cin >> AddChoice;
				if (AddChoice == 'Y' || AddChoice == 'y')
				{
					cout << endl;
					Player1[j2] = Deck[i + 1];	// ù ���۽� j=2�� ����
					cout << "Draw " << j2 + 1;  // i+1�� ��ġ�� �ʰ� �ö󰡵��� �ʱ�ȭ
					cout << setw(19) << " ";
					ShowCard(Player1[j2]);
					cout << endl;
					AddCard2++;
					j2 = j2 + 1;	// �߰����� ��� Player1�� �� ����
				}

				else
				{
					cout << endl;
					AddChoice = 0;	// ����ϰ� Y,y�� 0���� �ʱ�ȭ
					AddCard2 = 11;	// �ִ밪���� �ʱ�ȭ�ؼ� ������������ ����
				}
			}

			if (AddCard1 == 11 && AddCard2 == 11)
			{
				i = MAX;	// �� �� �����ÿ��� ������������ �ʱ�ȭ, MAX�� �ǹ��־ �ʱ�ȭ
			}
		}

		// ���� ���� 0~12 ���̷� ���߰� Arr[0]~[12]���� 0~12�� �ʱ�ȭ
		for (i = 0; i < 11; i++)
		{
			Dealer[i] = (Dealer[i] % 13);
			Player1[i] = (Player1[i] % 13);
		}
		// ���Ŀ� 0~12�� ������ �ʱ�ȭ �Ǿ��ִ� ����, ��������� 0~12�� �ʱ�ȭ�ؾ��Ѵ�.

		for (i = 0; i < 11; i++)	// �÷��̾� ī�� �ִ� 11��, ����� ���� �ٵ��
		{
			if (Dealer[i] % 13 > 9)	// Dealer, J,Q,K ���� 9�� �ʱ�ȭ -> �Ŀ� 10���� �ٲ� ��
			{
				Dealer[i] = 9;
			}

			if (Player1[i] % 13 > 9)	// Player1, J,Q,K ���� 9�� �ʱ�ȭ
			{
				Player1[i] = 9;
			}
		}

		for (i = 0; i < j2; i++)	// j1��ŭ �ݺ������Ƿ� j1-1�� �迭���� A�� �ִ��� �˻�
		{
			if (Player1[i] % 13 == 0)	// ���� �� Player1, A ī�� 1 or 11 ����
			{
				cout << endl;
				cout << "<Player1>�� A ī�带 1, 11 �߿� �������� ����Ͻðڽ��ϱ�? ";
				cin >> ACardChoice;

				if (ACardChoice == 11)	// 11�� �� ��� A�� 10���� �ʱ�ȭ -> �Ŀ� 11�� �ٲ� ��
				{
					Player1[i] = 10;
					ACardChoice = 0;
				}

				cout << endl;
			}
		}

		for (i = 0; i < 11; i++)	// ���� ���� ����ؾ��ϱ� ������ 1~10 ������ �ʱ�ȭ.
		{
			Dealer[i] = Dealer[i] + 1;
			Player1[i] = Player1[i] + 1;
		}

		ResultD = 0;	// �ö󰬴� ������ 0���� �ʱ�ȭ�ؼ� �ٽ� ���

		for (i = 0; i < j1; i++)
		{
			ResultD += Dealer[i];
		}

		for (i = 0; i < j2; i++)
		{
			Result1 += Player1[i];
		}

		// ���� ���� ī�� ���
		cout << "Hidden Card: ";
		ShowCard(ANum[0]);
		cout << endl;

		// ����, �÷��̾� �� ���
		cout << "<Dealer> : " << ResultD;
		if (ResultD > 21)	// 21 �ʰ��� Burst ���
		{
			cout << " Burst!!" << endl;
		}

		else
		{
			cout << endl;
		}

		cout << "<Player1> : " << Result1;
		if (Result1 > 21)
		{
			cout << " Burst!!" << endl;
		}

		else
		{
			cout << endl;
		}

		cout << endl;

		// ��� ���
		if (ResultD > 21 && Result1 > 21)	// �� �� burst�� ���
		{
			cout << "Burst Draw!!" << endl;
		}

		else if (ResultD == Result1)	// ���� ���
		{
			if (j1 > j2)
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}

			else if (j1 < j2)
			{
				cout << "<Dealer> Winner Winner Chicken Dinner!" << endl;
			}

			else
			{
				cout << "Draw!!" << endl;
			}
		}

		// �� �� �ϳ��� burst, �� �� burst�� �ƴ� ��� �߿�, ���� ���� Result1�� Result2�� ���� ��
		else if (ResultD > Result1)
		{
			if (ResultD <= 21)   // ResultD>Result1 �� ��쿡 ResultD�� ����Ʈ�� �ƴϸ� Result1�� ����Ʈ�� �ƴϴ�.
			{
				cout << "<Dealer> Winner Winner Chicken Dinner!" << endl;
			}

			else   // ResultD�� burst�� ��� Result1�� burst�� �ƴϴ�.
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}
		}

		else   // ResultD < Result1 �� ���� �� �� �ϳ��� burst, �� �� burst�� �ƴ� ��찡 �����ִ�.
		{
			if (Result1 <= 21)
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}

			else   // Result1�� burst�� ��� Dealer�� burst�� �ƴϴ�.
			{
				cout << "<Dealer> Winner Winner Chicken Dinner!" << endl;
			}
		}
	}










	// �÷��̾� ���� 2�� ���
	if (n == 2)
	{
		// ����
		for (i = 0; i < MAX * 5; i++)	// �� ��� 
		{
			Random1 = rand() % MAX;
			Random2 = rand() % MAX;

			t = Deck[Random1];
			Deck[Random1] = Deck[Random2];
			Deck[Random2] = t;
		}

		while (1)
		{
			cout << "�ʱ� ī�带 ��ο��Ͻ÷��� D �Ǵ� d�� �Է��Ͻʽÿ�: ";
			cin >> InitialDraw;

			if (InitialDraw == 'D' || InitialDraw == 'd')
			{
				break;
			}
			else
			{
				cout << "�߸��� �Է��Դϴ�" << endl;
			}
		}

		cout << endl;

		cout << setw(8) << " ";
		cout << setw(11) << "Player1";
		cout << setw(11) << "Player2";
		cout << endl;

		// �ʱ� ī�� ��� �� 2�� ���
		for (i = 0; i < 4; i = i + 2)	// i�� 2�� �������Ѽ� �й�
		{
			cout << "Draw " << j0 + 1;

			Player1[j1] = Deck[i];
			Player2[j2] = Deck[i + 1];

			cout << setw(7) << " ";
			ShowCard(Player1[j1]);
			cout << setw(9) << " ";
			ShowCard(Player2[j2]);
			cout << endl;

			j0 = j0 + 1;
			j1 = j1 + 1;
			j2 = j2 + 1;
		}

		cout << endl;

		// �߰� ī�� ��ο�
		for (i = 4; i < 22; i = i + 2)	// 2�� ������ ���� 9�� �� �����ϵ��� ����
		{
			if (AddCard1 < 9)
			{
				cout << "<Player1>�� �߰� Draw �Ͻðڽ��ϱ�? (�׷���:Y,y or �ƴϴ�:�ƹ�Ű): ";
				cin >> AddChoice;
				if (AddChoice == 'Y' || AddChoice == 'y')
				{
					cout << endl;
					Player1[j1] = Deck[i];	// ù ���۽� j=2�� ����
					cout << "Draw " << j1 + 1;
					cout << setw(7) << " ";
					ShowCard(Player1[j1]);
					AddCard1++;
					j1 = j1 + 1;	// �߰����� ��� Player1�� �� ����
					cout << endl;
				}

				else
				{
					AddChoice = 0;	// ����ϰ� Y,y�� 0���� �ʱ�ȭ
					AddCard1 = 11;	// �ִ밪���� �ʱ�ȭ�ؼ� ������������ ����
				}

				cout << endl;
			}

			if (AddCard2 < 9)
			{
				cout << "<Player2>�� �߰� Draw �Ͻðڽ��ϱ�? (�׷���:Y,y or �ƴϴ�:�ƹ�Ű): ";
				cin >> AddChoice;
				if (AddChoice == 'Y' || AddChoice == 'y')
				{
					cout << endl;
					Player2[j2] = Deck[i + 1];	// i+1�� ��ġ�� �ʰ� �ö󰡵��� �ʱ�ȭ
					cout << "Draw " << j2 + 1;
					cout << setw(19) << " ";
					ShowCard(Player2[j2]);
					AddCard2++;
					j2 = j2 + 1;
					cout << endl;
				}

				else
				{
					AddChoice = 0;
					AddCard2 = 11;
				}

				cout << endl;
			}

			if (AddCard1 == 11 && AddCard2 == 11)
			{
				i = MAX;	// �� �� �����ÿ��� ������������ �ʱ�ȭ, MAX�� �ǹ��־ �ʱ�ȭ
			}
		}

		// ���� ���� 0~12 ���̷� ���߰� Player[0]~[12]���� 0~12�� �ʱ�ȭ
		for (i = 0; i < 11; i++)
		{
			Player1[i] = (Player1[i] % 13);
			Player2[i] = (Player2[i] % 13);
		}
		// ���Ŀ� 0~12�� ������ �ʱ�ȭ �Ǿ��ִ� ����, ��������� 0~12�� �ʱ�ȭ�ؾ��Ѵ�.


		for (i = 0; i < 11; i++)	// �÷��̾� ī�� �ִ� 11��, ����� ���� �ٵ��
		{
			if (Player1[i] % 13 > 9)	// Player1, J,Q,K ���� 9�� �ʱ�ȭ -> �Ŀ� 10���� �ٲ� ��
			{
				Player1[i] = 9;
			}

			if (Player2[i] % 13 > 9)	// Player2, J,Q,K ���� 9�� �ʱ�ȭ
			{
				Player2[i] = 9;
			}
		}

		cout << endl;

		for (i = 0; i < j1; i++)	// j1��ŭ �ݺ������Ƿ� j1-1�� �迭���� A�� �ִ��� �˻�
		{
			if (Player1[i] % 13 == 0)	// ���� �� Player1, A ī�� 1 or 11 ����
			{
				cout << "<Player1>�� A ī�带 1, 11 �߿� �������� ����Ͻðڽ��ϱ�? ";
				cin >> ACardChoice;

				cout << ACardChoice << endl;

				if (ACardChoice == 11)	// 11�� �� ��� A�� 10���� �ʱ�ȭ -> �Ŀ� 11�� �ٲ� ��
				{
					Player1[i] = 10;
					ACardChoice = 0;
				}

				cout << endl;
			}
		}

		for (i = 0; i < j2; i++)
		{
			if (Player2[i] % 13 == 0)	// Player1, A ī�� 1 or 11 ����
			{
				cout << "<Player2>�� A ī�带 1, 11 �߿� �������� ����Ͻðڽ��ϱ�? ";
				cin >> ACardChoice;

				if (ACardChoice == 11)
				{
					Player2[i] = 10;
					ACardChoice = 0;
				}

				cout << endl;
			}
		}

		for (i = 0; i < 11; i++)	// ���� ���� ����ؾ��ϱ� ������ 1~10 ������ �ʱ�ȭ.
		{
			Player1[i] = Player1[i] + 1;
			Player2[i] = Player2[i] + 1;
		}

		for (i = 0; i < j1; i++)
		{
			Result1 += Player1[i];
		}

		for (i = 0; i < j2; i++)
		{
			Result2 += Player2[i];
		}

		cout << "<Player1> : " << Result1;
		if (Result1 > 21)	// 21 �ʰ��� Burst ���
		{
			cout << " Burst!!" << endl;
		}

		else
		{
			cout << endl;
		}

		cout << "<Player2> : " << Result2;
		if (Result2 > 21)
		{
			cout << " Burst!!" << endl;
		}

		else
		{
			cout << endl;
		}

		cout << endl;

		if (Result1 > 21 && Result2 > 21)	// �� �� burst�� ���
		{
			cout << "Burst Draw!!" << endl;
		}

		else if (Result1 == Result2)	// ���� ���, ���� ī���� ������ ����
		{
			if (j1 > j2)
			{
				cout << "<Player2> Winner Winner Chicken Dinner!" << endl;
			}

			else if (j1 < j2)
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}

			else
			{
				cout << "Draw!!" << endl;
			}
		}

		// �� �� �ϳ��� burst, �� �� burst�� �ƴ� ��� �߿�, ���� ���� Result1�� Result2�� ���� ��
		else if (Result1 > Result2)
		{
			if (Result1 <= 21)   // Result1>Result2 �� ��쿡 Result1�� ����Ʈ�� �ƴϸ� Result2�� ����Ʈ�� �ƴϴ�.
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}

			else   // Result1�� burst�� ��� Result2�� burst�� �ƴϴ�.
			{
				cout << "<Player2> Winner Winner Chicken Dinner!" << endl;
			}
		}

		else   // Result < Result2 �� ���� �� �� �ϳ��� burst, �� �� burst�� �ƴ� ��찡 �����ִ�.
		{
			if (Result2 <= 21)
			{
				cout << "<Player2> Winner Winner Chicken Dinner!" << endl;
			}

			else   // Result2�� burst�� ��� Result1�� burst�� �ƴϴ�.
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}
		}
	}

	return 0;
}