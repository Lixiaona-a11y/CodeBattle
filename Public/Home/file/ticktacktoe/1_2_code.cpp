#include<iostream>
#include <fstream>
using namespace std;

//矩阵初始化
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
//打印矩阵
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
//胜负判定
int Result(int arr[3][3])
{
	int i = 0, j = 0;
	int sum = 0;
	int flag = 0;//-1为玩家1获胜，0为平局，-2为玩家2获胜
	//行判定
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
	//列判定
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
	//对角判定
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

//主函数
int main()
{
	void Player1(int arr[3][3]);
	void Player2(int arr[3][3]);
	//文件流
	//ofstream outFile;
	//outFile.open("result.txt");

	int arr[3][3];
	int i = 0, j = 0,round=1;
	Init(arr);//矩阵数组初始化
	//Print_Arr(arr);//打印矩阵
	int flag = 0;//胜负标志位
	int GameOver_flag = GameOver(arr);//平局标志

	//循环
	while (flag==0&&GameOver_flag==0)
	{
		//outFile << "round" << round << ":" << endl;
		Player1(arr);
		flag = Result(arr);
		GameOver_flag = GameOver(arr);
		Print_Arr(arr);
		//Print_Arr_ToFile(arr, outFile);
		//每个选手走了一次就要判断一次
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
		cout << "平局" << endl;
		//outFile << "平局" << endl;
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