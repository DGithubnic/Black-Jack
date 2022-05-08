#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 52

// ShowCard
void ShowCard(int PlayerCard)
{
	if (PlayerCard < 13)
	{
		cout << "♥";
	}
	else if (PlayerCard < 26 && PlayerCard >= 13)
	{
		cout << "♠";
	}
	else if (PlayerCard < 39 && PlayerCard >= 26)
	{
		cout << "♣";
	}
	else
	{
		cout << "◆";
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

// 메인 함수
int main(void)
{
	int i = 0;	// 반복문 제어를 위한 변수
	int k = 0;  // 중간 검증을 위한 제어 변수
	int ANum[1] = { 0 }; // 딜러의 숨겨진 패가 A였을 경우 쓸 배열
	int j0 = 0; // 초기화 시 제어를 위해 쓸 변수
	int j1 = 0;	// 플레이어 배열 저장할 때 쓸 변수, A 검증을 위해 j1~j4까지 추가 선언
	int j2 = 0;
	int j3 = 0; // 3인 이상 시에 쓰일 변수
	int j4 = 0;
	int t = 0;
	int n = 0;	// 플레이어 수
	char InitialDraw;
	int AddCard1 = 0;
	int AddCard2 = 0;
	int AddCard3 = 0;	// 3인 이상 시에 쓰일 변수
	int AddCard4 = 0;
	char AddChoice;
	int ACardChoice;
	int Random1 = 0;
	int Random2 = 0;
	int Deck[52] = { 0, };
	int Dealer[11] = { 0, };
	int Player1[11] = { 0, };	// 21을 넘기 전까지 받을 수 있는 최대 카드 수
	int Player2[11] = { 0, };
	int Player3[11] = { 0, };	// 3인 이상 시에 쓰일 변수
	int Player4[11] = { 0, };
	int ResultD = 0;  // 카드 합
	int Result1 = 0;
	int Result2 = 0;
	int Result3 = 0;	// 3인 이상 시에 쓰일 변수
	int Result4 = 0;

	// 씨앗 심기
	srand((unsigned int)time(NULL));

	cout << "플레이어 수를 입력해주십시오(1~2) : ";
	cin >> n;
	cout << endl;

	// 초기화, 정수 0부터 51까지, *후에 13을 %에 써야하기 때문에 i+1이 아닌 i로 초기화*
	for (i = 0; i < MAX; i++)
	{
		Deck[i] = i;
	}

	// 플레이어 수가 1인 경우
	// AI가 그냥 
	// 2와 비슷하지만, 중간에 AI가 A값을 어떻게 설정할지 결정해야함
	// 2와 다르게 A값을 중간에 판별해야해서 순서를 바꿔야한다.

	if (n == 1)
	{
		// 셔플
		for (i = 0; i < MAX * 5; i++)	// 잘 섞어서 
		{
			Random1 = rand() % MAX;
			Random2 = rand() % MAX;

			t = Deck[Random1];
			Deck[Random1] = Deck[Random2];
			Deck[Random2] = t;
		}

		while (1)
		{
			cout << "초기 카드를 드로우하시려면 D 또는 d를 입력하십시오: ";
			cin >> InitialDraw;

			if (InitialDraw == 'D' || InitialDraw == 'd')
			{
				break;
			}
			else
			{
				cout << "잘못된 입력입니다" << endl;
			}
		}

		cout << endl;

		cout << setw(8) << " ";
		cout << setw(11) << "Dealer";
		cout << setw(11) << "Player1";
		cout << endl;

		// 초기 카드 배분 후 2장 출력


		for (i = 0; i < 2; i = i + 2)	// i를 2씩 증가시켜서 분배
		{
			cout << "Draw " << j0 + 1;

			Dealer[j1] = Deck[i];
			Player1[j2] = Deck[i + 1];

			cout << setw(10) << " ";   // 딜러는 첫번째 카드를 비공개 해둔다
			cout << setw(9) << " ";
			ShowCard(Player1[0]);
			cout << endl;

			j0 = j0 + 1;
			j1 = j1 + 1;
			j2 = j2 + 1;
		}

		for (i = 2; i < 4; i = i + 2)	// i를 2씩 증가시켜서 분배
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

		// 이후에 값이 변경되므로 감춰둔 딜러 카드의 크기를 미리 저장해두었다.
		ANum[0] = Dealer[0];

		// 추가 카드 드로우
		for (i = 4; i < 22; i = i + 2)	// 2씩 증가로 각각 9번 더 가능하도록 설정
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

				if (ResultD <= 16)   // 위에서 +1을 빼고 원값으로 하려고 했지만 2를 빼준 14를 넣었기 때문에
				{					 // 추가 베팅 부터는 원값에서 빠지는 수가 1씩 늘기 때문에 원값으로 해주는게 낫다.
					Dealer[j1] = Deck[i];	// i+1로 겹치지 않고 올라가도록 초기화
					cout << "Draw " << j1 + 1;
					cout << setw(8) << " ";
					ShowCard(Dealer[j1]);
					AddCard1++;
					j1 = j1 + 1;
					cout << endl;
					ResultD = 0;	// 다음 위의 계산에서 이전 ResultD의 값이 들어가지 않도록 초기화
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
				cout << "<Player1>님 추가 Draw 하시겠습니까? (그렇다:Y,y or 아니다:아무키): ";
				cin >> AddChoice;
				if (AddChoice == 'Y' || AddChoice == 'y')
				{
					cout << endl;
					Player1[j2] = Deck[i + 1];	// 첫 시작시 j=2인 상태
					cout << "Draw " << j2 + 1;  // i+1로 겹치지 않고 올라가도록 초기화
					cout << setw(19) << " ";
					ShowCard(Player1[j2]);
					cout << endl;
					AddCard2++;
					j2 = j2 + 1;	// 추가했을 경우 Player1의 패 증가
				}

				else
				{
					cout << endl;
					AddChoice = 0;	// 깔끔하게 Y,y를 0으로 초기화
					AddCard2 = 11;	// 최대값으로 초기화해서 빠져나오도록 설정
				}
			}

			if (AddCard1 == 11 && AddCard2 == 11)
			{
				i = MAX;	// 둘 다 만족시에는 빠져나오도록 초기화, MAX가 의미있어서 초기화
			}
		}

		// 실제 값을 0~12 사이로 맞추고 Arr[0]~[12]까지 0~12로 초기화
		for (i = 0; i < 11; i++)
		{
			Dealer[i] = (Dealer[i] % 13);
			Player1[i] = (Player1[i] % 13);
		}
		// 이후에 0~12의 값으로 초기화 되어있는 상태, 여기까지도 0~12로 초기화해야한다.

		for (i = 0; i < 11; i++)	// 플레이어 카드 최대 11장, 계산을 위해 다듬기
		{
			if (Dealer[i] % 13 > 9)	// Dealer, J,Q,K 전부 9로 초기화 -> 후에 10으로 바꿀 것
			{
				Dealer[i] = 9;
			}

			if (Player1[i] % 13 > 9)	// Player1, J,Q,K 전부 9로 초기화
			{
				Player1[i] = 9;
			}
		}

		for (i = 0; i < j2; i++)	// j1만큼 반복했으므로 j1-1의 배열까지 A가 있는지 검색
		{
			if (Player1[i] % 13 == 0)	// 있을 시 Player1, A 카드 1 or 11 선택
			{
				cout << endl;
				cout << "<Player1>님 A 카드를 1, 11 중에 무엇으로 사용하시겠습니까? ";
				cin >> ACardChoice;

				if (ACardChoice == 11)	// 11을 고를 경우 A를 10으로 초기화 -> 후에 11로 바꿀 것
				{
					Player1[i] = 10;
					ACardChoice = 0;
				}

				cout << endl;
			}
		}

		for (i = 0; i < 11; i++)	// 실제 값을 계산해야하기 때문에 1~10 값으로 초기화.
		{
			Dealer[i] = Dealer[i] + 1;
			Player1[i] = Player1[i] + 1;
		}

		ResultD = 0;	// 올라갔던 변수값 0으로 초기화해서 다시 계산

		for (i = 0; i < j1; i++)
		{
			ResultD += Dealer[i];
		}

		for (i = 0; i < j2; i++)
		{
			Result1 += Player1[i];
		}

		// 딜러 히든 카드 출력
		cout << "Hidden Card: ";
		ShowCard(ANum[0]);
		cout << endl;

		// 딜러, 플레이어 값 출력
		cout << "<Dealer> : " << ResultD;
		if (ResultD > 21)	// 21 초과시 Burst 출력
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

		// 결과 출력
		if (ResultD > 21 && Result1 > 21)	// 둘 다 burst인 경우
		{
			cout << "Burst Draw!!" << endl;
		}

		else if (ResultD == Result1)	// 같은 경우
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

		// 둘 중 하나만 burst, 둘 다 burst가 아닌 경우 중에, 같지 않은 Result1과 Result2의 값의 비교
		else if (ResultD > Result1)
		{
			if (ResultD <= 21)   // ResultD>Result1 인 경우에 ResultD가 버스트가 아니면 Result1도 버스트가 아니다.
			{
				cout << "<Dealer> Winner Winner Chicken Dinner!" << endl;
			}

			else   // ResultD가 burst일 경우 Result1은 burst가 아니다.
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}
		}

		else   // ResultD < Result1 인 경우와 둘 중 하나만 burst, 둘 다 burst가 아닌 경우가 남아있다.
		{
			if (Result1 <= 21)
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}

			else   // Result1이 burst일 경우 Dealer는 burst가 아니다.
			{
				cout << "<Dealer> Winner Winner Chicken Dinner!" << endl;
			}
		}
	}










	// 플레이어 수가 2인 경우
	if (n == 2)
	{
		// 셔플
		for (i = 0; i < MAX * 5; i++)	// 잘 섞어서 
		{
			Random1 = rand() % MAX;
			Random2 = rand() % MAX;

			t = Deck[Random1];
			Deck[Random1] = Deck[Random2];
			Deck[Random2] = t;
		}

		while (1)
		{
			cout << "초기 카드를 드로우하시려면 D 또는 d를 입력하십시오: ";
			cin >> InitialDraw;

			if (InitialDraw == 'D' || InitialDraw == 'd')
			{
				break;
			}
			else
			{
				cout << "잘못된 입력입니다" << endl;
			}
		}

		cout << endl;

		cout << setw(8) << " ";
		cout << setw(11) << "Player1";
		cout << setw(11) << "Player2";
		cout << endl;

		// 초기 카드 배분 후 2장 출력
		for (i = 0; i < 4; i = i + 2)	// i를 2씩 증가시켜서 분배
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

		// 추가 카드 드로우
		for (i = 4; i < 22; i = i + 2)	// 2씩 증가로 각각 9번 더 가능하도록 설정
		{
			if (AddCard1 < 9)
			{
				cout << "<Player1>님 추가 Draw 하시겠습니까? (그렇다:Y,y or 아니다:아무키): ";
				cin >> AddChoice;
				if (AddChoice == 'Y' || AddChoice == 'y')
				{
					cout << endl;
					Player1[j1] = Deck[i];	// 첫 시작시 j=2인 상태
					cout << "Draw " << j1 + 1;
					cout << setw(7) << " ";
					ShowCard(Player1[j1]);
					AddCard1++;
					j1 = j1 + 1;	// 추가했을 경우 Player1의 패 증가
					cout << endl;
				}

				else
				{
					AddChoice = 0;	// 깔끔하게 Y,y를 0으로 초기화
					AddCard1 = 11;	// 최대값으로 초기화해서 빠져나오도록 설정
				}

				cout << endl;
			}

			if (AddCard2 < 9)
			{
				cout << "<Player2>님 추가 Draw 하시겠습니까? (그렇다:Y,y or 아니다:아무키): ";
				cin >> AddChoice;
				if (AddChoice == 'Y' || AddChoice == 'y')
				{
					cout << endl;
					Player2[j2] = Deck[i + 1];	// i+1로 겹치지 않고 올라가도록 초기화
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
				i = MAX;	// 둘 다 만족시에는 빠져나오도록 초기화, MAX가 의미있어서 초기화
			}
		}

		// 실제 값을 0~12 사이로 맞추고 Player[0]~[12]까지 0~12로 초기화
		for (i = 0; i < 11; i++)
		{
			Player1[i] = (Player1[i] % 13);
			Player2[i] = (Player2[i] % 13);
		}
		// 이후에 0~12의 값으로 초기화 되어있는 상태, 여기까지도 0~12로 초기화해야한다.


		for (i = 0; i < 11; i++)	// 플레이어 카드 최대 11장, 계산을 위해 다듬기
		{
			if (Player1[i] % 13 > 9)	// Player1, J,Q,K 전부 9로 초기화 -> 후에 10으로 바꿀 것
			{
				Player1[i] = 9;
			}

			if (Player2[i] % 13 > 9)	// Player2, J,Q,K 전부 9로 초기화
			{
				Player2[i] = 9;
			}
		}

		cout << endl;

		for (i = 0; i < j1; i++)	// j1만큼 반복했으므로 j1-1의 배열까지 A가 있는지 검색
		{
			if (Player1[i] % 13 == 0)	// 있을 시 Player1, A 카드 1 or 11 선택
			{
				cout << "<Player1>님 A 카드를 1, 11 중에 무엇으로 사용하시겠습니까? ";
				cin >> ACardChoice;

				cout << ACardChoice << endl;

				if (ACardChoice == 11)	// 11을 고를 경우 A를 10으로 초기화 -> 후에 11로 바꿀 것
				{
					Player1[i] = 10;
					ACardChoice = 0;
				}

				cout << endl;
			}
		}

		for (i = 0; i < j2; i++)
		{
			if (Player2[i] % 13 == 0)	// Player1, A 카드 1 or 11 선택
			{
				cout << "<Player2>님 A 카드를 1, 11 중에 무엇으로 사용하시겠습니까? ";
				cin >> ACardChoice;

				if (ACardChoice == 11)
				{
					Player2[i] = 10;
					ACardChoice = 0;
				}

				cout << endl;
			}
		}

		for (i = 0; i < 11; i++)	// 실제 값을 계산해야하기 때문에 1~10 값으로 초기화.
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
		if (Result1 > 21)	// 21 초과시 Burst 출력
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

		if (Result1 > 21 && Result2 > 21)	// 둘 다 burst인 경우
		{
			cout << "Burst Draw!!" << endl;
		}

		else if (Result1 == Result2)	// 같은 경우, 받은 카드의 개수로 승패
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

		// 둘 중 하나만 burst, 둘 다 burst가 아닌 경우 중에, 같지 않은 Result1과 Result2의 값의 비교
		else if (Result1 > Result2)
		{
			if (Result1 <= 21)   // Result1>Result2 인 경우에 Result1이 버스트가 아니면 Result2도 버스트가 아니다.
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}

			else   // Result1가 burst일 경우 Result2은 burst가 아니다.
			{
				cout << "<Player2> Winner Winner Chicken Dinner!" << endl;
			}
		}

		else   // Result < Result2 인 경우와 둘 중 하나만 burst, 둘 다 burst가 아닌 경우가 남아있다.
		{
			if (Result2 <= 21)
			{
				cout << "<Player2> Winner Winner Chicken Dinner!" << endl;
			}

			else   // Result2가 burst일 경우 Result1은 burst가 아니다.
			{
				cout << "<Player1> Winner Winner Chicken Dinner!" << endl;
			}
		}
	}

	return 0;
}