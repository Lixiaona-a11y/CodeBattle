#include<iostream>
#include <fstream>
using namespace std;

//�����ʼ��
int Init(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = 0;
			//cout << arr[i][j] << "  ";
		}
		//cout << endl;
	}
	return 0;
}
//��ӡ����
void Print_Arr(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << ",";
		}
		//cout << endl;
	}
	cout << endl;
}
void Print_Arr_ToFile(int arr[3][3],ofstream &output)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			output << arr[i][j] << ",";
		}
	}
	output << endl;
}
//ʤ���ж�
int Result(int arr[3][3])
{
	int i = 0, j = 0;
	int sum = 0;
	int flag = 0;//-1Ϊ���1��ʤ��0Ϊƽ�֣�-2Ϊ���2��ʤ
	//���ж�
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum += arr[i][j];
		}
		if (sum / 3 == -1)
		{
			flag = -1;

		}
		else if (sum / 3 == 1)
		{
			flag = 1;

		}
		sum = 0;
	}
	//���ж�
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 3; i++)
		{
			sum += arr[i][j];
		}
		if (sum / 3 == -1)
		{
			flag = -1;
		}
		else if (sum / 3 == 1)
		{
			flag = 1;
		}
		sum = 0;
	}
	//�Խ��ж�
	for (i = 0, j = 0; i < 3, j < 3; i++, j++)
	{
		sum += arr[i][j];
	}
	if (sum / 3 == -1)
	{
		flag = -1;
	}
	else if (sum / 3 == 1)
	{
		flag = 1;
	}
	sum = 0;
	for (i = 2, j = 0; i >= 0, j < 3; i--, j++)
	{
		sum += arr[i][j];
	}
	if (sum / 3 == -1)
	{
		flag = -1;
	}
	else if (sum / 3 == 1)
	{
		flag = 1;
	}
	sum = 0;


	return flag;
}
int GameOver(int arr[3][3])
{
	int GameOver_flag = 0;
	int zero_count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == 0) zero_count++;
		}
	}
	if (zero_count == 0) GameOver_flag = 1;
	return GameOver_flag;
}

//������
int main()
{
	void Player1(int arr[3][3]);
	void Player2(int arr[3][3]);
	//�ļ���
	//ofstream outFile;
	//outFile.open("result.txt");

	int arr[3][3];
	int i = 0, j = 0,round=1;
	Init(arr);//���������ʼ��
	//Print_Arr(arr);//��ӡ����
	int flag = 0;//ʤ����־λ
	int GameOver_flag = GameOver(arr);//ƽ�ֱ�־

	//ѭ��
	while (flag==0&&GameOver_flag==0)
	{
		//outFile << "round" << round << ":" << endl;
		Player1(arr);
		flag = Result(arr);
		GameOver_flag = GameOver(arr);
		Print_Arr(arr);
		//Print_Arr_ToFile(arr, outFile);
		//ÿ��ѡ������һ�ξ�Ҫ�ж�һ��
		if (GameOver_flag != 0 || flag!=0)
		{
			break;
		}

		Player2(arr);
		flag = Result(arr);
		GameOver_flag = GameOver(arr);
		Print_Arr(arr);
		//Print_Arr_ToFile(arr, outFile);
		round++;
	}
	if (GameOver_flag!=0)
	{
		cout << "ƽ��" << endl;
		//outFile << "ƽ��" << endl;
	}
	else
	{
		cout << "the winner is:" << flag << endl;
		//outFile << "the winner is:" << flag << endl;
	}
	//outFile.close();
	return 0;
}

void Player1(int arr[3][3])
{
	int i=0,j=0;
	while (arr[i][j]!=0)
	{
		j++;
		if (j/3==1)
		{
			j = 0;
			i++;
		}
	}
	arr[i][j] = 1;
}
        void Player2(int arr[3][3])
{
	int i = 0, j = 0;
	while (arr[i][j] != 0)
	{
		j++;
		if (j / 3 == 1)
		{
			j = 0;
			i++;
		}
	}
	arr[i][j] = -1;
}